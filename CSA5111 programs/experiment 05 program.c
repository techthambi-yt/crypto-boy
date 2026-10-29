#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    printf("Ciphertext: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            int p = ch - 'A';
            int c = (a * p + b) % 26;
            printf("%c", c + 'A');
        }
    }

    return 0;
}
