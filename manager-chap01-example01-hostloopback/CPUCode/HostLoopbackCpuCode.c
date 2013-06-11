/**
 * Document: Manager Compiler Tutorial (maxcompiler-manager-tutorial.pdf)
 * Chapter: 1      Example: 1      Name: Host loopback
 * MaxFile name: HostLoopback
 * Summary:
 *     Streams integers to the dataflow engine and confirms that in the returned
 *     stream each integer has been incremented.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

int check(int dataSize, uint32_t *dataOut, uint32_t *expectedOut)
{
	int status = 0;
	for (int i = 0; i < dataSize; i++)
		if (dataOut[i] != expectedOut[i]) {
			fprintf(stderr, "Output data @ %d = %d (expected %d)\n",
				i, dataOut[i], expectedOut[i]);
			status = 1;
		}
	return status;
}

void HostLoopbackCPU(int size, uint32_t *dataIn, uint32_t *dataOut)
{
	for (int i=0; i<size; i++) {
		dataOut[i] = dataIn[i] + 1;
	}
}

int main()
{
	const int dataSize =1024;
	size_t sizeBytes = dataSize * sizeof(uint32_t);
	uint32_t *dataIn = malloc(sizeBytes);
	uint32_t *dataOut = malloc(sizeBytes);
	uint32_t *expectedOut = malloc(sizeBytes);

	for (int i = 0; i < dataSize; i++) {
		dataIn[i] = i + 1;
		dataOut[i] = 0;
	}

	HostLoopbackCPU(dataSize, dataIn, expectedOut);

	printf("Running DFE.\n");
	HostLoopback(dataSize, dataIn, dataOut);

	int status = check(dataSize, dataOut, expectedOut);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;

}
