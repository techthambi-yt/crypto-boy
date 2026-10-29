#include <stdio.h>
#include <string.h>
#include <ctype.h>

char m[5][5];

void gen(char k[]) {
    int u[26] = {0}, i, r = 0, c = 0;
    u['J' - 'A'] = 1;
    for (i = 0; k[i]; i++) {
        char ch = toupper(k[i]);
        if (ch == 'J') ch = 'I';
        if (!u[ch - 'A']) {
            m[r][c++] = ch;
            u[ch - 'A'] = 1;
            if (c == 5) r++, c = 0;
        }
    }
    for (i = 0; i < 26; i++)
        if (!u[i]) {
            m[r][c++] = 'A' + i;
            if (c == 5) r++, c = 0;
        }
}

void pos(char ch, int *r, int *c) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (m[i][j] == ch) {
                *r = i;
                *c = j;
                return;
            }
}

int main() {
    char key[30], pt[100];
    int r1, c1, r2, c2;

    printf("Key: ");
    scanf("%s", key);
    gen(key);

    printf("Plaintext (even letters): ");
    scanf("%s", pt);

    printf("Ciphertext: ");
    for (int i = 0; pt[i]; i += 2) {
        pos(pt[i], &r1, &c1);
        pos(pt[i + 1], &r2, &c2);

        if (r1 == r2)
            printf("%c%c", m[r1][(c1 + 1) % 5], m[r2][(c2 + 1) % 5]);
        else if (c1 == c2)
            printf("%c%c", m[(r1 + 1) % 5][c1], m[(r2 + 1) % 5][c2]);
        else
            printf("%c%c", m[r1][c2], m[r2][c1]);
    }
    return 0;
}
