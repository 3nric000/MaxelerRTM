#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"
int n1;
int n2;

int main(void) {
	int n12 = n1 * n2;
	int offX, offY, offZ;
	//const int size = 384;
	int size = n1 * n2 * n2;
	int const xzSize = 11;
	int const burst = 96;
	int sizeC = 5;
	float *pp_value;
	float *dvv_value;
	float *source_container_value;
	int sizeBytes = size * sizeof(float);

	int sizeCBytes = sizeC * sizeof(float);
	//uint32_t *x = malloc(sizeBytes);
	//uint32_t *y = malloc(sizeBytes);
	//uint32_t *s = malloc(sizeBytes);
	int c_0;

	max_file_t *maxfile = MemStream_init();
	max_engine_t *engine = max_load(maxfile, "*");

	printf("Writing to LMem.\n");
	max_actions_t* act = max_actions_init(maxfile, "writeLMem");
	max_set_param_uint64t(act, "address", 0);
	max_set_param_uint64t(act, "nbytes", sizeBytes);
	printf("Loading p in LMem\n");
	max_queue_input(act, "p", p, size * sizeof(float));

	/*max_set_param_uint64t(act, "address", sizeBytes);
	 max_set_param_uint64t(act, "nbytes", sizeBytes);
	 max_queue_input(act, "pp", pp, size * sizeof(float));

	 max_set_param_uint64t(act, "address", 2 * sizeBytes);
	 max_set_param_uint64t(act, "nbytes", sizeBytes);
	 max_queue_input(act, "dvv", dvv, size * sizeof(float));

	 max_set_param_uint64t(act, "address", 3 * sizeBytes);
	 max_set_param_uint64t(act, "nbytes", sizeCBytes);
	 max_queue_input(act, "c_1", c_1, sizeC * sizeof(float));

	 max_set_param_uint64t(act, "address", 3 * sizeBytes + sizeCBytes);
	 max_set_param_uint64t(act, "nbytes", sizeCBytes);
	 max_queue_input(act, "c_2", c_2, sizeC * sizeof(float));

	 max_set_param_uint64t(act, "address", 3 * sizeBytes + 2 * sizeCBytes);
	 max_set_param_uint64t(act, "nbytes", sizeCBytes);
	 max_queue_input(act, "c_3", c_3, sizeC * sizeof(float));

	 max_set_param_uint64t(act, "address", 3 * sizeBytes + 3 * sizeCBytes);
	 max_set_param_uint64t(act, "nbytes", sizeBytes);
	 max_queue_input(act, "source_container", source_container, size
	 * sizeof(float));*/

	//max_run(engine, act);

	printf("Running on DFE.\n");
	act = max_actions_init(maxfile, "default");

	printf("Loading c_x, n1, n1m, n2, burst, xzSize in LMem");

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

	max_set_param_uint64t(act, "n1", n1);
	max_set_param_uint64t(act, "n1m", n1m);
	max_set_param_uint64t(act, "n2", n2);
	max_set_param_double(act, "c_0", (double) c_0);

	max_set_param_uint64t(act, "burst", burst);

	max_set_param_uint64t(act, "xzSize", xzSize);

	for (offZ = 0; offZ < n3; offZ++) { //Loop over slowest axis
		for (offX = 0; offX < n2; offX++) { //Loop over middle axis
			for (offY = 0; offY < n1m; offY = offY + 8) {

				pp_value = malloc(sizeof(float) * 8);
				dvv_value = malloc(sizeof(float) * 8);
				source_container_value = malloc(sizeof(float) * 8);

				for (int i = 0; i < 8; i++) {
					pp_value[i] = pp[offY + offX * n1 + offZ * n12 + i];
					dvv_value[i] = dvv[offY + offX * n1 + offZ * n12 + i];
					source_container_value[i] = source_container[offY + offX
							* n1 + offZ * n12 + i];
				}
				max_queue_input(act, "pp_value", pp_value, 8 * sizeof(float));
				max_queue_input(act, "dvv_value", dvv_value, 8 * sizeof(float));
				max_queue_input(act, "source_container_value",
						source_container_value, 8 * sizeof(float));

				/*max_set_param_double(act, "pp_value", (double) pp_value);
				 max_set_param_double(act, "dvv_value", (double) dvv_value);
				 max_set_param_double(act, "source_container_value", (double) source_container_value);
				 */
				max_set_param_uint64t(act, "offM", offX);
				max_set_param_uint64t(act, "offF", offY);
				max_set_param_uint64t(act, "offS", offZ);
				max_run(engine, act);

				free(pp_value);
				free(dvv_value);
				free(source_container_value);
			}
		}
	}

	max_actions_t* act = max_actions_init(maxfile, "readLMem");
	max_set_param_uint64t(act, "address", sizeBytes);
	max_set_param_uint64t(act, "nbytes", sizeBytes);
	max_queue_output(act, "pp", pp, size * sizeof(uint32_t));

	max_unload(engine);

}
