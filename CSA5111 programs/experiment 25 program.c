#include <stdio.h>

long long gcd(long long a,
              long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

long long modInverse(long long e,
                     long long phi)
{
    long long t = 0;
    long long newt = 1;

    long long r = phi;
    long long newr = e;

    while (newr != 0)
    {
        long long quotient = r / newr;

        long long temp = newt;
        newt = t - quotient * newt;
        t = temp;

        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }

    if (r > 1)
        return -1;

    if (t < 0)
        t += phi;

    return t;
}

int main()
{
    long long n, e;
    long long message;

    printf("Enter RSA modulus n: ");
    scanf("%lld", &n);

    printf("Enter public exponent e: ");
    scanf("%lld", &e);

    printf("Enter known plaintext block: ");
    scanf("%lld", &message);

    long long factor =
        gcd(message, n);

    printf("\ngcd(M, n) = %lld\n",
           factor);

    if (factor > 1 &&
        factor < n)
    {
        long long p = factor;
        long long q = n / p;

        printf("\nRSA Factor Found!\n");

        printf("p = %lld\n", p);
        printf("q = %lld\n", q);

        long long phi =
            (p - 1) * (q - 1);

        printf("phi(n) = %lld\n", phi);

        long long d =
            modInverse(e, phi);

        printf("Private exponent d = %lld\n",
               d);
    }
    else
    {
        printf("No useful common factor found.\n");
    }

    return 0;
}
