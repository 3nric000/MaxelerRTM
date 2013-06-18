/*
 * Cpu_simulation file is part of the RTM project
 * This file contains the functions required to steer the execution on the cpu
 * This file contains the optimized RTM algorithm
 * 1st pass - collects receiver data
 * 2nd pass - propagates source forward using a wavefield with random borders
 * 3rd pass - propagates receiver and source backwards and correlates both
 * @author f.pratas
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <omp.h>
#include "cpu_constructors.h"
#include "Maxfiles.h"
#include "MaxSLiCInterface.h"
//--------------------------------------------------------------
// Construct 10th order space stencil
//--------------------------------------------------------------

void construct_stencil() {
	float sm = 0.;
	int i;

	float d = dt;
	c_3[0] = 1.66666666f * d * d / (d3 * d3);
	c_2[0] = 1.66666666f * d * d / (d2 * d2);
	c_1[0] = 1.66666666f * d * d / (d1 * d1);

	c_3[1] = -.23809523f * d * d / (d3 * d3);
	c_2[1] = -.23809523f * d * d / (d2 * d2);
	c_1[1] = -.23809523f * d * d / (d1 * d1);

	c_3[2] = .03968253f * d * d / (d3 * d3);
	c_2[2] = .03968253f * d * d / (d2 * d2);
	c_1[2] = .03968253f * d * d / (d1 * d1);

	c_3[3] = -0.00496031f * d * d / (d3 * d3);
	c_2[3] = -0.00496031f * d * d / (d2 * d2);
	c_1[3] = -0.00496031f * d * d / (d1 * d1);

	c_3[4] = 0.00031746f * d * d / (d3 * d3);
	c_2[4] = 0.00031746f * d * d / (d2 * d2);
	c_1[4] = 0.00031746f * d * d / (d1 * d1);

	for (i = 0; i < 5; i++) {
		sm += c_1[i] + c_2[i] + c_3[i];
	}
	c_0 = -2.0f * sm; //Zero lag stencil

#ifdef DEBUG
	fprintf(stderr,"FINISHED CONSTRUCTING STENCIL\n");
#endif

	return;
}
//--------------------------------------------------------------
// Propagation
//--------------------------------------------------------------
/*
 * do_step - propagate wavefield one step in time
 * p  - current wavefield
 * pp - previous and next wavefield
 * dvv - density (1) * velocity *velocity
 */
