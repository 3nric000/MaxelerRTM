/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 11      Example: 2      Name: Counter Controlled Input
 * MaxFile name: CounterControlledInput
 * Summary:
 *      CPU code for a kernel design using a counter controlled input.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void generateInputData(
	int size,
	uint32_t *inA,
	uint32_t *inB)
{
	for (int i = 0; i < size; ++i) {
		inA[i] = (uint32_t) i + 1;
		inB[i] = inA[i] * 1000;
	}
}

void CounterControlledInputCPU(
	int size,
	int readLimit,
	uint32_t *inA,
	uint32_t *inB,
	uint32_t *outY)
{
	for (int i=0; i < size; i++)
		outY[i] = inA[i] + ( i < readLimit ? inB[i] : 0 );
}

int check(int size, uint32_t *outY, uint32_t *expected) {
	int status = 0;
	for (int i = 0; i < size; ++i) {
		if (outY[i] != expected[i]) {
			fprintf(stderr, "ERROR @ %d, expected %u, got %u\n",
				i, expected[i], outY[i]);
			status = 1;
		}
	}
	return status;
}

int main()
{
	const int size = 64;
	int dataSize = size * sizeof(uint32_t);
	uint32_t *inA = malloc(dataSize);
	uint32_t *inB = malloc(dataSize);
	uint32_t *outY = malloc(dataSize);
	uint32_t *expected = malloc(dataSize);

	generateInputData(size, inA, inB);

	printf("Running DFE.\n");
	CounterControlledInput(size, 10, inA, inB, outY);

	CounterControlledInputCPU(size, 10, inA, inB, expected);

	int status = check(size, outY, expected);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
