/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 9       Example: 2      Name: Simple two-dimensional counter
 * MaxFile Name: Simple2DCounter
 * Summary:
 *        Shows how to construct a chained counter and output its
 *   values every cycle.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

const int maxI = Simple2DCounter_maxI;
const int maxJ = Simple2DCounter_maxJ;
const int iterations = 4;

void generateInputData(int length, uint32_t *passthroughIn)
{
	for (int x = 0; x < length; x++)
		passthroughIn[x] = x;
}

void Simple2DCounterCPU(
	int length,
	uint32_t *passthroughIn,
	uint32_t *countiExpected,
	uint32_t *countjExpected,
	uint32_t *passthroughExpected)
{
	for (int x = 0; x < length; x++)
		passthroughExpected[x] = passthroughIn[x];

	for (int x = 0; x < iterations; x++)
		for (int i = 0; i < maxI; i += 2)
			for (int j = 0; j < maxJ; j++) {
				int index = (maxI / 2) * maxJ * x + (i / 2) * maxJ + j;
				countiExpected[index] = i;
				countjExpected[index] = j;
			}
}

int check(
	int length,
	unsigned int *countiOut,
	unsigned int *countjOut,
	unsigned int *passthroughOut,
	unsigned int *countiExpected,
	unsigned int *countjExpected,
	unsigned int *passthroughExpected)
{
	int status = 0;
	for (int x = 0; x < length; x++) {
		if (passthroughOut[x] != passthroughExpected[x]) {
			fprintf(stderr,	"[%d] Passthrough error, in: %d != out: %d\n",
				x,	passthroughExpected[x], passthroughOut[x]);
			status = 1;
		}
		if (countiOut[x] != countiExpected[x]) {
			fprintf(stderr, "[%d] Count i error, expected: %d != received: %d\n",
				x, countiExpected[x], 	countiOut[x]);
			status = 1;
		}

		if (countjOut[x] != countjExpected[x]) {
			fprintf(stderr, "[%d] Count j error, expected: %d != received: %d\n",
				x, countjExpected[x], countjOut[x]);
			status = 1;
		}
	}
	return status;
}

int main()
{
	const int length = (maxI / 2) * maxJ * iterations;
	int sizeBytes = length * sizeof(uint32_t);
	uint32_t *passthroughIn = malloc(sizeBytes);
	uint32_t *passthroughOut = malloc(sizeBytes);
	uint32_t *passthroughExpected = malloc(sizeBytes);
	uint32_t *countiOut = malloc(sizeBytes);
	uint32_t *countjOut = malloc(sizeBytes);
	uint32_t *countiExpected = malloc(sizeBytes);
	uint32_t *countjExpected = malloc(sizeBytes);

	generateInputData(length, passthroughIn);

	printf("Running DFE.\n");
	Simple2DCounter(length, passthroughIn, countiOut, countjOut, passthroughOut);

	Simple2DCounterCPU(
		length,
		passthroughIn,
		countiExpected,
		countjExpected,
		passthroughExpected);

	int status = check(
		length,
		countiOut,
		countjOut,
		passthroughOut,
		countiExpected,
		countjExpected,
		passthroughExpected);

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
