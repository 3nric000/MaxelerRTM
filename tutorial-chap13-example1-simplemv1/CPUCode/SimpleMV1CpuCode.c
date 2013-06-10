/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 13      Example: 1      Name: Simple MV 1
 * MaxFile name: SimpleMV1
 * Summary:
 *        Incorrect CPU code for the M Fold kernel design.
 *    This will cause the DFE to stall on input.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void generateInputData(int32_t **dataIn, int32_t **dataOut, int size)
{
	for (int m = 0; m < SimpleMV1_M; m++) {
		dataIn[m]  = malloc(size * sizeof(int32_t));
		dataOut[m] = malloc(size * sizeof(int32_t));
		for (int i = 0; i < size; i++)
			dataIn[m][i] = i;
	}
}

void SimpleMV1CPU(int size, int32_t *dataIn, int32_t *dataOut)
{
	for (int i = 0; i < size; i++)
		dataOut[i] = dataIn[i] * dataIn[i] + dataIn[i];
}

int check(int size, int32_t *dataOut, int32_t *expected)
{
	int status = 0;
	for (int i = 0; i < size; i++) {
		if ( dataOut[i] != expected[i] ) {
			fprintf(stderr, " Output data @ %d = %d (expected %d)\n",
				i, dataOut[i], expected[i]);
			status = 1;
		}
	}
	return status;
}

int main()
{
	const int size = 10000;
	int sizeBytes = size * sizeof(int32_t);
	int32_t *dataIn[SimpleMV1_M] , *dataOut[SimpleMV1_M];

	generateInputData(dataIn, dataOut, size);

	printf("Running DFE.\n");
	SimpleMV1(
		size + 5000,
		dataIn[0],
		sizeBytes,
		dataIn[1],
		sizeBytes,
		dataIn[2],
		sizeBytes,
		dataIn[3],
		sizeBytes,
		dataOut[0],
		sizeBytes,
		dataOut[1],
		sizeBytes,
		dataOut[2],
		sizeBytes,
		dataOut[3],
		sizeBytes);

	int status = 0;
	int32_t *expected = malloc(size * sizeof(int32_t));
	for (int i = 0; i < SimpleMV1_M; i++) {
		SimpleMV1CPU(size, dataIn[i], expected);
		status |= check(size, dataOut[i], expected);
	}

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}