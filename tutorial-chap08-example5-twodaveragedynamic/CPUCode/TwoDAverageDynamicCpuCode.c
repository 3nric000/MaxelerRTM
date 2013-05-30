/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 8      Example: 5      Name: Two-dimensional average dynamic
 * MaxFile name: TwoDAverageDynamic
 * Summary:
 *       Averages within an 8-point window.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

void generateInputData(float *dataIn, float *expectedOut, int nx, int ny)
{
	for (int i = 0; i < nx * ny; i++) {
		dataIn[i] = 0;
		expectedOut[i] = 0;
	}
	dataIn[nx * (ny / 2) + nx / 2] = 9;
	for (int x = -1; x <= 1; x++)
		for (int y = -1; y <= 1; y++)
			expectedOut[nx * (ny / 2 + y) + (nx / 2 + x)] = 1.0;
}

void print2dData(float *data, char* name, int nx, int ny)
{
	printf("\n%s\n", name);
	for (int y = 0; y < ny; y++) {
		for (int x = 0; x < nx; x++) {
			printf("%5.2g", data[y * nx + x]);
		}
		printf("\n");
	}
}

int check(int size, float *dataOut, float *expectedOut)
{
	int status = 0;
	for (int i = 0; i < size; i++) {
		if (dataOut[i] != expectedOut[i]) {
			fprintf(stderr, "Error in output data at location %d, expected %g, received %g\n",
				i, expectedOut[i], dataOut[i]);
			status = 1;
		}
	}
	return status;
}

int checkInt(int size, uint32_t *dataOut, uint32_t *expectedOut)
{
	int status = 0;
	for (int i = 0; i < size; i++) {
		if (dataOut[i] != expectedOut[i]) {
			fprintf(stderr, "Error in output data at location %d, expected %d, received %d\n",
				i, expectedOut[i], dataOut[i]);
			status = 1;
		}
	}
	return status;
}

void TwoDAverageDynamicCPU(int size, int nx, float *dataIn, uint32_t *counterOut, float *dataOut)
{
	const int ny = size / nx;
	for (int i = 1; i < nx - 1; i++) {
		for (int j = 1; j < ny - 1; j++) {
			dataOut[j * nx + i] =
				(dataIn[(j-1)*nx + i - 1] +
				dataIn[(j-1)*nx + i ] +
				dataIn[(j-1)*nx + i + 1] +
				dataIn[j*nx + i - 1] +
				dataIn[j*nx + i] +
				dataIn[j*nx + i + 1]  +
				dataIn[(j+1)*nx + i - 1] +
				dataIn[(j+1)*nx + i ] +
				dataIn[(j+1)*nx + i + 1]) / 9.0;
		}
	}
	for (int i=0 ; i < ny*nx ; i++) {
		counterOut[i] = (i % 32);
	}
}

int main()
{
	const int NX = 16;
	const int NY = 16;
	size_t sizeBytes = NX * NY * sizeof(float);
	float *dataIn = malloc(sizeBytes);
	float *dataOut = malloc(sizeBytes);
	uint32_t *counterOut = malloc(sizeBytes);
	uint32_t *expectedcounterOut = malloc(sizeBytes);
	float *expectedOut = malloc(sizeBytes);
	generateInputData(dataIn, expectedOut, NX, NY);

	int nxMax = TwoDAverageDynamic_nxMax;
	if (NX > nxMax) {
		fprintf(
			stderr,
			"2D filter with maximum size nxMax=%d can not process data with nx=%d\n",
			nxMax,
			NX);
		exit(1);
	}
	if (NY < 1) {
		fprintf(
			stderr,
			"Invalid ny size (%d), ny must be greater than 1\n",
			NY);
		exit(1);
	}

	TwoDAverageDynamicCPU(NX*NY, NX, dataIn, expectedcounterOut, expectedOut);

	printf("Running DFE.\n");
	TwoDAverageDynamic(NX*NY, NX, dataIn, counterOut, dataOut);

	// Display results, if we're running a small size
	if (NX < 20 && NY < 20) {
		print2dData(dataIn, "INPUT DATA", NX, NY);
		print2dData(dataOut, "OUTPUT DATA", NX, NY);
	} else
		printf("(Not displaying output data of size %dx%d)\n", NX, NY);

	int statusOutput = check(NX*NY, dataOut, expectedOut);
	int statusCounter = checkInt(NX*NY, counterOut, expectedcounterOut);

	int status = statusOutput && statusCounter;
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}

