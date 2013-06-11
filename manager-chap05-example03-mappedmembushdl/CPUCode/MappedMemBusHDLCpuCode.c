/**
 * Document: Manager Compiler Tutorial (maxcompiler-manager-tutorial.pdf)
 * Chapter: 5
 * Example: 3
 * Name: Mapped Memmory Bus HDL
 * MaxFile name: MappedMemBusHDL
 * Summary:
 *     Tests the read-back of the HDL mapped memories, and generates an
 *     output stream by writing to HDL mapped memory.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>


void MappedMemBusHDLCpu(int size, int testValue, uint32_t *dataOut)
{
	for (int i = 0; i < size; i++) {
		dataOut[i] = testValue;
	}
}

int check(uint32_t *dataOut, uint32_t *expected, int size)
{
	int status = 0;
		for(int i = 1; i < (size-1); i++) {
			if(dataOut[i] != expected[i]) {
				fprintf(stderr, "Output data @ %d = %d (expected %d)\n",
					i, dataOut[i], expected[i]);
				status = 1;
			}
		}

	return status;
}

int main()
{
	const int size = 384;
	const int testValue = 0xdeadbeef;
	const int numMemRead = 8;
	uint32_t *outputData   = malloc(size * sizeof(uint32_t));
	uint32_t *expectedData = malloc(size * sizeof(uint32_t));
	uint64_t *mem = malloc(numMemRead * sizeof(uint64_t));

	max_file_t    *maxfile = MappedMemBusHDL_init();
	max_engine_t  *engine  = max_load(maxfile, "*");
	max_actions_t *actions;

	actions = max_actions_init(maxfile, NULL);
	for (int i = 0; i < numMemRead; i++) {
		max_get_mem_uint64t(actions, "hdl_node_mapped_mem_bus", "example", i, &mem[i]);
	}
	max_run(engine, actions);
	max_actions_free(actions);

	int status = 0;
	for (int i = 0; i < numMemRead; i++) {
		if (mem[i] != (uint64_t) i) {
			fprintf(stderr, "error:  expected %d.\n", i);
			status = 1;
		}
	}

	MappedMemBusHDLCpu(size, testValue, expectedData);

	actions = max_actions_init(maxfile, NULL);
	max_disable_reset(actions);
	max_set_mem_uint64t(actions, "hdl_node_mapped_mem_bus", "example", 1, testValue);
	max_set_mem_uint64t(actions, "hdl_node_mapped_mem_bus", "example", 0, 1);
	max_queue_output(actions, "output", outputData, size * sizeof(uint32_t));
	max_run(engine, actions);
	max_actions_free(actions);

	status = status | check(outputData, expectedData, size);

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	max_unload(engine);
	max_file_free(maxfile);
	free(outputData);
	free(expectedData);

	return status;
}
