#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int key[2][2]={{9,4},{5,7}};
    int invKey[2][2]={{5,12},{15,25}};

    char plaintext[200], temp[200];
    char cipher[200], decrypt[200];

    int i,j=0;

    printf("Enter Plaintext:\n");
    fgets(plaintext,sizeof(plaintext),stdin);

    // Remove spaces and convert to uppercase
    for(i=0;plaintext[i]!='\0';i++)
    {
        if(isalpha(plaintext[i]))
        {
            temp[j++]=toupper(plaintext[i]);
        }
    }

    temp[j]='\0';

    if(j%2!=0)
    {
        temp[j]='X';
        temp[j+1]='\0';
        j++;
    }

    printf("\nProcessed Plaintext : %s\n",temp);

    // Encryption
    for(i=0;i<j;i+=2)
    {
        int p1=temp[i]-'A';
        int p2=temp[i+1]-'A';

        cipher[i]=((key[0][0]*p1+key[0][1]*p2)%26)+'A';
        cipher[i+1]=((key[1][0]*p1+key[1][1]*p2)%26)+'A';
    }

    cipher[j]='\0';

    printf("\nCipher Text : %s\n",cipher);

    // Decryption
    for(i=0;i<j;i+=2)
    {
        int c1=cipher[i]-'A';
        int c2=cipher[i+1]-'A';

        decrypt[i]=((invKey[0][0]*c1+invKey[0][1]*c2)%26)+'A';
        decrypt[i+1]=((invKey[1][0]*c1+invKey[1][1]*c2)%26)+'A';
    }

    decrypt[j]='\0';

    printf("\nDecrypted Text : %s\n",decrypt);

    return 0;
}