void do_step_damping(float *__restrict p, float *__restrict pp,
		float *__restrict dvv, float *__restrict source_container) {
	int i3;
	int n12 = n1 * n2;

	// #pragma omp parallel for
	for (i3 = ORDER; i3 < n3 - ORDER; i3++) { //Loop over slowest axis
		int i1;
		int i2;
		float f1;//Distance from the boundary
		float f2;
		float f3;

		if (i3 < SPONGE_WIDTH)
			f3 = SPONGE_WIDTH - i3; //Inside neg boundary
		else if (i3 >= n3 - SPONGE_WIDTH)
			f3 = i3 - (n3 - SPONGE_WIDTH) + 1; //Inside pos boundary
		else
			f3 = 0; // Not in boundary region
		f3 = f3 * f3; //Distance in boundary

		for (i2 = ORDER; i2 < n2 - ORDER; i2++) { //Loop over middle axis
			if (i2 < SPONGE_WIDTH)
				f2 = SPONGE_WIDTH - i2; // Inside neg boundary
			else if (i2 >= n2 - SPONGE_WIDTH)
				f2 = i2 - (n2 - SPONGE_WIDTH) + 1; //Inside pos boundary
			else
				f2 = 0; //Not in boundary
			f2 = f2 * f2; //Distance in boundary

			for (i1 = ORDER; i1 < n1 - ORDER; i1++) { //Loop over fast axis
				int is;
				float scale;

				if (i1 < BOUND_T)
					f1 = (BOUND_T - i1); //Inside neg boundary
				else if (i1 >= n1 - SPONGE_WIDTH)
					f1 = (i1 - (n1 - SPONGE_WIDTH) + 1);//Inside pos bound
				else
					f1 = 0; // Not in boundary
				f1 = f1 * f1; //Distance in boundary

				is = (int) (sqrtf(f1 + f2 + f3)); //Distance from edge
				if (is > SPONGE_WIDTH)
					is = SPONGE_WIDTH; //Don't go outside computed boundary region

				if (is > 0)
					scale = bound_e[SPONGE_WIDTH - is]; //get scale parameter
				else
					scale = 1;

				pp[i1 + i2 * n1 + i3 * n12] *= scale; // sponge previous wavefield

				//Wavefield update
				pp[i1 + i2 * n1 + i3 * n12] = (2.0 * p[i1 + i2 * n1 + i3 * n12]
						- pp[i1 + i2 * n1 + i3 * n12] + dvv[i1 + i2 * n1 + i3
						* n12] * (p[i1 + i2 * n1 + i3 * n12] * c_0 + c_1[0]
						* (p[(i1 + 1) + (i2) * n1 + (i3) * n12] + p[(i1 - 1)
								+ (i2) * n1 + (i3) * n12]) + c_1[1] * (p[(i1
						+ 2) + (i2) * n1 + (i3) * n12] + p[(i1 - 2) + (i2) * n1
						+ (i3) * n12]) + c_1[2] * (p[(i1 + 3) + (i2) * n1
						+ (i3) * n12] + p[(i1 - 3) + (i2) * n1 + (i3) * n12])
						+ c_1[3] * (p[(i1 + 4) + (i2) * n1 + (i3) * n12]
								+ p[(i1 - 4) + (i2) * n1 + (i3) * n12])
						+ c_1[4] * (p[(i1 + 5) + (i2) * n1 + (i3) * n12]
								+ p[(i1 - 5) + (i2) * n1 + (i3) * n12])
						+ c_2[0] * (p[(i1) + (i2 + 1) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 1) * n1 + (i3) * n12])
						+ c_2[1] * (p[(i1) + (i2 + 2) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 2) * n1 + (i3) * n12])
						+ c_2[2] * (p[(i1) + (i2 + 3) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 3) * n1 + (i3) * n12])
						+ c_2[3] * (p[(i1) + (i2 + 4) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 4) * n1 + (i3) * n12])
						+ c_2[4] * (p[(i1) + (i2 + 5) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 5) * n1 + (i3) * n12])
						+ c_3[0] * (p[(i1) + (i2) * n1 + (i3 + 1) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 1) * n12])
						+ c_3[1] * (p[(i1) + (i2) * n1 + (i3 + 2) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 2) * n12])
						+ c_3[2] * (p[(i1) + (i2) * n1 + (i3 + 3) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 3) * n12])
						+ c_3[3] * (p[(i1) + (i2) * n1 + (i3 + 4) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 4) * n12])
						+ c_3[4] * (p[(i1) + (i2) * n1 + (i3 + 5) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 5) * n12])))
						+ source_container[i1 + i2 * n1 + i3 * n12];
				pp[i1 + i2 * n1 + i3 * n12] *= scale; // sponge result
			}
		}
	}
	return;
}
void do_step(float *__restrict p, float *__restrict pp, float *__restrict dvv,
		float *__restrict source_container) {

	int i3, i2, i1;
	int n12 = n1 * n2;
	int const size = n1 * n2 * n3;
	float *px;
	float *py;
	float *pcopy;
	float *tmp;
	float *ppresult, *ppresult1;
	int const stencilSize = 11;
	int sizeBytes = size * sizeof(float);
	int sizepxy = size * stencilSize * sizeof(float);

	uint32_t *controller = malloc(size * stencilSize * sizeof(uint32_t));
	ppresult = malloc(sizeBytes);
	px = malloc(sizepxy);
	py = malloc(sizepxy);
	ppresult1 = malloc(sizeBytes);
	//pcopy = malloc(sizeBytes);
	//memcpy(pcopy, p, size);


	for (i3 = ORDER; i3 < n3 - ORDER; i3++) { //Loop over slowest axis
		for (i2 = ORDER; i2 < n2 - ORDER; i2++) { //Loop over middle axis
			for (i1 = ORDER; i1 < n1 - ORDER; i1++) { //Loop over fast axis
				//Wavefield update
				ppresult1[i1 + i2 * n1 + i3 * n12] = (2.0 * p[i1 + i2 * n1 + i3
						* n12] - pp[i1 + i2 * n1 + i3 * n12] + dvv[i1 + i2 * n1
						+ i3 * n12] * (p[i1 + i2 * n1 + i3 * n12] * c_0
						+ c_1[0] * (p[(i1 + 1) + (i2) * n1 + (i3) * n12]
								+ p[(i1 - 1) + (i2) * n1 + (i3) * n12])
						+ c_1[1] * (p[(i1 + 2) + (i2) * n1 + (i3) * n12]
								+ p[(i1 - 2) + (i2) * n1 + (i3) * n12])
						+ c_1[2] * (p[(i1 + 3) + (i2) * n1 + (i3) * n12]
								+ p[(i1 - 3) + (i2) * n1 + (i3) * n12])
						+ c_1[3] * (p[(i1 + 4) + (i2) * n1 + (i3) * n12]
								+ p[(i1 - 4) + (i2) * n1 + (i3) * n12])
						+ c_1[4] * (p[(i1 + 5) + (i2) * n1 + (i3) * n12]
								+ p[(i1 - 5) + (i2) * n1 + (i3) * n12])
						+ c_2[0] * (p[(i1) + (i2 + 1) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 1) * n1 + (i3) * n12])
						+ c_2[1] * (p[(i1) + (i2 + 2) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 2) * n1 + (i3) * n12])
						+ c_2[2] * (p[(i1) + (i2 + 3) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 3) * n1 + (i3) * n12])
						+ c_2[3] * (p[(i1) + (i2 + 4) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 4) * n1 + (i3) * n12])
						+ c_2[4] * (p[(i1) + (i2 + 5) * n1 + (i3) * n12]
								+ p[(i1) + (i2 - 5) * n1 + (i3) * n12])
						+ c_3[0] * (p[(i1) + (i2) * n1 + (i3 + 1) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 1) * n12])
						+ c_3[1] * (p[(i1) + (i2) * n1 + (i3 + 2) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 2) * n12])
						+ c_3[2] * (p[(i1) + (i2) * n1 + (i3 + 3) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 3) * n12])
						+ c_3[3] * (p[(i1) + (i2) * n1 + (i3 + 4) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 4) * n12])
						+ c_3[4] * (p[(i1) + (i2) * n1 + (i3 + 5) * n12]
								+ p[(i1) + (i2) * n1 + (i3 - 5) * n12])))
						+ source_container[i1 + i2 * n1 + i3 * n12];
			}
		}
	}

	int index = 0;

	for (index = 0; index < size * stencilSize; index++) {
		px[index] = 0;
		py[index] = 0;
		controller[index] = 0;
	}
