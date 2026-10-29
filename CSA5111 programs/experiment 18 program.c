#include <stdio.h>
#include <string.h>

int shifts[16] =
{
    1,1,2,2,2,2,2,2,
    1,2,2,2,2,2,2,1
};

void left_shift(char a[], int shift)
{
    char temp[29];

    for (int i = 0; i < 28; i++)
        temp[i] = a[(i + shift) % 28];

    temp[28] = '\0';

    strcpy(a, temp);
}

void generate_subkey(char C[], char D[], char key48[])
{
    /*
     * Simplified PC-2:
     * Take 24 bits from C
     * and 24 bits from D.
     */

    for (int i = 0; i < 24; i++)
        key48[i] = C[i];

    for (int i = 0; i < 24; i++)
        key48[i + 24] = D[i];

    key48[48] = '\0';
}

int main()
{
    char key[57];
    char C[29], D[29];
    char subkey[49];

    printf("Enter 56-bit DES key: ");
    scanf("%56s", key);

    for (int i = 0; i < 28; i++)
        C[i] = key[i];

    C[28] = '\0';

    for (int i = 0; i < 28; i++)
        D[i] = key[i + 28];

    D[28] = '\0';

    printf("\nDES Subkeys:\n");

    for (int round = 0; round < 16; round++)
    {
        left_shift(C, shifts[round]);
        left_shift(D, shifts[round]);

        generate_subkey(C, D, subkey);

        printf("K%d = %s\n", round + 1, subkey);
        printf("    First 24 bits  = ");

        for (int i = 0; i < 24; i++)
            printf("%c", subkey[i]);

        printf("\n    Second 24 bits = ");

        for (int i = 24; i < 48; i++)
            printf("%c", subkey[i]);

        printf("\n\n");
    }

    return 0;
}
