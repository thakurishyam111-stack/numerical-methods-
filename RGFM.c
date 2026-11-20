

#include <stdio.h>
#include <math.h>

#define f(x) (sin(x) - cos(x))

int main()
{
    float a, b, c, E;

    printf("Enter the initial interval (a,b): ");
    scanf("%f %f", &a, &b);

    printf("Enter the tolerance (E): ");
    scanf("%f", &E);

    if (f(a) * f(b) >= 0)
    {
        printf("Error: No root in the given interval\n");
        return 0;
    }

    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(f(c)) > E);

    printf("\nThe root is: %.4f\n", c);

    return 0;
}