/* VECCHIO CONTROLLER
	for (index = 10; index < size * stencilSize; index += 11) {
		controller[index] = 1;
	}
*/

	for (index = 0; index < size * stencilSize; index += 11) {
                controller[index] = 1;
        }


	index = 0;

	for (i3 = ORDER; i3 < n3 - ORDER; i3++) { //Loop over slowest axis
		/*int i1;
		 int i2;*/
		for (i2 = ORDER; i2 < n2 - ORDER; i2++) { //Loop over middle axis
			for (i1 = ORDER; i1 < n1 - ORDER; i1++, index++) {

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 10] = p[(i1)
						+ (i2) * n1 + (i3 - 5) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 10] = p[(i1)
						+ (i2 - 5) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 9] = p[(i1)
						+ (i2) * n1 + (i3 - 4) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 9] = p[(i1)
						+ (i2 - 4) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 8] = p[(i1)
						+ (i2) * n1 + (i3 - 3) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 8] = p[(i1)
						+ (i2 - 3) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 7] = p[(i1)
						+ (i2) * n1 + (i3 - 2) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 7] = p[(i1)
						+ (i2 - 2) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 6] = p[(i1)
						+ (i2) * n1 + (i3 - 1) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 6] = p[(i1)
						+ (i2 - 1) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 5] = p[(i1)
                                                + (i2) * n1 + (i3) * n12];
                                py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 5] = p[(i1)
                                                + (i2) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 4] = p[(i1)
						+ (i2) * n1 + (i3 + 1) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 4] = p[(i1)
						+ (i2 + 1) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 3] = p[(i1)
						+ (i2) * n1 + (i3 + 2) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 3] = p[(i1)
						+ (i2 + 2) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 2] = p[(i1)
						+ (i2) * n1 + (i3 + 3) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 2] = p[(i1)
						+ (i2 + 3) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 1] = p[(i1)
						+ (i2) * n1 + (i3 + 4) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize - 1] = p[(i1)
						+ (i2 + 4) * n1 + (i3) * n12];

				px[((i1) + (i2) * n1 + (i3) * n12) * stencilSize] = p[(i1)
						+ (i2) * n1 + (i3 + 5) * n12];
				py[((i1) + (i2) * n1 + (i3) * n12) * stencilSize] = p[(i1)
						+ (i2 + 5) * n1 + (i3) * n12];
			}
		}
	}

	max_file_t *maxfile = CpuMain_init();
	max_engine_t *engine = max_load(maxfile, "*");
	printf("loading values\n");
	max_actions_t* act = max_actions_init(maxfile, "default");

	max_queue_input(act, "p", p, size * sizeof(float));
	max_queue_input(act, "pp", pp, size * sizeof(float));
	max_queue_input(act, "dvv", dvv, size * sizeof(float));
	max_queue_input(act, "source_container", source_container, size
			* sizeof(float));
	max_queue_input(act, "px", px, size * stencilSize * sizeof(float));
	max_queue_input(act, "py", py, size * stencilSize * sizeof(float));
	max_queue_input(act, "controller", controller, size * stencilSize
			* sizeof(uint32_t));
	max_queue_output(act, "ppresult", ppresult, size * sizeof(float));

	max_set_param_double(act, "c_1_0", (double) c_1[0]);
	max_set_param_double(act, "c_1_1", (double) c_1[1]);
	max_set_param_double(act, "c_1_2", (double) c_1[2]);
	max_set_param_double(act, "c_1_3", (double) c_1[3]);
	max_set_param_double(act, "c_1_4", (double) c_1[4]);

	max_set_param_double(act, "c_2_0", (double) c_2[0]);
	max_set_param_double(act, "c_2_1", (double) c_2[1]);
	max_set_param_double(act, "c_2_2", (double) c_2[2]);
	max_set_param_double(act, "c_2_3", (double) c_2[3]);
	max_set_param_double(act, "c_2_4", (double) c_2[4]);

	max_set_param_double(act, "c_3_0", (double) c_3[0]);
	max_set_param_double(act, "c_3_1", (double) c_3[1]);
	max_set_param_double(act, "c_3_2", (double) c_3[2]);
	max_set_param_double(act, "c_3_3", (double) c_3[3]);
	max_set_param_double(act, "c_3_4", (double) c_3[4]);

	max_set_param_uint64t(act, "size", size);
	max_set_param_uint64t(act, "stencilSize", stencilSize);
	max_set_param_uint64t(act, "sizeController", stencilSize * size);
	max_set_param_double(act, "c_0", (double) c_0);

	printf("running DFE\n");
	max_run(engine, act);
	max_unload(engine);
	printf("unload DFE\n");

	free(px);
	free(py);
	free(controller);
	//free(pcopy);
	/*tmp = pp;

	 free(tmp);*/

	int check = 1;
	for (i3 = ORDER; i3 < n3 - ORDER; i3++) { //Loop over slowest axis
		for (i2 = ORDER; i2 < n2 - ORDER; i2++) { //Loop over middle axis
			for (i1 = ORDER; i1 < n1 - ORDER; i1++) {
				if(ppresult1[i1 + i2 * n1 + i3 * n12]!=ppresult[i1 + i2 * n1 + i3 * n12]){
					check=0;
					printf("ppresult1=%.100f, ppresult=%.100f, i3=%d, i2=%d, i1=%d\n", ppresult1[i1 + i2 * n1 + i3 * n12],  ppresult[i1 + i2 * n1 + i3 * n12], i3, i2, i1);
				}
			}
		}
	}

	printf("check=%d\n", check);

	memcpy(pp, ppresult1, sizeBytes);
	free(ppresult);
	//free(ppresult1);
}
/*
 * add_source - add source to wavefield
 * it - current time sample
 * p - current wavefield
 */
