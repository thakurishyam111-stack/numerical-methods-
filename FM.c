#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {
    int i, j, k, n;
    float a[MAX][MAX], l[MAX][MAX], u[MAX][MAX];
    float b[MAX], y[MAX], x[MAX];
    float sum = 0.0;

    printf("Enter the order of matrix (n): ");
    scanf("%d", &n);

    printf("Enter elements of matrix A (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter elements of vector B:\n");
    for (i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%f", &b[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            l[i][j] = 0.0;
            u[i][j] = 0.0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            sum = 0.0;
            for (k = 0; k < i; k++) {
                sum += (l[i][k] * u[k][j]);
            }
            u[i][j] = a[i][j] - sum;
        }

        for (j = i; j < n; j++) {
            if (i == j) {
                l[i][i] = 1.0; 
            } else {
                sum = 0.0;
                for (k = 0; k < i; k++) {
                    sum += (l[j][k] * u[k][i]);
                }
                if (u[i][i] == 0) {
                    printf("Mathematical Error: Division by zero (u[%d][%d] = 0).\n", i, i);
                    return 0;
                }
                l[j][i] = (a[j][i] - sum) / u[i][i];
            }
        }
    }

    for (i = 0; i < n; i++) {
        sum = 0.0;
        for (k = 0; k < i; k++) {
            sum += l[i][k] * y[k];
        }
        y[i] = b[i] - sum;
    }

    for (i = n - 1; i >= 0; i--) {
        sum = 0.0;
        for (k = i + 1; k < n; k++) {
            sum += u[i][k] * x[k];
        }
        if (u[i][i] == 0) {
            printf("Mathematical Error: Division by zero during back substitution.\n");
            return 0;
        }
        x[i] = (y[i] - sum) / u[i][i];
    }

    printf("\nSolution of the linear system:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, x[i]);
    }

    return 0;
}