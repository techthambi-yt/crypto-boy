#include <stdio.h>

int power(int a, int b, int n)
{
    int r = 1;
    while (b--)
        r = (r * a) % n;
    return r;
}

int main()
{
    int p, q, e, d, n, phi, m, c;

    printf("Enter p, q, e and message: ");
    scanf("%d%d%d%d", &p, &q, &e, &m);

    n = p * q;
    phi = (p - 1) * (q - 1);

    for (d = 1; d < phi; d++)
        if ((e * d) % phi == 1)
            break;

    c = power(m, e, n);

    printf("Public Key  = (%d, %d)\n", e, n);
    printf("Private Key = (%d, %d)\n", d, n);
    printf("Encrypted Message = %d\n", c);

    printf("If private key is leaked, using the same n is NOT safe.\n");
    printf("A new modulus must be generated.\n");

    return 0;
}
