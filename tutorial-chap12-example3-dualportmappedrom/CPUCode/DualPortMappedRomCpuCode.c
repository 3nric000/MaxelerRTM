/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 12      Example: 3      Name: Dualport mapped ROM
 * MaxFile name: DualPortMappedRom
 * Summary:
 *       CPU code for a design which uses a dual port mapped ROM.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void generateInputData(
	int size,
	uint8_t *inStreamAddressA,
	uint8_t *inStreamAddressB,
	double *romContents,
	double *romContentsReversed)
{
	for (int i = 0; i < size; i++) {
		inStreamAddressA[i] = size - 1 - i;
		inStreamAddressB[i] = i;
	}

	for (int i = 0; i < size; i++) {
		romContents[i] = sin(((M_PI / 2.0) / size) * i);
	}

	for (int i = 0; i < size; i++) {
		romContentsReversed[size - 1 - i] = romContents[i];
	}
}

int check(
	int size,
	float *outStreamDataA,
	float *outStreamDataB,
	double *romContents,
	double *romContentsReversed)
{
	int status = 0;
	for (int i = 0; i < size; ++i) {
		if (fabs(outStreamDataA[i] - romContentsReversed[i]) > 0.01) {
			fprintf(stderr, "%d => %1.8g\n", i, outStreamDataA[i]);
			fprintf(stderr, "ERROR, expected %1.8g\n", romContentsReversed[i]);
			status = 1;
		}
		if (fabs(outStreamDataB[i] - romContents[i]) > 0.01) {
				fprintf(stderr, "%d => %1.8g\n", i, outStreamDataB[i]);
				fprintf(stderr, "ERROR, expected %1.8g\n", romContents[i]);
				status = 1;
		}
	}

	return status;
}

int main()
{
	const int size = 256;
	int sizeBytesFloat = size * sizeof(float);
	int sizeBytesDouble = size * sizeof(double);
	int sizeBytesInt = size * sizeof(uint8_t);
	uint8_t *inAddressA = malloc(sizeBytesInt);
	uint8_t *inAddressB = malloc(sizeBytesInt);
	double *romContents = malloc(sizeBytesDouble);
	double *romContentsReversed = malloc(sizeBytesDouble);
	float *outDataA = malloc(sizeBytesFloat);
	float *outDataB = malloc(sizeBytesFloat);

	generateInputData(
		size,
		inAddressA, inAddressB,
		romContents, romContentsReversed);

	printf("Running DFE.\n");
	DualPortMappedRom(
		size,
		inAddressA,	inAddressB,
		outDataA, outDataB,
		romContents);

	int status = check(
		size,
		outDataA, outDataB,
		romContents, romContentsReversed);

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
