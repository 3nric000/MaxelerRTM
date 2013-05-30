/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 5      Example: 1      Name: Printf
 * MaxFile name: Printf
 * Summary:
 *        Example showing the use of debug printf.
 */
#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int comparePrintfResults()
{
	FILE *fp1, *fp2;
	if ((fp1 = fopen("debug/debug_printf.txt", "r")) == NULL) {
		fprintf(stderr, "Cannot open printf output file.\n");
		fprintf(stderr, "Exiting\n");
		return 1;
	}
	if ((fp2 = fopen("printf_output_golden.txt", "r")) == NULL) {
		fprintf(stderr, "Cannot open printf golden data file.\n");
		fprintf(stderr, "Exiting\n");
		return 1;
	}

	unsigned long l = 0;
	char ch1, ch2, same = 1;

	/* compare the files */
	while (!feof(fp1)) {
		ch1 = fgetc(fp1);
		if (ferror(fp1)) {
			fprintf(stderr, "Error reading printf output file.\n");
			exit(1);
		}
		ch2 = fgetc(fp2);
		if (ferror(fp2)) {
			fprintf(stderr, "Error reading printf golden data file.\n");
			exit(1);
		}
		if (ch1 != ch2) {
			fprintf(stderr, "Files differ at byte number %lu: expected: %i found: %i\n",
				l, (int) ch2, (int) ch1);
			same = 0;
			break;
		}
		l++;
	}
	fclose(fp1);
	fclose(fp2);

	return same;
}

void PrintfCPU(int size, float *dataIn, float *dataOut) {
	dataOut[0] = (dataIn[0] + dataIn[1]) / 2;
	dataOut[size - 1] = (dataIn[size - 2] + dataIn[size -1]) / 2;
	for (int i = 1; i < size - 1; i++) {
		dataOut[i] = (dataIn[i - 1] + dataIn[i] + dataIn[i + 1]) / 3;
	}
}

int check(float *dataOut, float *expected, int size)
{
	int status = 0;
	for (int i = 0; i < size; i++)
		if (dataOut[i] != expected[i]) {
			fprintf(stderr, "Output data @ %d = %f (expected %f)\n",
				i, dataOut[i], expected[i]);
			status = 1;
		}

	return status || (comparePrintfResults() == 0);
}

const int size = 8;
float dataIn[8] = { 1, 5, 6, 7, 2, 0, 1, 11 };
float expected[8];
float dataOut[8];

int main(void)
{
	printf("Running Kernel.\n");
	Printf(size, size, dataIn, dataOut);

	PrintfCPU(size, dataIn, expected); // generate expected data

	int status = check(dataOut, expected, size);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}

