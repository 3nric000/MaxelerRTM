/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 13      Example: 2      Name: Simple MV 2
 * MaxFile name: SimpleMV2
 * Summary:
 *        Incorrect CPU code for the M Fold kernel design.
 *    This will cause the DFE to stall on output.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void generateInputData(int size, int32_t **dataIn, int32_t **dataOut)
{
	for (int m = 0; m < SimpleMV2_M; m++) {
		dataIn[m]  = malloc(size * sizeof(int32_t));
		dataOut[m] = malloc(size * sizeof(int32_t));
		for (int i = 0; i < size; i++)
			dataIn[m][i] = i;
	}
}

void SimpleMV2CPU(int size, int32_t *dataIn, int32_t *dataOut)
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
	int32_t *dataIn[SimpleMV2_M] , *dataOut[SimpleMV2_M];

	generateInputData(size, dataIn, dataOut);

	printf("Running DFE.\n");
	SimpleMV2(
		size,
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
		sizeBytes - 8000 * sizeof(int32_t));

	int status = 0;
	int32_t *expected = malloc(size * sizeof(int32_t));
	for (int i = 0; i < SimpleMV2_M; i++) {
		SimpleMV2CPU(size, dataIn[i], expected);
		status |= check(size, dataOut[i], expected);
	}

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