void add_source(int it, float *__restrict source_container) {
	int i1, i2, i3;
	float x1, x2, x3;
	float x, xx;
	float val, tdelay;

	tdelay = 1. / fpeak;
	float t = (float) it * dt;
	if (t > 2. * tdelay) {
		clean_source();
	} else {
		x = 3.1415926536 * fpeak * (t - tdelay);
		xx = x * x;
		val = expf(-xx) * (1.0 - 2.0 * xx); //Wavelet time

		//Add source term over a region
		for (i3 = isy - 1; i3 <= isy + 1; i3++) {
			x3 = isy - i3;
			for (i2 = isx - 1; i2 <= isx + 1; i2++) {
				x2 = isx - i2;
				for (i1 = isz - 1; i1 <= isz + 1; i1++) {
					x1 = isz - i1;
					source_container[i1 + i2 * n1 + i3 * n1 * n2] = -val
							* expf(-x1 * x1 - x2 * x2 - x3 * x3);
				}
			}
		}
	}
	return;
}
/*
 * extract_data - extract data from forward propagation in this case everywhere on the surface
 * it - current time sample
 * p  - current wavefield
 */
void extract_data(int ifr, float *__restrict p,
		float *__restrict frames_container) {
	int i2, i3;

	// #pragma omp parallel for default(shared) private(i3,i2)
	for (i3 = 0; i3 < n3; i3++) {
		for (i2 = 0; i2 < n2; i2++) {
			frames_container[i2 + i3 * n2 + ifr * n2 * n3] = p[isz + i2 * n1
					+ i3 * n1 * n2];
		}
	}
}
/*
 * prop_source - propagation source wavefield
 * model - whether or not I am modeling data or propagating source wavefield
 */
