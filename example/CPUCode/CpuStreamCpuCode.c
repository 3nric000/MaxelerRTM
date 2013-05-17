#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

#define N 10

int main(void) {
	int *str, *strout;
	int cube[N][N][N];
	int cubeout[N][N][N];
	int i, j, k, w;
	int valiprec, valinext, valjprec, valjnext, valkprec, valknext;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				cube[i][j][k] = 1 + k + j * N + i * N * N;
			}
		}
	}

	/*for(i=0; i<N; i++){
	 for(j=0; j<N; j++){
	 for(k=0; k<N; k++){
	 printf("%d ",cube[i][j][k]);
	 }
	 printf("\n");
	 }
	 printf("\n");
	 }
	 */

	str = malloc(sizeof(int) * N * N * N);
	strout = malloc(sizeof(int) * N * N * N);
	w = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++, w++) {
				*(str + w) = cube[i][j][k];
			}
		}
	}

	for (i = 1; i < N-1; i++) {
		for (j = 1; j < N-1; j++) {
			for (k = 1; k < N-1; k++) {
				valiprec = i - 1 >= 0 ? cube[i - 1][j][k] : 0;
				valinext = i + 1 < N ? cube[i + 1][j][k] : 0;
				valjprec = j - 1 >= 0 ? cube[i][j - 1][k] : 0;
				valjnext = j + 1 < N ? cube[i][j + 1][k] : 0;
				valkprec = k - 1 >= 0 ? cube[i][j][k - 1] : 0;
				valknext = k + 1 < N ? cube[i][j][k + 1] : 0;
				cubeout[i][j][k] = valiprec + valjprec + valkprec + valinext
						+ valjnext + valknext;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				printf("%d ", cubeout[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("\nRunning DFE\n");
	CpuStream(N * N * N, N, N * N, str, strout);

	int ok = 1;
	w = 0;
	for (i = 1; i < N-1 && ok; i++) {
		for (j = 1; j < N-1 && ok; j++) {
			for (k = 1; k < N-1 && ok; k++) {
				if (*(strout + (k+j*N+i*N*N)) != cubeout[i][j][k]) {
					ok = 0;
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	if (ok) {
		printf("\ndati uguali\n");
	} else {
		printf("\nerrore\n");
	}

	/*
	for (i = 0; i < N * N * N; i++) {
		printf("%d ", *(strout + i));
	}

	
	 const int size = 384;
	 int sizeBytes = size * sizeof(int32_t);
	 int32_t *x = malloc(sizeBytes);
	 int32_t *y = malloc(sizeBytes);
	 int32_t *s = malloc(sizeBytes);

	 // TODO Generate input data
	 for(int i = 0; i < size; ++i) {
	 x[i] = random() % 100;
	 y[i] = random() % 100;
	 }

	 printf("Running on DFE.\n");
	 int scalar = 3;
	 CpuStream(scalar, size, x, y, s);

	 // TODO Use result data
	 for(int i = 0; i < size; ++i)
	 if ( s[i] != x[i] + y[i] + scalar)
	 return 1;

	 printf("Done.\n");*/
	return 0;
}
