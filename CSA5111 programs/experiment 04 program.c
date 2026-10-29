#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter key: ");
    scanf("%s", key);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            char k = toupper(key[j % strlen(key)]);
            text[i] = ((ch - 'A' + k - 'A') % 26) + 'A';
            j++;
        }
    }

    printf("Encrypted Text: %s\n", text);

    return 0;
}
