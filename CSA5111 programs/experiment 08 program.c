#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plain[100];
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i;

    printf("Enter plaintext: ");
    fgets(plain, sizeof(plain), stdin);

    printf("Ciphertext: ");
    for (i = 0; plain[i] != '\0'; i++) {
        if (isalpha(plain[i])) {
            char ch = toupper(plain[i]);
            printf("%c", cipher[ch - 'A']);
        } else {
            printf("%c", plain[i]);
        }
    }

    return 0;
}
