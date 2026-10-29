#include <stdio.h>

int main()
{
    int X, K, T, Y, T2;

    printf("Enter message block X: ");
    scanf("%d", &X);

    printf("Enter key K: ");
    scanf("%d", &K);

    /* MAC of X */
    T = X ^ K;

    /* Second block */
    Y = X ^ T;

    /* MAC of X || Y */
    T2 = T ^ Y ^ K;

    printf("\nMAC of X (T) = %d\n", T);
    printf("X XOR T = %d\n", Y);
    printf("MAC of X || (X XOR T) = %d\n", T2);

    if (T == T2)
        printf("Attack successful: Both MACs are equal.\n");
    else
        printf("MACs are different.\n");

    return 0;
}
