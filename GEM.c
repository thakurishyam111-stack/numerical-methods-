
#include <stdio.h>
#include <math.h>
#define MAX 10

int main()
{
    int i, n, k, j;

    double A[MAX][MAX + 1], X[MAX];

    double ratio;
    printf("how many unknowns? ");
    scanf("%d", &n);

    printf("\nEnter the augmented co-eff .metrix \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
            scanf("%lf", &A[i][j]);
    for (j = 0; j < n - 1; j++)
    {
        if (fabs(A[i][j]) < 0.00005)
        {
            printf("\nError:pivot element approx .zero!");
            return 0;
        }
        for (i = j + 1; i < n; i++)
        {
            ratio = A[i][j] / A[j][j];
            for (k = j; k < n; k++)
            {
                A[i][k] = A[i][k] - ratio * A[j][k];
            }
        }
    }

    for (i = n; i >= 0; i--)
    {
        X[i] = A[i][n];
        for (j = i + 1; j < n; j++)
            X[i] = X[i] - A[i][j] * X[j];
        X[i] = X[i] / A[i][i];
    }
    printf("\nsolution :");
    for (i = 0; i < n; i++)
        printf("\n%.4f", X[i]);
}
