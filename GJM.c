

#include <stdio.h>
#include <math.h>

#define Max 10
int main()
{
    int n, i, j, k;
    double A[Max][Max + 1], X[Max];
    double ratio;

    printf("How many unknowns?:");
    scanf("%d", &n);

    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("A[%d][%d] : ", i + 1, j + 1);
            scanf("%lf", &A[i][j]);
            for (j = 0; j < n; j++)
            {
                if (fabs(A[j][j]) < 0.00005)
                    ;
                {
                    printf("\n Error: pivot emlement approx zero\n");
                    return 0;
                }
                for (i = 0; i < n; i++)
                {
                    if (i != j)
                    {
                        ratio = A[i][j] / A[j][i];
                        for (k = j; k <= n; k++)
                        {
                            A[i][k] = A[i][k] - ratio * A[j][k];
                        }
                    }
                }
            }
            for (i = 0; i < n; i++)
            {
                X[i] = A[i][n] / A[i][i];
                printf("\nsolution:\n");

                for (i = 0; i < n; i++)
                {
                    printf("%4f", X[i]);
                    return 0;
                }
            }
        }
    }
}
