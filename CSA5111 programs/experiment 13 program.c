#include <stdio.h>

int modInverse(int a)
{
    a = a % 26;
    for(int i = 1; i < 26; i++)
    {
        if((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main()
{
    int P[2][2], C[2][2];
    int Pinv[2][2], Key[2][2];

    int det, detInv;

    printf("Enter Plaintext Matrix (numbers 0-25):\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&P[i][j]);

    printf("Enter Ciphertext Matrix (numbers 0-25):\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&C[i][j]);

    // Determinant
    det = (P[0][0]*P[1][1] - P[0][1]*P[1][0]) % 26;
    if(det < 0)
        det += 26;

    detInv = modInverse(det);

    if(detInv == -1)
    {
        printf("\nPlaintext matrix is not invertible.\n");
        return 0;
    }

    // Inverse of Plaintext Matrix
    Pinv[0][0] = ( P[1][1] * detInv) % 26;
    Pinv[0][1] = ((-P[0][1] + 26) * detInv) % 26;
    Pinv[1][0] = ((-P[1][0] + 26) * detInv) % 26;
    Pinv[1][1] = ( P[0][0] * detInv) % 26;

    // Recover Key = C × Pinv
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            Key[i][j]=0;

            for(int k=0;k<2;k++)
            {
                Key[i][j]+=C[i][k]*Pinv[k][j];
            }

            Key[i][j]%=26;
        }
    }

    printf("\nRecovered Key Matrix:\n");

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            printf("%3d ",Key[i][j]);
        printf("\n");
    }

    return 0;
}
