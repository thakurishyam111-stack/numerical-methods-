
#include <stdio.h>
#include <math.h>

double g(double x) { return (2 - cos(x)) / 3; }

int main()
{
    double x0, x1, E, err;
    int I, N;

    printf("Initial guess (x0):");
    scanf("%lf", &x0);

    printf("Error tolerance (err):");
    scanf("%lf", &err);

    printf("Maximum iterations (N):");
    scanf("%d", &N);

    I = 0;
    do
    {
        x1 = g(x0);
        err = fabs(x1 - x0);
        x0 = x1;
        I++;
        if (I > N)
        {
            printf("Error :Not converging\n");
            return 0;
        }

    } while (err > E );
    {
        printf("After %d iterations, the root is: %f\n", I, x0);
        return 0;
    }
}
