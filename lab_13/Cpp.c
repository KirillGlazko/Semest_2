#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define SIZE(x)  (sizeof(x) / sizeof((x)[0]))

void bubblesort_increase(int *parr, int N) { //по возврастаню
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			if (parr[j] > parr[j + 1]) {
				int buf = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = buf;
			}
		}
	}
}

void bubblesort_descending(int *parr, int N) { //по убыванию
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			if (parr[j] < parr[j + 1]) {
				int buf = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = buf;
			}
		}
	}
}

int main(int argc, const char * argv[]) {
	int N = 0, M = 0;
	printf("size of arrA: ");
	scanf_s("%d", &N);
	printf("size of arrB: ");
	scanf_s("%d", &M);
	int *arrA = (int*)malloc(N * sizeof(int));
	int *arrB = (int*)malloc(M * sizeof(int));
	srand(time(0));

	for (int i = 0; i < N; ++i)
		arrA[i] = rand() % 10;

	for (int i = 0; i < M; ++i)
		arrB[i] = rand() % 10;

	bubblesort_increase(arrA, N);
	bubblesort_descending(arrB, M);

	printf("arrA: ");
	for (int i = 0; i < N; ++i)
		printf("%d ", arrA[i]);
	printf("\n");

	printf("arrB: ");
	for (int i = 0; i < M; ++i)
		printf("%d ", arrB[i]);
	printf("\n");

	int K = M + N;

	int *arrC = (int*)malloc(K * sizeof(int));

	int n = 0;
	for (int i = 0; i < K / 2; i++) //слияние
	{
		arrC[n++] = arrA[i];
		arrC[n++] = arrB[i];
	}

	/*int *arrC = (int*)malloc(SIZE(arrA) + SIZE(arrB));

	int i = 0, j = 0, k = 0;

	while (i < SIZE(arrA) && j < SIZE(arrB)) {
		arrC[k++] = arrA[i] < arrB[j] ? arrA[i++] : arrB[j++];
	}

	while (i < SIZE(arrA)) arrC[k++] = arrB[i++];
	while (j < SIZE(arrB)) arrC[k++] = arrB[j++];*/

	bubblesort_increase(arrC, K);

	printf("ArrC: ");
	for (int i = 0; i < K; i++) printf("%d ", arrC[i]);
	printf("\n");
	return 0;
}