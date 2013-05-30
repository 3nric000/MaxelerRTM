/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 12      Example: 1      Name: DualPort RAM
 * MaxFile name: DualPortRam
 * Summary:
 *       Shows how to create a design that uses a dual port RAM to reverse
 *   the order of data in an input stream.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

int check(int size, float *outStreamData, float *inStreamData)
{
	int status = 0;
	for (int i = 0; i < size; ++i) {
		if (fabs(outStreamData[i] - inStreamData[size - 1 - i]) > 0.01f) {
			fprintf(stderr, "%d => %f\n", i, outStreamData[i]);
			fprintf(stderr, "ERROR, expected %f\n",
				inStreamData[size - 1 - i]);
			status = 1;
		}
	}
	return status;
}

int main()
{
	const int size = 16;
	int sizeBytes = size * sizeof(float);
	float *inStreamData = malloc(sizeBytes);
	float *outStreamData = malloc(sizeBytes);

	for (int i = 0; i < size; i++)
		inStreamData[i] = i;

	printf("Running DFE.\n");
	DualPortRam(size, inStreamData, outStreamData);

	int status = check(size, outStreamData, inStreamData);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
