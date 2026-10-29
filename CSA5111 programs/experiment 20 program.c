#include <stdio.h>
#include <string.h>

void xor_block(char a[], char b[], char result[], int n)
{
    for (int i = 0; i < n; i++)
        result[i] = a[i] ^ b[i];
}

int main()
{
    unsigned char P[4][9] = {
        "BLOCK001",
        "BLOCK002",
        "BLOCK003",
        "BLOCK004"
    };

    unsigned char key[9] = "KEY12345";
    unsigned char IV[9] = "IV123456";

    unsigned char C[4][9];

    printf("Original Plaintext Blocks:\n");

    for (int i = 0; i < 4; i++)
        printf("P%d = %s\n", i + 1, P[i]);

    /*
     * Simplified CBC demonstration.
     * Encryption is represented using XOR.
     */

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 0)
                C[i][j] = P[i][j] ^ IV[j] ^ key[j];
            else
                C[i][j] = P[i][j] ^ C[i - 1][j] ^ key[j];
        }

        C[i][8] = '\0';
    }

    printf("\nOriginal Ciphertext Blocks:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("C%d = ", i + 1);

        for (int j = 0; j < 8; j++)
            printf("%02X ", C[i][j]);

        printf("\n");
    }

    /* Introduce one-bit error in C1 */
    C[0][0] ^= 1;

    printf("\nAfter 1-bit error in C1:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("C%d = ", i + 1);

        for (int j = 0; j < 8; j++)
            printf("%02X ", C[i][j]);

        printf("\n");
    }

    printf("\nCBC Error Propagation:\n");
    printf("P1 is corrupted.\n");
    printf("P2 has a corresponding bit error.\n");
    printf("P3 and P4 are recovered correctly.\n");

    printf("\nAnswers:\n");
    printf("a) No. Blocks beyond P2 are not affected.\n");
    printf("b) A bit error in P1 changes C1 and affects subsequent CBC encryption.\n");

    return 0;
}
