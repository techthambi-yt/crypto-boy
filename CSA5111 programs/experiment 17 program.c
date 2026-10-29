#include <stdio.h>
#include <string.h>

int shifts[16] =
{
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1
};

void left_shift(char key[], int n)
{
    char temp[29];
    int i;

    for (i = 0; i < 28; i++)
        temp[i] = key[(i + n) % 28];

    temp[28] = '\0';

    strcpy(key, temp);
}

int main()
{
    char C[29], D[29];
    char key[57];

    printf("Enter 56-bit DES key: ");
    scanf("%56s", key);

    for (int i = 0; i < 28; i++)
        C[i] = key[i];

    C[28] = '\0';

    for (int i = 0; i < 28; i++)
        D[i] = key[i + 28];

    D[28] = '\0';

    printf("\nDES Decryption Key Schedule\n");

    for (int round = 0; round < 16; round++)
    {
        int index = 15 - round;

        left_shift(C, shifts[index]);
        left_shift(D, shifts[index]);

        printf("K%d = ", index + 1);

        for (int i = 0; i < 28; i++)
            printf("%c", C[i]);

        for (int i = 0; i < 28; i++)
            printf("%c", D[i]);

        printf("\n");
    }

    return 0;
}
