/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 5      Example: 2      Name: Watches
 * MaxFile name: Watches
 * Summary:
 *        Debug watch example.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void WatchesCPU(int size, float *dataIn, float *dataOut) {
	dataOut[0] = (dataIn[0] + dataIn[1]) / 2;
	dataOut[size - 1] = (dataIn[size - 2] + dataIn[size -1]) / 2;
	for (int i = 1; i < size - 1; i++) {
		dataOut[i] = (dataIn[i - 1] + dataIn[i] + dataIn[i + 1]) / 3;
	}
}

int check(int size, float *data_out, float *expected)
{
	int status = 0;
	for (int i = 0; i < size; i++)
		if (data_out[i] != expected[i]) {
			fprintf(stderr, "Output data @ %d = %f (expected %f)\n",
				i, data_out[i], expected[i]);
			status = 1;
		}
	return status;
}

const int size = 8;
float dataIn[8]  = { 1, 5, 6, 7, 2, 0, 1, 11 };
float dataOut[8];
float expected[8];

int main()
{
	printf("Running DFE.\n");
	Watches(size, size, dataIn, dataOut);

	WatchesCPU(size, dataIn, expected);

	int status = check(size, dataOut, expected);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
