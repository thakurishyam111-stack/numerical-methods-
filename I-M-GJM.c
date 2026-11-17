#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    float a[SIZE][2 * SIZE];
    int n, i, j, k;

    printf("Enter the order of the matrix (n): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n; j++) {
            if (j >= n) {
                if (j == (i + n))
                    a[i][j] = 1.0;
                else
                    a[i][j] = 0.0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error: Division by zero! Matrix is singular and cannot be inverted.\n");
            return 0;
        }

        for (j = 0; j < 2 * n; j++) {
            if (j != i) {
                float ratio = a[j][i] / a[i][i];
                for (k = 0; k < 2 * n; k++) {
                    if (j != i) {
                        a[j][k] = a[j][k] - ratio * a[i][k];
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        float temp = a[i][i];
        for (j = 0; j < 2 * n; j++) {
            a[i][j] = a[i][j] / temp;
        }
    }

    printf("\nThe Inverse of the given matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            printf("%8.4f\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}