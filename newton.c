#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * sin(x) + cos(x);
}

double g(double x)
{
    return x * cos(x);
}

int main()
{
    double x0, x1, E;
    int N, I = 0;

    printf("Enter the initial guess (x0): ");
    scanf("%lf", &x0);

    printf("Enter the tolerance (E): ");
    scanf("%lf", &E);

    printf("Enter the maximum number of iterations (N): ");
    scanf("%d", &N);

    while (fabs(f(x0)) > E)
    {
        if (I >= N)
        {
            printf("Maximum number of iterations reached\n");
            return 0;
        }

        if (fabs(g(x0)) < 0.000005)
        {
            printf("Mathematical error: division by zero\n");
            return 0;
        }

        x1 = x0 - f(x0) / g(x0);

        printf("Iteration %d: x = %lf\n", I + 1, x1);

        x0 = x1;
        I++;
    }

    printf("\nRoot = %lf\n", x0);
    printf("Iterations = %d\n", I);

    return 0;
}