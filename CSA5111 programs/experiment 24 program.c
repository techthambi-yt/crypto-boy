#include <stdio.h>

int extendedGCD(int a, int b,
                int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;

        return b;
    }

    int x1, y1;

    int gcd = extendedGCD(
        b % a,
        a,
        &x1,
        &y1
    );

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    int n = 3599;
    int e = 31;

    int p = 0, q = 0;

    /* Trial-and-error factorization */

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            p = i;
            q = n / i;
            break;
        }
    }

    printf("n = %d\n", n);
    printf("p = %d\n", p);
    printf("q = %d\n", q);

    int phi =
        (p - 1) * (q - 1);

    printf("phi(n) = %d\n", phi);

    int x, y;

    int gcd = extendedGCD(
        e,
        phi,
        &x,
        &y
    );

    int d = (x % phi + phi) % phi;

    printf("\nPublic Key:\n");
    printf("(e, n) = (%d, %d)\n", e, n);

    printf("\nPrivate Key:\n");
    printf("(d, n) = (%d, %d)\n", d, n);

    return 0;
}