void prop_source(int model) {
	int it;
	long long i;
	float *p1, *p2, *p_aux;

#ifdef DEBUG
	FILE *fd;
	char output[64];
	strcpy(output,folder_path);
	if(model) {
		strcat(output,"/rec_prop.out");
		//saving receiver
		create_header_file(output);

		fd = fopen(output,"w+");
		if(fd == NULL) {
			fprintf(stderr,"Error: couldn't open rec_prop.out\n");
			exit(-1);
		}
	} else {
		strcat(output,"/src_prop.out");
		//saving source
		create_header_file(output);

		fd = fopen(output,"w+");
		if(fd == NULL) {
			fprintf(stderr,"Error: couldn't open src_prop.out\n");
			exit(-1);
		}
	}
#endif

	if (model) {
		p1 = pon_g;
		p2 = pc_g;
	} else {
		p1 = pon_s;
		p2 = pc_s;
	}

	//Loop over time
	for (it = 0; it < nt; it++) {
		add_source(it, source);
		if (model) {
			//use the damping field to get the receiver data
			do_step_damping(p2, p1, vel_g, source);
			if (it % jt == 0)
				extract_data((int) (it / jt), p1, data);
		} else {
			//use the random field to propagate the source forward without losing energy
			do_step(p2, p1, vel_s, source);
		}

#ifdef DEBUG
		if(it%jt==0) fwrite(&(p1[isy*n2*n1]), sizeof(float), n1*n2, fd);
		//Print progress
		switch(it%100) {
			case 0: fprintf(stderr," Propagating  Forward %5d of %5d |\r",it,nt);break;
			case 25: fprintf(stderr," Propagating  Forward %5d of %5d /\r",it,nt);break;
			case 50: fprintf(stderr," Propagating  Forward %5d of %5d -\r",it,nt);break;
			case 75: fprintf(stderr," Propagating  Forward %5d of %5d \\\r",it,nt);
		}
#endif
		p_aux = p1;
		p1 = p2;
		p2 = p_aux; //Flip pointers
	}
	if ((nt % 2) == 1) { //Make sure pointers are consistent for backward propagation
		if (model) {
			p_aux = pon_g;
			pon_g = pc_g;
			pc_g = p_aux;
		} //Flip pointers
		else {
			p_aux = pon_s;
			pon_s = pc_s;
			pc_s = p_aux;
		} //Flip pointers
	}
#ifdef DEBUG
	fprintf(stderr," Propagating  Forward %5d of %5d X\n",it,nt);
	fclose(fd);
#endif
	return;
}
//--------------------------------------------------------------
// Take time derivative of data and mute out direct arrival
//--------------------------------------------------------------
void differentiate_mute_data(char *file) {
	int i3;
	int wavelet_samp;
	wavelet_samp = (2 / (fpeak * dt)) / jt;

	float vel = sqrt(vel_g[isz + isx * n1 + isy * n1 * n2]);

#ifdef DEBUG
	FILE *fd;
	char output[64];
	strcpy(output,folder_path);
	strcat(output,"/rec_data_or.out");
	//receiver data with source
	create_header_file(output);
	fd = fopen(output,"w+");
	if(fd == NULL) {
		fprintf(stderr,"Error: couldn't open rec_data_or.out\n");
		exit(-1);
	}
	fwrite(data, sizeof(float), nf*n3*n2, fd);
	fclose(fd);
	strcpy(output,folder_path);
	strcat(output,"/rec_data.out");
	//receiver data without source
	create_header_file(output);
	fd = fopen(output,"w+");
	if(fd == NULL) {
		fprintf(stderr,"Error: couldn't open rec_data.out\n");
		exit(-1);
	}
#endif

	// #pragma omp parallel for
	for (i3 = 0; i3 < n3; i3++) {
		int i2;
		int ifr;
		for (i2 = 0; i2 < n2; i2++) {
			//Distance away from source
			float dist = sqrt((isx - i2) * (isx - i2) * d2 * d2 + d3 * d3
					* (isy - i3) * (isy - i3));
			int mute_s = ((dist / vel) / (dt * jt)); //Mute frames
			mute_s += wavelet_samp; //remove whole source (the source is injected during number of steps = 2/(fpeak*dt))
			for (ifr = 0; (ifr < mute_s) && (ifr < nf); ifr++)
				data[i2 + i3 * n2 + ifr * n2 * n3] = 0; //Mute direct arrive
		}
	}

	save_receiver_to_file(file);

#ifdef DEBUG
	fwrite(data, sizeof(float), nf*n3*n2, fd);
	fclose(fd);
#endif

	return;
}
//--------------------------------------------------------------
// Migrate a shot
//--------------------------------------------------------------
/*
 * image_it  - Apply imaging condition
 * p1 - source wavefield
 * p2 - receiver wavefield
 */
