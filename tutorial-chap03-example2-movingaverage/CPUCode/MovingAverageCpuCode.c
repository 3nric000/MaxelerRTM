/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial)
 * Chapter: 3      Example: 2      Name: Moving Average
 * MaxFile name: MovingAverage
 * Summary:
 *   CPU code for the three point moving average design.
 */
#include "Maxfiles.h" 			// Includes .max files
#include <MaxSLiCInterface.h>	// Simple Live CPU interface

float dataIn[8] = { 1, 0, 2, 0, 4, 1, 8, 3 };
float dataOut[8];

int main()
{
	printf("Running DFE\n");
	MovingAverage(8, dataIn, dataOut);

	for (int i = 1; i < 7; i++) // Ignore edge values
		printf("dataOut[%d] = %f\n", i, dataOut[i]);

	return 0;
}

