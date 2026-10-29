#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[200];
    char plain[200];
    int top, key;

    printf("Enter Cipher Text (uppercase letters only): ");
    scanf("%s", cipher);

    printf("Enter number of possible plaintexts to display: ");
    scanf("%d", &top);

    if(top > 26)
        top = 26;

    printf("\nPossible Plaintexts:\n");

    for(key = 0; key < top; key++)
    {
        int i;

        for(i = 0; cipher[i] != '\0'; i++)
        {
            if(isalpha(cipher[i]))
            {
                plain[i] = ((cipher[i]-'A'-key+26)%26)+'A';
            }
            else
            {
                plain[i] = cipher[i];
            }
        }

        plain[i]='\0';

        printf("\nKey %2d : %s", key, plain);
    }

    return 0;
}
