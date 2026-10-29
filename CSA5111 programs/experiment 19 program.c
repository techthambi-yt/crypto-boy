#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

void print_hex(unsigned char data[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%02X", data[i]);

    printf("\n");
}

int main()
{
    DES_cblock key1, key2, key3;
    DES_key_schedule ks1, ks2, ks3;

    DES_cblock iv;

    unsigned char plaintext[256];
    unsigned char ciphertext[256];

    int length;

    printf("Enter 24-byte 3DES key: ");
    scanf("%24s", key1);

    /*
     * For demonstration, derive three keys.
     */
    memcpy(key2, key1, 8);
    memcpy(key3, key1, 8);

    printf("Enter 8-byte IV: ");
    scanf("%8s", iv);

    printf("Enter plaintext: ");
    scanf(" %[^\n]", plaintext);

    length = strlen((char *)plaintext);

    /* Padding to 8-byte block */
    int padded_length = ((length + 7) / 8) * 8;

    for (int i = length; i < padded_length; i++)
        plaintext[i] = 0;

    DES_set_key_unchecked(&key1, &ks1);
    DES_set_key_unchecked(&key2, &ks2);
    DES_set_key_unchecked(&key3, &ks3);

    DES_ede3_cbc_encrypt(
        plaintext,
        ciphertext,
        padded_length,
        &ks1,
        &ks2,
        &ks3,
        &iv,
        DES_ENCRYPT
    );

    printf("\nCiphertext (Hex): ");
    print_hex(ciphertext, padded_length);

    printf("\nCBC Mode Information:\n");
    printf("Algorithm: 3DES\n");
    printf("Mode: CBC\n");

    printf("\nSecurity: 3DES\n");
    printf("Performance: DES is faster than 3DES.\n");

    return 0;
}
