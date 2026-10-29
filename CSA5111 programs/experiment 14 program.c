#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100], cipher[100], decrypt[100];
    int key[100];
    int i, len = 0;

    printf("Enter Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove spaces and convert to uppercase
    char temp[100];
    for(i = 0; plaintext[i] != '\0'; i++)
    {
        if(isalpha(plaintext[i]))
            temp[len++] = toupper(plaintext[i]);
    }
    temp[len] = '\0';

    printf("Enter %d key values:\n", len);

    for(i = 0; i < len; i++)
        scanf("%d", &key[i]);

    // Encryption
    for(i = 0; i < len; i++)
    {
        cipher[i] = ((temp[i] - 'A' + key[i]) % 26) + 'A';
    }
    cipher[len] = '\0';

    printf("\nCipher Text : %s\n", cipher);

    // Decryption
    for(i = 0; i < len; i++)
    {
        decrypt[i] = ((cipher[i] - 'A' - key[i] + 26) % 26) + 'A';
    }
    decrypt[len] = '\0';

    printf("Decrypted Text : %s\n", decrypt);

    return 0;
}
