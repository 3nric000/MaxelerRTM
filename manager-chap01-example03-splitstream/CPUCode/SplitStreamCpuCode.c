/**
 * Document: Manager Compiler Tutorial (maxcompiler-manager-tutorial.pdf)
 * Chapter: 1      Example: 3      Name: Split Stream
 * MaxFile name: SplitStream
 * Summary:
 *     Stream data into port x1 which will go though kernel k1 and read
 *     the stream back from y1. Then stream data into port x2 which will
 *     go though kernel k2 and read the stream back from y2.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

int check(int dataSize, int kernelNumber, uint32_t *dataOut, uint32_t *expectedOut)
{
	int status = 0;
	for (int i = 0; i < dataSize; i++) {
		if (dataOut[i] != expectedOut[i]) {
			fprintf(stderr, "Output data from Kernel %d @ %d = %d (expected %d)\n",
				kernelNumber, i, dataOut[i], expectedOut[i]);
			status = 1;
		}
	}
	return status;
}

void SplitStreamCPU(
	int dataSize,
	int add,
	uint32_t *dataIn,
	uint32_t *dataOut)
{
	for (int i = 0; i < dataSize; i++) {
		dataOut[i] = dataIn[i] + add;
	}
}

int main()
{
	int const dataSize= 1024;

	size_t sizeBytes = dataSize* sizeof(uint32_t);
	uint32_t *dataIn = malloc(sizeBytes);
	uint32_t *dataOut1 = malloc(sizeBytes);
	uint32_t *dataOut2 = malloc(sizeBytes);
	uint32_t *expected1 = malloc(sizeBytes);
	uint32_t *expected2 = malloc(sizeBytes);

	for (int i = 0; i < dataSize; i++) {
		dataIn[i] = i + 1;
		dataOut1[i] = 0;
		dataOut2[i] = 0;
	}

	SplitStreamCPU(dataSize, 1, dataIn, expected1);
	SplitStreamCPU(dataSize, 0, dataIn, expected2);

	printf("Running DFE.\n");
	SplitStream(dataSize, 1, 0, dataIn, dataOut1, "x1 -> split, y1 -> join");

	SplitStream(dataSize, 1, 0, dataIn, dataOut2, "x2 -> split, y2 -> join");

	int status = check(dataSize, 1, dataOut1, expected1);
	status |= check(dataSize, 2, dataOut2, expected2);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
