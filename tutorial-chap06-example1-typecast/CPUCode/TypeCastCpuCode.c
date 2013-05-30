/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 6      Example: 1      Name: Typecast
 * MaxFile name: TypeCast
 * Summary:
 *        Casts from an unsigned int to a float and back.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

int check(float *outB, uint8_t *outY, float *expectedB, uint8_t *expectedY, int size)
{
	int status = 0;
	for (int i = 0; i < size; i++) {
		printf("[%d]\tb: %f\ty: %d\n", i, outB[i], outY[i]);

		if (outB[i] != expectedB[i] || outY[i] != expectedY[i]) {
			fprintf(
				stderr, "Error detected, expected b: %f\ty: %d\n",
				expectedB[i], expectedY[i]);
			status = 1;
		}
	}
	return status;
}

void TypeCastCPU(int size, uint8_t *inA, float *inX, float *outB, uint8_t *outY)
{
	for (int i = 0; i < size; i++) {
		outB[i] = (inX[i] + 10.5);
		outY[i] = inA[i] % 256;
	}
}

int main()
{
	const int size = 16;
	int intBytes = size * sizeof(uint8_t);
	int floatBytes = size * sizeof(float);

	// Input data is one stream of floats and another one of 8bit unsigned ints
	uint8_t *inA = malloc(intBytes);
	float *inX = malloc(floatBytes);

	float *outB = malloc(floatBytes);
	uint8_t *outY = malloc(intBytes);

	float *expectB = malloc(floatBytes);
	uint8_t *expectY = malloc(intBytes);

	for (int i = 0; i < size; i++) {
		inA[i] = inX[i] = i;
		outB[i] = outY[i] = 0;
	}

	TypeCastCPU(size, inA, inX, expectB, expectY);

	printf("Running DFE.\n");
	TypeCast(size, inA, inX, outB, outY);

	int status = check(outB, outY, expectB, expectY, size);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
