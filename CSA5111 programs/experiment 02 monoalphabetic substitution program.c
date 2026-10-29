#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], ciphertext[100];

    // Substitution key (26 unique letters)
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isupper(ch)) {
            ciphertext[i] = key[ch - 'A'];
        }
        else if (islower(ch)) {
            ciphertext[i] = tolower(key[ch - 'a']);
        }
        else {
            ciphertext[i] = ch;   // Keep spaces and symbols unchanged
        }
    }

    ciphertext[strlen(plaintext)] = '\0';

    printf("Encrypted text: %s", ciphertext);

    return 0;
}
