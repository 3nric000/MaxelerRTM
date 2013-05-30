/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 12      Example: 2      Name: Rom Manager
 * MaxFile name: Rom
 * Summary:
 *       CPU code for a single port ROM design which takes an input stream of
 *  addresses and outputs the contents of the ROM.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void generateInputData(int size, uint8_t *inAddress)
{
	for (int i = 0; i < size; i++)
		inAddress[i] = rand()%size;
}

void RomCPU(int size, uint8_t * inAddress, float *out)
{
	for (int i = 0; i < size; i++)
		out[i] = sin(((M_PI / 2.0) / size) * inAddress[i]);
}

int check(int size, float *outData, float *expected)
{
	int status = 0;
	for (int i = 0; i < size; ++i) {
		if (outData[i] != expected[i]) {
			fprintf(stderr, "%d => %1.8g\n", i, outData[i]);
			fprintf(stderr, "ERROR, expected %1.8g\n", expected[i]);
			status = 1;
		}
	}
	return status;
}

int main()
{
	const int size = 256;
	int sizeBytesFloat = size * sizeof(float);
	uint8_t *inAddress = malloc(size * sizeof(uint8_t));
	float *out = malloc(sizeBytesFloat);
	float *expected = malloc(sizeBytesFloat);

	generateInputData(size, inAddress);

	printf("Running DFE.\n");
	Rom(size, inAddress, out);

	RomCPU(size, inAddress, expected);

	int status = check(size, out, expected);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}

