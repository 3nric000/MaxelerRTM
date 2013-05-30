/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 8      Example: 4      Name: Three-dimensional average variable
 * MaxFile name: ThreeDAverageVariable
 * Summary:
 *       Averages on three dimensions within a 26-point window.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

void generateInputData(float *dataIn, int nx, int ny, int nz) {
	for (int i = 0; i < nx*ny*nz; i++) {
			dataIn[i] = 0;
	}
	dataIn[nx*(ny*(nz/2)) + nx*(ny/2) + nx/2] = 27;
}

void print3dData(float *data, char* name, int nx, int ny, int nz) {
	printf("\n%s\n", name);
	for (int z = 0; z < nz; z++) {
		for (int y = 0; y < ny; y++) {
			for (int x = 0; x < nx; x++) {
				printf("%5.2g", data[z*nx*ny + y*nx + x]);
			}
			printf("\n");
		}
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

void ThreeDAverageVariableCPU(int size, int nx, int nxy, float *dataIn, float *dataOut)
{
	const int ny = nxy / nx;
	const int nz = size / nxy;
	for (int i = 1; i < nx - 1; i++) {
		for (int j = 1; j < ny - 1; j++) {
			for (int k = 1; k < nz - 1; k++) {
				dataOut[k*nx*ny + j*nx + i] =
					(
					dataIn[(k-1)*nx*ny + (j-1)*nx + i - 1] +
					dataIn[(k-1)*nx*ny + (j-1)*nx + i ] +
					dataIn[(k-1)*nx*ny + (j-1)*nx + i + 1] +
					dataIn[(k-1)*nx*ny + j*nx + i - 1] +
					dataIn[(k-1)*nx*ny + j*nx + i] +
					dataIn[(k-1)*nx*ny + j*nx + i + 1]  +
					dataIn[(k-1)*nx*ny + (j+1)*nx + i - 1] +
					dataIn[(k-1)*nx*ny + (j+1)*nx + i ] +
					dataIn[(k-1)*nx*ny + (j+1)*nx + i + 1] +

					dataIn[(k)*nx*ny + (j-1)*nx + i - 1] +
					dataIn[(k)*nx*ny + (j-1)*nx + i ] +
					dataIn[(k)*nx*ny + (j-1)*nx + i + 1] +
					dataIn[(k)*nx*ny + j*nx + i - 1] +
					dataIn[(k)*nx*ny + j*nx + i] +
					dataIn[(k)*nx*ny + j*nx + i + 1]  +
					dataIn[(k)*nx*ny + (j+1)*nx + i - 1] +
					dataIn[(k)*nx*ny + (j+1)*nx + i ] +
					dataIn[(k)*nx*ny + (j+1)*nx + i + 1] +

					dataIn[(k+1)*nx*ny + (j-1)*nx + i - 1] +
					dataIn[(k+1)*nx*ny + (j-1)*nx + i ] +
					dataIn[(k+1)*nx*ny + (j-1)*nx + i + 1] +
					dataIn[(k+1)*nx*ny + j*nx + i - 1] +
					dataIn[(k+1)*nx*ny + j*nx + i] +
					dataIn[(k+1)*nx*ny + j*nx + i + 1]  +
					dataIn[(k+1)*nx*ny + (j+1)*nx + i - 1] +
					dataIn[(k+1)*nx*ny + (j+1)*nx + i ] +
					dataIn[(k+1)*nx*ny + (j+1)*nx + i + 1]
					) / 27.0;
			}
		}
	}
}

int main()
{
	const int NX = 16;
	const int NY = 16;
	const int NZ = 16;
	size_t sizeBytes = NX*NY*NZ * sizeof(float);
	float *dataIn = malloc(sizeBytes);
	float *dataOut = malloc(sizeBytes);
	float *expectedOut = malloc(sizeBytes);
	generateInputData(dataIn, NX, NY, NZ);

	int nxMax = ThreeDAverageVariable_nxMax;
	if (NX > nxMax) {
		fprintf(stderr, "3D filter with maximum size nxMax=%d cannot process data with nx=%d\n",
			nxMax, NX);
		exit(1);
	}
	if (NY < 1) {
		fprintf(stderr, "Invalid ny size (%d), ny must be greater than 1\n",
			NY);
		exit(1);
	}

	ThreeDAverageVariableCPU(NX*NY*NZ, NX, NX*NY, dataIn, expectedOut);

	printf("Running DFE.\n");
	ThreeDAverageVariable(NX*NY*NZ, NX, NX*NY, dataIn, dataOut);

	// Display results, if we're running a small size
	if (NX < 20 && NY < 20 && NZ < 20) {
		print3dData(dataIn, "INPUT DATA", NX, NY, NZ);
		print3dData(dataOut, "OUTPUT DATA", NX, NY, NZ);
	} else printf("(Not displaying output data of size %dx%dx%d)\n", NX, NY, NZ);

	int status = check(NX*NY*NZ, dataOut, expectedOut);

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
