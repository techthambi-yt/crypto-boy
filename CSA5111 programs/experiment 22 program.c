#include <stdio.h>

unsigned char encrypt(unsigned char block,
                      unsigned char key)
{
    /* Simplified cipher operation */
    return block ^ key;
}

unsigned char decrypt(unsigned char block,
                      unsigned char key)
{
    return block ^ key;
}

int main()
{
    unsigned char key;
    unsigned char iv;

    unsigned char p1, p2;
    unsigned char c1, c2;

    unsigned char d1, d2;

    printf("Enter 8-bit key in decimal: ");
    scanf("%hhu", &key);

    printf("Enter IV in decimal: ");
    scanf("%hhu", &iv);

    printf("Enter plaintext block 1: ");
    scanf("%hhu", &p1);

    printf("Enter plaintext block 2: ");
    scanf("%hhu", &p2);

    /* CBC Encryption */

    c1 = encrypt(p1 ^ iv, key);
    c2 = encrypt(p2 ^ c1, key);

    printf("\nCiphertext:\n");
    printf("C1 = %u\n", c1);
    printf("C2 = %u\n", c2);

    /* CBC Decryption */

    d1 = decrypt(c1, key) ^ iv;
    d2 = decrypt(c2, key) ^ c1;

    printf("\nDecrypted Plaintext:\n");
    printf("P1 = %u\n", d1);
    printf("P2 = %u\n", d2);

    return 0;
}
