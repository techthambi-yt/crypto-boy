#include <stdio.h>

long long power(long long a, long long b, long long q)
{
    long long r = 1;

    while (b > 0)
    {
        r = (r * a) % q;
        b--;
    }

    return r;
}

int main()
{
    long long a, q, x, y;
    long long A, B, keyA, keyB;

    printf("Enter public a and q: ");
    scanf("%lld%lld", &a, &q);

    printf("Enter Alice secret x: ");
    scanf("%lld", &x);

    printf("Enter Bob secret y: ");
    scanf("%lld", &y);

    A = power(a, x, q);
    B = power(a, y, q);

    keyA = power(B, x, q);
    keyB = power(A, y, q);

    printf("\nAlice sends: %lld\n", A);
    printf("Bob sends: %lld\n", B);

    printf("Alice key: %lld\n", keyA);
    printf("Bob key: %lld\n", keyB);

    if (keyA == keyB)
        printf("Key exchange successful.\n");
    else
        printf("Key exchange failed.\n");

    return 0;
}
