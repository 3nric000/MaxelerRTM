/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial)
 * Chapter: 3      Example: 3      Name: Moving Average Weighted
 * MaxFile name: MovingAverageWeighted
 * Summary:
 *   CPU code for the three point moving average design.
 */
#include "Maxfiles.h" 			// Includes .max files
#include <MaxSLiCInterface.h>	// Simple Live CPU interface

float dataIn[8] = { 1, 0, 2, 0, 4, 1, 8, 3 };
float dataOut[8];

int main()
{
	float coeffs[3] = {0.75, 1.5, 0.75};

	printf("Running DFE\n");
	MovingAverageWeighted_weighted(8, coeffs, dataIn, dataOut);

	for (int i = 1; i < 7; i++) // Ignore edge values
		printf("dataOut[%d] = %f\n", i, dataOut[i]);

	return 0;
}
