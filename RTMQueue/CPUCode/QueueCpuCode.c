#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

int main(void) {
	const int size = 384;
	int sizeBytes = size * sizeof(uint32_t);
	uint32_t *x = malloc(sizeBytes);
	uint32_t *y = malloc(2 * sizeBytes);
	uint32_t *s = malloc(sizeBytes);
	uint32_t *controller = malloc(2 * sizeBytes);
	int scalar = 3;

	// TODO Generate input data
	for (int i = 0; i < 2 * size; i++) {
		y[i] = i;

	}


	controller[0]=1;
	controller[1]=0;
	for (int i = 2; i < 2*size+2; ++i) {
		if ((i % 2) == 0)
			controller[i] = 1;
		else
			controller[i] = 0;
	}

	for (int i = 0; i < size; ++i) {
		x[i] = i;

	}

	max_file_t *maxfile = Queue_init();
	max_engine_t *engine = max_load(maxfile, "*");

	printf("Writing to LMem.\n");
	max_actions_t* act = max_actions_init(maxfile, "writeLMem");
	max_set_param_uint64t(act, "address", 0);
	max_set_param_uint64t(act, "nbytes", sizeBytes);
	max_queue_input(act, "cpu_to_lmem", x, size * sizeof(uint32_t));
	max_run(engine, act);

	printf("Running on DFE.\n");
	act = max_actions_init(maxfile, "default");
	max_set_param_uint64t(act, "N", size);
	max_set_param_uint64t(act, "A", scalar);
	max_queue_input(act, "y", y, 2*size * sizeof(uint32_t));
	max_queue_input(act, "controller", controller, 2 * size * sizeof(uint32_t));
	max_queue_output(act, "s", s, size * sizeof(uint32_t));
	max_run(engine, act);
	max_unload(engine);

	// TODO Use result data
	for (int i = 0; i < size; ++i)
		printf("\n%d\n", s[i]);

	printf("Done.\n");
	return 0;
}
