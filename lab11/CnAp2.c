#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	double maxd, maxdp = 0, *B, *X, *d, **A, ESP;
	int i, j, n;
	printf("Enter size of array: ");
	scanf("%d", &n);

	B = (double*)malloc(n * sizeof(double));
	X = (double*)malloc(n * sizeof(double));
	d = (double*)malloc(n * sizeof(double));
	A = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; ++i)
	{
		B[i] = 0; X[i] = 0; d[i] = 0;
		A[i] = (double*)malloc(n * sizeof(double));
		for (j = 0; j < n; ++j)
		{
			A[i][j] = 0;
		}
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("A[%d][%d]=", i, j);
			scanf("%lf", &A[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; ++i)
	{
		printf("B[%d]=", i);
		scanf("%lf", &B[i]);
	}

	printf("\nEnter measurement accurecy: ");
	scanf_s("%lf", &ESP);

	do
	{
		for (i = 0; i < n; ++i)
		{
			d[i] = X[i];
			X[i] = B[i];
			for (j = 0; j < n; ++j)
			{
				if (i != j)
				{
					X[i] -= A[i][j] * X[j];
				}
			}
			X[i] = X[i] / A[i][i];
			d[i] = fabs(d[i] - X[i]);
		}
		maxd = d[0];
		for (i = 1; i < n; ++i)
		{
			if (d[i] > maxd) maxd = d[i];
		}
		if (maxdp == 0)
		{
			maxdp = maxd;
			continue;
		}
		else
		{
			if (maxdp - maxd < 0)
			{
				break;
			}
			else
			{
				maxdp = maxd;
			}
		}
	} while (maxd > ESP);

	for (i = 0; i < n; ++i)
	{
		printf("X[%d]=%lf ", i, X[i]);
	}
	system("pause");
}