void image_it(float *__restrict source_container, float *__restrict receiver,
		float **__restrict image_container) {
	int k;

	//2D gather
	// #pragma omp parallel for
	for (k = 0; k < n3; k++) {
		int j;
		int i;
		int sub;
		for (sub = 0; sub <= num_subsurface_offsets; sub++) {
			for (j = sub; j < n2 - sub; j++) {
				for (i = 0; i < n1; i++) {
					image_container[sub][i + j * n1 + k * n1 * n2]
							+= source_container[i + (j - sub) * n1 + k * n1
									* n2] * receiver[i + (j + sub) * n1 + k
									* n1 * n2];
				}
			}
		}
	}
	return;
}
/*
 * add_data - add data to propagation grid
 * it - current time step
 * p - current wavefield
 */
void add_data(int it, float *__restrict source_container,
		float *__restrict frames_container) {
	int i2, i3;
	int ib = it / jt; //Linear interpolation
	int ie = ib + 1;
	float f = (float) (it - ib * jt) / (float) (jt);
	if (ie >= nf) {
		ie = nf - 1;
		f = 1.;
	}
	int n12 = n1 * n2;

	// #pragma omp parallel for
	for (i3 = 0; i3 < n3; i3++) {
		int i2;
		for (i2 = 0; i2 < n2; i2++) {
			source_container[isz + i2 * n1 + i3 * n12] = (1. - f)
					* frames_container[i2 + i3 * n2 + ib * n2 * n3] + f
					* frames_container[i2 + i3 * n2 + ie * n2 * n3];
		}
	}
	return;
}
/*
 * migrate_shot - Migrate a single shot
 */
