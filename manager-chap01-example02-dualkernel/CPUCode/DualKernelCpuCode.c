/**
 * Document: Manager Compiler Tutorial (maxcompiler-manager-tutorial.pdf)
 * Chapter: 1      Example: 2      Name: Dual Kernel
 * MaxFile name: DualKernel
 * Summary:
 *      Send a stream of integers to two kernels where the first has the scalar
 *      input to trigger incrementation and the second does not.
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

void DualKernelCPU(
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
	const int dataSize = 1024;

	size_t sizeBytes = dataSize * sizeof(uint32_t);
	uint32_t *dataIn = malloc(sizeBytes);
	uint32_t *dataOut1 = malloc(sizeBytes);
	uint32_t *dataOut2 = malloc(sizeBytes);
	uint32_t *expected1 = malloc(sizeBytes);
	uint32_t *expected2 = malloc(sizeBytes);

	for (int i = 0; i < dataSize; i++) {
		dataIn[i] = i + 1;
	}

	DualKernelCPU(dataSize, 1, dataIn, expected1);
	DualKernelCPU(dataSize, 0, dataIn, expected2);

	printf("Running DFE.\n");
	DualKernel(dataSize, 1, 0, dataIn, dataIn, dataOut1, dataOut2);

	int status = check(dataSize, 1, dataOut1, expected1);
	status |= check(dataSize, 2, dataOut2, expected2);

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}

