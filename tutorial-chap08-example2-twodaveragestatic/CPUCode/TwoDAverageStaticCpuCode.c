/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial)
 * Chapter: 8      Example: 2      Name: Two Dimensional Average Static
 * MaxFile name: TwoDAverageStatic
 * Summary:
 *   Averages within an 8-point window.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

void generateInputData(float *dataIn, int nx, int ny)
{
	for (int i = 0; i < nx * ny; i++) {
		dataIn[i] = 0;
	}
	dataIn[nx * (ny / 2) + nx / 2] = 9;
}

int check(int size, float *dataOut, float *expectedOut)
{
	int status = 0;
	for (int i = 0; i < size; i++) {
		if (dataOut[i] != expectedOut[i]) {
			fprintf(
				stderr,
				"Error in output data at location %d, expected %g, received %g\n",
				i,
				expectedOut[i],
				dataOut[i]);
			status = 1;
		}
	}
	return status;
}

void print_2d_data(float *data, char* name, int nx, int ny)
{
	printf("\n%s\n", name);
	for (int y = 0; y < ny; y++) {
		for (int x = 0; x < nx; x++) {
			printf("%5.2g", data[y * nx + x]);
		}
		printf("\n");
	}
}

void TwoDAverageStaticCPU(int size, float *dataIn, float *dataOut)
{
	const int nx = TwoDAverageStatic_nxMax;
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
}

int main()
{
	const int NX = 4096;
	const int NY = 4096;
	size_t sizeBytes = NX * NY * sizeof(float);
	float *dataIn = malloc(sizeBytes);
	float *dataOut = malloc(sizeBytes);
	float *expected = malloc(sizeBytes);
	generateInputData(dataIn, NX, NY);

	int nxMax = TwoDAverageStatic_nxMax;
	if (NX != nxMax) {
		fprintf(
			stderr,
			"2D filter with static size nx=%d can not process data with nx=%d\n",
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
	TwoDAverageStaticCPU(NX * NY, dataIn, expected);

	printf("Running DFE.\n");
	TwoDAverageStatic(NX * NY, dataIn, dataOut);

	// Display results, if we're running a small size
	if (NX < 20 && NY < 20) {
		print_2d_data(dataIn, "INPUT DATA", NX, NY);
		print_2d_data(dataOut, "OUTPUT DATA", NX, NY);
	} else {
		printf("(Not displaying output data of size %dx%d)\n", NX, NY);
	}

	int status = check(NX * NY, dataOut, expected);

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}

