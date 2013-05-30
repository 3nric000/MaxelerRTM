/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial)
 * Chapter: 8      Example: 1      Name: Simple offset
 * MaxFile name: SimpleOffset
 * Summary:
 *   Streams floats to the DFE and confirms the stream that comes back has each element added
 *     added to its neighbouring elements.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

int check(int n, float *dataOut, float *expected)
{
	int status = 0;
	for (int i = 1; i < n - 1; i++) // First and last data point are undefined!
	{
		if (dataOut[i] != expected[i]) {
			fprintf(
				stderr, "Output data @ %d = %f (expected %f)\n",
				i, dataOut[i], expected[i]);
			fprintf(stderr, "This is incorrect!\n");
			status = 1;
		}
	}
	return status;
}

void SimpleOffsetCPU(int n, float *dataIn, float *dataOut)
{
	for (int i = 1; i < n - 1; i++) // First and last data point are undefined!
	{
		dataOut[i] = dataIn[i-1] + dataIn[i] + dataIn[i+1];
	}
}

int main()
{
	const int N = 1024;
	size_t sizeBytes = N * sizeof(float);
	float *dataIn = malloc(sizeBytes);
	float *dataOut = malloc(sizeBytes);
	float *expected = malloc(sizeBytes);

	for (int i = 0; i < N; i++) {
		dataIn[i] = i;
		dataOut[i] = 0;
	}

	SimpleOffsetCPU(N, dataIn, expected);

	printf("Running DFE.\n");
	SimpleOffset(N, dataIn, dataOut);

	int status = check(N, dataOut, expected);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
