#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    int i, j, n;
    float a[MAX][MAX + 1], x[MAX], x_old[MAX];
    float error, toler;
    int max_iter, iter = 0;

    printf("Enter the number of equations (n): ");
    scanf("%d", &n);

    printf("Enter the augmented matrix coefficients (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter initial guesses for variables:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
    }

    printf("Enter tolerable error (e.g., 0.0001): ");
    scanf("%f", &toler);

    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);

    printf("\nIter\t");
    for (i = 0; i < n; i++) {
        printf("x[%d]\t\t", i + 1);
    }
    printf("\n--------------------------------------------------\n");

    do {
        iter++;
        error = 0.0;

        for (i = 0; i < n; i++) {
            x_old[i] = x[i];
            float sum = 0.0;
            
            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum += a[i][j] * x[j];
                }
            }
            
            x[i] = (a[i][n] - sum) / a[i][i];

            if (fabs(x[i] - x_old[i]) > error) {
                error = fabs(x[i] - x_old[i]);
            }
        }

        printf("%d\t", iter);
        for (i = 0; i < n; i++) {
            printf("%8.4f\t", x[i]);
        }
        printf("\n");

        if (error < toler) {
            printf("\nConverged successfully in %d iterations.\n", iter);
            break;
        }

    } while (iter < max_iter);

    if (iter == max_iter && error >= toler) {
        printf("\nSolution did not converge within %d iterations.\n", max_iter);
    }

    printf("\nFinal Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, x[i]);
    }

    return 0;
}