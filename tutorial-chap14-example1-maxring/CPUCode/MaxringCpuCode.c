/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 14      Example: 1      Name: Maxring
 * MaxFile name: Maxring
 * Summary:
 *        Reads a stream of data into one dataflow engine, passes the
 *   data over a MaxRing link to the second DFE and then writes the
 *   data back from the second DFE to the CPU.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

int check(int size, uint32_t *inA, uint32_t *outB)
{
	int status = 0;
	for (int i = 0; i < size; i++) {
		if (outB[i] != inA[i]) {
			fprintf(stderr, "[%d] Verification error, out: %u != expected: %u\n",
				i, outB[i], inA[i]);
			status = 1;
		}
	}
	return status;
}

int main()
{
	const int size = 384;
	const int numEngines = 2;

	int sizeBytes = size * sizeof(uint32_t);
	uint32_t *inA = malloc(sizeBytes);
	uint32_t *outB = malloc(sizeBytes);

	for (int i = 0; i < size; i++)
		inA[i] = i;

	Maxring_actions_t *actions[numEngines];

	for (int i = 0; i < numEngines; i++) {
		int isLeft = (i == 0);
		actions[i] = malloc(sizeof(Maxring_actions_t));
		actions[i]->param_N = size;
		actions[i]->param_isLeft = isLeft ? 1 : 0;
		actions[i]->instream_inA = isLeft ? inA : NULL;
		actions[i]->outstream_outB = isLeft ? NULL : outB;
	}

	printf("Running DFEs.\n");
	max_file_t *maxfile = Maxring_init();
	max_engarray_t *engines = max_load_array(maxfile, numEngines, "*");
	Maxring_run_array(engines, actions);

	int status = check(size, inA, outB);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	max_unload_array(engines);
	max_file_free(maxfile);
	return status;
}
