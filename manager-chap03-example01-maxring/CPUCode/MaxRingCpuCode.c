/**
 * Document: Manager Compiler Tutorial (maxcompiler-manager-tutorial.pdf)
 * Chapter: 3      Example: 1      Name: MaxRing
 * MaxFile name: MaxRing
 * Summary:
 *     Create an array of two engines. Stream data to and from the right engine and
 *     configure the the muxes and demuxes in each engine so that data sent to the
 *     right engine is also sent through the left engine via maxring.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

int check(int dataSize, uint32_t *expected, uint32_t *oData)
{
	int status = 0;
	for (int i = 0; i < dataSize; i++) {
		if (oData[i] != expected[i]) {
			fprintf(stderr, "[%d] Verification error, out: %u != expected: %u\n",
				i, oData[i], expected[i]);
			status = 1;
		}
	}
	return status;
}

void MaxRingCPU(int dataSize, uint32_t *in, uint32_t *out)
{
	for (int i=0 ; i<dataSize ; i++) {
		out[i] = in[i] + 2;
	}
}

void generateInputData(int dataSize, uint32_t *iData)
{
	for (int i = 0; i < dataSize; i++)
		iData[i] = i;
}

int main()
{
	const int dataSize = 384;
	size_t sizeBytes = dataSize * sizeof(uint32_t);
	uint32_t *iData = malloc(sizeBytes);
	uint32_t *oData = malloc(sizeBytes);
	uint32_t *expected = malloc(sizeBytes);

	generateInputData(dataSize, iData);

	MaxRingCPU(dataSize, iData, expected);

	MaxRing_actions_t *actions[2];
	MaxRing_actions_t interface_actions[2];

	// Right
	interface_actions[0].routing_string
		= "fromcpu -> inputSwitch, bypassSwitch -> tocpu";
	interface_actions[0].instream_fromcpu = iData;
	interface_actions[0].outstream_tocpu = oData;
	interface_actions[0].param_dataSize = dataSize;
	interface_actions[0].ticks_MaxRingKernel = dataSize;
	actions[0] = &interface_actions[0];

	// Left
	interface_actions[1].routing_string
		= "fromMaxRing -> inputSwitch, bypassSwitch -> toKernel";
	interface_actions[1].instream_fromcpu = NULL;
	interface_actions[1].outstream_tocpu = NULL;
	interface_actions[1].param_dataSize = 0;
	interface_actions[1].ticks_MaxRingKernel = dataSize;
	actions[1] = &interface_actions[1];

	printf("Running DFE.\n");
	max_file_t *maxfile = MaxRing_init();
	max_engarray_t *array = max_load_array(maxfile, 2, "*");

	MaxRing_run_array(array, actions);

	max_unload_array(array);
	max_file_free(maxfile);

	int status = check(dataSize, expected, oData);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
