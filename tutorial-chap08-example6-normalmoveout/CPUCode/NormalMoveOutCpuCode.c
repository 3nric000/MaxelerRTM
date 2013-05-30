/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 8      Example: 6      Name: Normal move-out
 * MaxFile name: NormalMoveOut
 * Summary:
 *    A simple Normal Move-Out application using dynamic offsets.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

void generateInputData(int simLength, int timeUnit, float *inData, float *moveAmts)
{
	// Generate pseudo-random test data
	srand(12345);

	for (int i = 0; i < simLength; i++) {
		inData[i] = ((float) rand() / (float) RAND_MAX) * i;
		moveAmts[i] = (((float) rand() / (float) RAND_MAX) * (simLength - 2))
			- i;
		moveAmts[i] *= timeUnit;
	}
}

int check(int size, float *outData, float *expectedData)
{
	int status = 0;
	for (int i = 1; i < (size -1); i++) // First and last data point are undefined!
	{
		if (fabs((outData[i] - expectedData[i]) / expectedData[i]) > 0.001) {
			fprintf(
				stderr,
				"Output data @ %d = %f (expected %f)\n",
				i,
				outData[i],
				expectedData[i]);
			status = 1;
		}
	}
	return status;
}

void NormalMoveOutCPU(int size, float timeUnit, float *inData, float *moveAmts, float *outData)
{
	for (int i = 0; i < size; i++) {
		float moveInUnits = moveAmts[i] / timeUnit;
		int ptLower = (int) floor(moveInUnits);
		float interp = moveInUnits - (float) ptLower;
		outData[i] = (float) inData[i + ptLower] * interp
			+ (float) inData[i + ptLower + 1] * (1 - interp);
	}
}

int main()
{
	const int simLength = 512;
	const float timeUnit = 4E-3;
	size_t sizeBytes = simLength * sizeof(float);
	float *inData = malloc(sizeBytes);
	float *moveAmts = malloc(sizeBytes);
	float *outData = malloc(sizeBytes);
	float *expectedData = malloc(sizeBytes);
	generateInputData(simLength, timeUnit, inData, moveAmts);

	NormalMoveOutCPU(simLength, timeUnit, inData, moveAmts, expectedData);

	printf("Running DFE.\n");
	NormalMoveOut(simLength, timeUnit, inData, moveAmts, outData);

	int status = check(simLength, outData, expectedData);

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
