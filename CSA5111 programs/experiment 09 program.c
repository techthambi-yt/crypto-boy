#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key[5][5];

void generateKey(char *k) {
    int used[26] = {0}, i, j = 0;
    char temp[25];

    used['J' - 'A'] = 1;

    for (i = 0; k[i]; i++) {
        char c = toupper(k[i]);
        if (c == 'J') c = 'I';
        if (c >= 'A' && c <= 'Z' && !used[c - 'A']) {
            used[c - 'A'] = 1;
            temp[j++] = c;
        }
    }

    for (i = 0; i < 26; i++)
        if (!used[i])
            temp[j++] = 'A' + i;

    j = 0;
    for (i = 0; i < 5; i++)
        for (int k = 0; k < 5; k++)
            key[i][k] = temp[j++];
}

void findPos(char c, int *r, int *c1) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (key[i][j] == c) {
                *r = i;
                *c1 = j;
            }
}

void decrypt(char text[]) {
    int i, r1, c1, r2, c2;

    printf("Plaintext: ");
    for (i = 0; text[i]; i += 2) {
        findPos(text[i], &r1, &c1);
        findPos(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c", key[r1][(c1 + 4) % 5], key[r2][(c2 + 4) % 5]);
        } else if (c1 == c2) {
            printf("%c%c", key[(r1 + 4) % 5][c1], key[(r2 + 4) % 5][c2]);
        } else {
            printf("%c%c", key[r1][c2], key[r2][c1]);
        }
    }
}

int main() {
    char keyword[50], text[500];

    printf("Enter keyword: ");
    scanf("%s", keyword);

    printf("Enter ciphertext: ");
    scanf("%s", text);

    generateKey(keyword);
    decrypt(text);

    return 0;
}
