/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 9      Example: 1      Name: Simple Counter
 * MaxFile name: SimpleCounter
 * Summary:
 *        Shows how to create a simple counter and add its count
 *   to the input stream.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void generateInputData(uint32_t *dataIn, int size)
{
	srand(12345);
	for (int i = 0; i < size; i++)
		dataIn[i] = rand();
}

int check(int size, uint32_t *dataOut, uint32_t *expected) {
	int status = 0;
	for (int i = 0; i < size; i++) {
		if (dataOut[i] != expected[i]) {
			fprintf(stderr, "[%d] Verification error, out: %d != expected: %d\n",
				i, dataOut[i], expected[i]);
			status = 1;
		}
	}
	return status;
}

void SimpleCounterCPU(int size, uint32_t *dataIn, uint32_t *dataOut)
{
	for (int i = 0; i < size; i++)
		dataOut[i] = dataIn[i] + i;
}

int main()
{
	const int size = 1024;
	int sizeBytes = size * sizeof(int32_t);
	uint32_t *dataIn = malloc(sizeBytes);
	uint32_t *dataOut = malloc(sizeBytes);
	uint32_t *expected = malloc(sizeBytes);

	generateInputData(dataIn, size);

	printf("Running DFE.\n");
	SimpleCounter(size, dataIn, dataOut);

	SimpleCounterCPU(size, dataIn, expected);

	int status = check(size, dataOut, expected);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