void migrate_shot() {
	int it;
	float *p1s, *p1g, *p_aux, *p2s, *p2g;
	p1s = pon_s;
	p2s = pc_s;
	p1g = pon_g;
	p2g = pc_g;

#ifdef DEBUG
	FILE *fd1,*fd2;
	char output[64];
	strcpy(output,folder_path);
	strcat(output,"/rec_bprop.out");
	create_header_file(output);
	fd1 = fopen(output,"w+");
	if(fd1 == NULL) {
		fprintf(stderr,"Error: couldn't open rec_bprop.out\n");
		exit(-1);
	}
	strcpy(output,folder_path);
	strcat(output,"/src_bprop.out");
	create_header_file(output);
	fd2 = fopen(output,"w+");
	if(fd2 == NULL) {
		fprintf(stderr,"Error: couldn't open src_bprop.out\n");
		exit(-1);
	}
#endif

	//Should loop from max time to 0
	for (it = nt - 1; it >= 0; it--) {

#ifdef DEBUG
		//Print progress
		switch(it%100) {
			case 0: fprintf(stderr," Propagating Backward %5d of %5d |\r",it,nt);break;
			case 25: fprintf(stderr," Propagating Backward %5d of %5d /\r",it,nt);break;
			case 50: fprintf(stderr," Propagating Backward %5d of %5d -\r",it,nt);break;
			case 75: fprintf(stderr," Propagating Backward %5d of %5d \\\r",it,nt);
		}
#endif

		clean_source();
		do_step(p1s, p2s, vel_s, source); //Backward prop source
		add_data(it, source, data); //Inject recorded data
		do_step_damping(p1g, p2g, vel_g, source); //Backward prop receiver
		if (it % jt == 0)
			image_it(p2s, p2g, image); //Apply imaging condition
#ifdef DEBUG
		if(it%jt==0) fwrite(&(p2g[(n3/2)*n2*n1]), sizeof(float), n1*n2, fd1);
		if(it%jt==0) fwrite(&(p2s[(n3/2)*n2*n1]), sizeof(float), n1*n2, fd2);
#endif
		p_aux = p1s;
		p1s = p2s;
		p2s = p_aux; //Flip source pointers
		p_aux = p1g;
		p1g = p2g;
		p2g = p_aux; //Flip receiver pointers
	}

#ifdef DEBUG
	fprintf(stderr," Propagating Backward %5d of %5d X\n",0,nt);
	fclose(fd1);
	fclose(fd2);
#endif
	return;
}
