#include <stdio.h>

int main() {
    int p, q, n, phi, e, d, m, c;

    printf("Enter p, q, e, message: ");
    scanf("%d%d%d%d", &p, &q, &e, &m);

    n = p * q;
    phi = (p - 1) * (q - 1);

    for (d = 1; d < phi; d++)
        if ((d * e) % phi == 1)
            break;

    c = 1;
    for (int i = 0; i < e; i++)
        c = (c * m) % n;

    printf("n = %d\n", n);
    printf("Private key d = %d\n", d);
    printf("Encrypted message = %d\n", c);
    printf("If d is leaked, generating only new e,d with same n is NOT safe.\n");
    printf("Generate a new modulus n using new prime numbers.\n");

    return 0;
}
