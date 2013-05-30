/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial)
 * Chapter: 8      Example: 7      Name: Stream Hold
 * MaxFile name: StreamHold
 * Summary:
 *     Streams random numbers to the DFE and confirms
 *     that the returned stream contains the current
 *     maximum value at each point.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

int check(uint32_t n, uint32_t *dataOut, uint32_t *expected)
{
	int status = 0;
	for (uint32_t i = 0; i < n; i++)
	{
		if (dataOut[i] != expected[i]) {
			fprintf(
				stderr, "Output data @ %d = %d (expected %d)\n",
				i, dataOut[i], expected[i]);
			fprintf(stderr, "This is incorrect!\n");
			status = 1;
		}
	}
	return status;
}

void StreamHoldCPU(uint32_t n, uint64_t holdCount, uint32_t *dataIn, uint32_t *dataOut)
{
	uint32_t counterMax = (1 << StreamHold_counterWidth);
	printf("%d\n",counterMax);

	for (uint32_t i = 0; i < n; i+=counterMax)
	{
		for (uint32_t j = 0; j < (uint32_t) holdCount; j++)
			dataOut[i+j] = dataIn[i+j];
		for (uint32_t j = (uint32_t)holdCount; j < counterMax; j++)
			dataOut[i+j] = dataIn[i+(uint32_t)holdCount-1];
	}
}

int main()
{
	const uint32_t N = 1024;
	size_t sizeBytes = N * sizeof(uint32_t);
	uint32_t *dataIn = malloc(sizeBytes);
	uint32_t *dataOut = malloc(sizeBytes);
	uint32_t *expected = malloc(sizeBytes);

	for (uint32_t i = 0; i < N; i++) {
		dataIn[i] = (uint32_t) rand();
	}

	uint64_t holdCount = 8;

	StreamHoldCPU(N, holdCount, dataIn, expected);

	printf("Running DFE.\n");
	StreamHold(N, holdCount, dataIn, dataOut);

	int status = check(N, dataOut, expected);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
