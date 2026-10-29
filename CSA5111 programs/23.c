```c
#include <stdio.h>
#include <string.h>

int P10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int P8[]  = {6, 3, 7, 4, 8, 5, 10, 9};
int IP[]  = {2, 6, 3, 1, 4, 8, 5, 7};
int IP1[] = {4, 1, 3, 5, 7, 2, 8, 6};
int EP[]  = {4, 1, 2, 3, 2, 3, 4, 1};
int P4[]  = {2, 4, 3, 1};

int S0[4][4] = {
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}
};

int S1[4][4] = {
    {0, 1, 2, 3},
    {2, 0, 1, 3},
    {3, 0, 1, 0},
    {2, 1, 0, 3}
};

void permute(int *in, int *out, int *p, int n) {
    for (int i = 0; i < n; i++)
        out[i] = in[p[i] - 1];
}

void leftShift(int *key, int n) {
    int temp = key[0];
    for (int i = 0; i < n - 1; i++)
        key[i] = key[i + 1];
    key[n - 1] = temp;
}

void generateKeys(int *key, int *k1, int *k2) {
    int p10[10], left[5], right[5], temp[10];

    permute(key, p10, P10, 10);

    for (int i = 0; i < 5; i++) {
        left[i] = p10[i];
        right[i] = p10[i + 5];
    }

    leftShift(left, 5);
    leftShift(right, 5);

    for (int i = 0; i < 5; i++) {
        temp[i] = left[i];
        temp[i + 5] = right[i];
    }

    permute(temp, k1, P8, 8);

    leftShift(left, 5);
    leftShift(left, 5);
    leftShift(right, 5);
    leftShift(right, 5);

    for (int i = 0; i < 5; i++) {
        temp[i] = left[i];
        temp[i + 5] = right[i];
    }

    permute(temp, k2, P8, 8);
}

void xorBits(int *a, int *b, int *out, int n) {
    for (int i = 0; i < n; i++)
        out[i] = a[i] ^ b[i];
}

void fk(int *bits, int *key) {
    int left[4], right[4], expanded[8], x[8];
    int sInput[4], sOutput[4], p4[4];

    for (int i = 0; i < 4; i++) {
        left[i] = bits[i];
        right[i] = bits[i + 4];
    }

    permute(right, expanded, EP, 8);
    xorBits(expanded, key, x, 8);

    sInput[0] = x[0];
    sInput[1] = x[3];
    sInput[2] = x[1];
    sInput[3] = x[2];

    int row = x[0] * 2 + x[3];
    int col = x[1] * 2 + x[2];
    int val = S0[row][col];

    sOutput[0] = (val >> 1) & 1;
    sOutput[1] = val & 1;

    row = x[4] * 2 + x[7];
    col = x[5] * 2 + x[6];
    val = S1[row][col];

    sOutput[2] = (val >> 1) & 1;
    sOutput[3] = val & 1;

    permute(sOutput, p4, P4, 4);
    xorBits(left, p4, bits, 4);

    for (int i = 0; i < 4; i++) {
        bits[i] = bits[i];
        bits[i + 4] = right[i];
    }
}

void swapHalves(int *bits) {
    for (int i = 0; i < 4; i++) {
        int temp = bits[i];
        bits[i] = bits[i + 4];
        bits[i + 4] = temp;
    }
}

void sdes(int input, int *k1, int *k2, int decrypt, int *output) {
    int bits[8], temp[8], result[8];

    for (int i = 0; i < 8; i++)
        bits[i] = (input >> (7 - i)) & 1;

    permute(bits, temp, IP, 8);

    for (int i = 0; i < 8; i++)
        bits[i] = temp[i];

    fk(bits, decrypt ? k2 : k1);
    swapHalves(bits);
    fk(bits, decrypt ? k1 : k2);

    permute(bits, result, IP1, 8);

    *output = 0;
    for (int i = 0; i < 8; i++)
        *output = (*output << 1) | result[i];
}

void ctrMode(unsigned char *data, int len, int *k1, int *k2) {
    unsigned char counter = 0;
    int stream;

    for (int i = 0; i < len; i++) {
        sdes(counter++, k1, k2, 0, &stream);
        data[i] ^= stream;
    }
}

int main() {
    int key[10] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1};
    int k1[8], k2[8];

    unsigned char plaintext[] = {0x01, 0x02, 0x04};
    unsigned char ciphertext[3];

    generateKeys(key, k1, k2);

    printf("Plaintext : ");
    for (int i = 0; i < 3; i++)
        printf("%08d ", plaintext[i]);
    printf("\n");

    memcpy(ciphertext, plaintext, 3);
    ctrMode(ciphertext, 3, k1, k2);

    printf("Ciphertext: ");
    for (int i = 0; i < 3; i++) {
        for (int j = 7; j >= 0; j--)
            printf("%d", (ciphertext[i] >> j) & 1);
        printf(" ");
    }
    printf("\n");

    ctrMode(ciphertext, 3, k1, k2);

    printf("Decrypted : ");
    for (int i = 0; i < 3; i++) {
        for (int j = 7; j >= 0; j--)
            printf("%d", (ciphertext[i] >> j) & 1);
        printf(" ");
    }
    printf("\n");

    return 0;
}
```
