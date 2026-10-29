#include <stdio.h>
#include <string.h>

#define BLOCK 8
#define MAX 256

void xorBlock(unsigned char *a, unsigned char *b,
              unsigned char *result, int size)
{
    int i;

    for (i = 0; i < size; i++)
        result[i] = a[i] ^ b[i];
}

/* Simplified encryption */
void encryptBlock(unsigned char *input,
                  unsigned char *output,
                  unsigned char *key)
{
    int i;

    for (i = 0; i < BLOCK; i++)
        output[i] = input[i] ^ key[i];
}

/* XOR cipher decryption is same */
void decryptBlock(unsigned char *input,
                  unsigned char *output,
                  unsigned char *key)
{
    encryptBlock(input, output, key);
}

/* ECB */
void ECB(unsigned char data[][BLOCK],
         unsigned char result[][BLOCK],
         unsigned char key[])
{
    int i;

    for (i = 0; i < 2; i++)
        encryptBlock(data[i], result[i], key);
}

/* CBC */
void CBC(unsigned char data[][BLOCK],
         unsigned char result[][BLOCK],
         unsigned char key[],
         unsigned char iv[])
{
    unsigned char temp[BLOCK];
    int i;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
            xorBlock(data[i], iv, temp, BLOCK);
        else
            xorBlock(data[i], result[i - 1], temp, BLOCK);

        encryptBlock(temp, result[i], key);
    }
}

/* CFB */
void CFB(unsigned char data[][BLOCK],
         unsigned char result[][BLOCK],
         unsigned char key[],
         unsigned char iv[])
{
    unsigned char registerBlock[BLOCK];
    unsigned char encryptedIV[BLOCK];
    int i;

    memcpy(registerBlock, iv, BLOCK);

    for (i = 0; i < 2; i++)
    {
        encryptBlock(registerBlock, encryptedIV, key);

        xorBlock(data[i], encryptedIV,
                 result[i], BLOCK);

        memcpy(registerBlock, result[i], BLOCK);
    }
}

void printBlocks(unsigned char data[][BLOCK])
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        printf("Block %d: ", i + 1);

        for (j = 0; j < BLOCK; j++)
            printf("%02X ", data[i][j]);

        printf("\n");
    }
}

int main()
{
    unsigned char plaintext[2][BLOCK];
    unsigned char ecb[2][BLOCK];
    unsigned char cbc[2][BLOCK];
    unsigned char cfb[2][BLOCK];

    unsigned char key[BLOCK] =
        "KEY12345";

    unsigned char iv[BLOCK] =
        "IV123456";

    char input[17];

    printf("Enter 16 character plaintext: ");
    scanf("%16s", input);

    memcpy(plaintext[0], input, 8);
    memcpy(plaintext[1], input + 8, 8);

    ECB(plaintext, ecb, key);
    CBC(plaintext, cbc, key, iv);
    CFB(plaintext, cfb, key, iv);

    printf("\nECB Ciphertext:\n");
    printBlocks(ecb);

    printf("\nCBC Ciphertext:\n");
    printBlocks(cbc);

    printf("\nCFB Ciphertext:\n");
    printBlocks(cfb);

    return 0;
}
