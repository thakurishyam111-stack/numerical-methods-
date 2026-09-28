#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x + 4 * x - 10;
}

int main()
{
    double a, b, c, E;
    int I, N;

    printf("Enter the initial guesses (a, b): ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the tolerance (E): ");
    scanf("%lf", &E);

    printf("Enter the maximum number of iterations (N): ");
    scanf("%d", &N);

    I = 0;

    do
    {
        if (fabs(f(b) - f(a)) < 0.000005)
        {
            printf("Mathematical error: division by zero\n");
            return 0;
        }

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        a = b;
        b = c;

        I = I + 1;

        if (I >= N)
        {
            printf("The method did not converge after %d iterations\n", N);
            return 0;
        }

    } while (fabs(f(c)) > E);

    printf("The root is %lf\n", c);

    return 0;
}