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
    int p, q, e, n, m, c;

    printf("Enter p, q and e: ");
    scanf("%d%d%d", &p, &q, &e);

    n = p * q;

    printf("Enter character value (A=0 to Z=25): ");
    scanf("%d", &m);

    c = power(m, e, n);

    printf("Encrypted value = %d\n", c);
    printf("This method is NOT secure.\n");
    printf("Attack: Codebook or frequency analysis.\n");

    return 0;
}
