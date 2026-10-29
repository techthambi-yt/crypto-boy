#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int a) {
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1)
            return i;
    return -1;
}

int main() {
    int c1 = 'B' - 'A';   // 1
    int c2 = 'U' - 'A';   // 20
    int p1 = 'E' - 'A';   // 4
    int p2 = 'T' - 'A';   // 19

    int dp = (p1 - p2 + 26) % 26;
    int dc = (c1 - c2 + 26) % 26;

    for (int a = 1; a < 26; a++) {
        if (gcd(a, 26) != 1) continue;

        if ((a * dp) % 26 == dc) {
            int b = (c1 - a * p1) % 26;
            if (b < 0) b += 26;
            printf("Possible key: a = %d, b = %d\n", a, b);
        }
    }

    return 0;
}
