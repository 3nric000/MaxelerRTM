/**
 * Document: Manager Compiler Tutorial (maxcompiler-manager-tutorial.pdf)
 * Chapter: 5      Example: 2      Name: Scalar HDL
 * MaxFile name: ScalarHDL
 * Summary:
 *     Streams data in and out of a design using a custom HDL node which
 *     implements a counter and checks for correctness. Sets up a scalar input
 *     corresponding to the number of cycles that the count is held once it
 *     reaches maximum.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

#define COUNTING_UP   0
#define COUNTING_DOWN 1
#define HOLD_COUNT 2

void generateInputData(int size, uint32_t *dataIn)
{
	srand(12345);
	for (int i = 0; i < size; i++)
		dataIn[i] = rand() >> 24;
}

void ScalarHDLCPU(int dataSize, int holdCount, uint32_t *dataIn, uint32_t *dataOut)
{
	int counter = 0, nextCounter = 0, holdCounter = 0, nextHoldCounter = 0;
	int max, mode = COUNTING_UP, nextMode = COUNTING_UP;

	for (int i = 0; i < dataSize; i++) {
		max = (int) dataIn[i];
		switch (mode)
		{
			case COUNTING_UP:
				if (counter == max) {
					nextMode = HOLD_COUNT;
				} else {
					if (counter > max) {
						nextCounter = max;
						nextMode = HOLD_COUNT;
					} else {
						nextCounter = counter + 1;
					}
				}
				break;
			case COUNTING_DOWN:
				if (counter == 0) {
					nextCounter = counter + 1;
					nextMode = COUNTING_UP;
				} else
					nextCounter = counter - 1;
				break;
			default:
				if (holdCounter == holdCount) {
					nextHoldCounter = 0;
					nextMode = COUNTING_DOWN;
				} else
					nextHoldCounter = holdCounter + 1;
		}
		dataOut[i] = counter;
		if (i < dataSize - 1) {
			//Don't do the last update as this won't be enabled
			counter = nextCounter;
			holdCounter = nextHoldCounter;
			mode = nextMode;
		}
	}
}

int check(
	int size,
	uint32_t *dataOut,
	uint32_t *expected)
{
	int status = 0;
	for (int i = 0; i < size; i++)
		if ( dataOut[i] != expected[i] ) {
			fprintf(stderr,	"Error in output: Output data @ %d = %d (expected %d)\n",
				i, dataOut[i], expected[i]);
			status = 1;
		}
	return status;
}


int main()
{
	const int size = 1024;
	const int holdCount = 2;

	int sizeBytes = size * sizeof(uint32_t);
	uint32_t *dataIn   = malloc(sizeBytes);
	uint32_t *dataOut  = malloc(sizeBytes);
	uint32_t *expected = malloc(sizeBytes);

	generateInputData(size, dataIn);

	printf("Running DFE.\n");
	ScalarHDL(size, holdCount, dataIn, dataOut);

	ScalarHDLCPU(size, holdCount, dataIn, expected);

	int status = check(size, dataOut, expected);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
