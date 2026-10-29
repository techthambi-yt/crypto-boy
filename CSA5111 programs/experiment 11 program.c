#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double log2Keys = 0.0;

    // Calculate log2(25!)
    for(i = 1; i <= 25; i++)
    {
        log2Keys += log2((double)i);
    }

    printf("=====================================\n");
    printf("   Playfair Cipher Key Space\n");
    printf("=====================================\n\n");

    printf("Ignoring equivalent keys:\n");
    printf("Total possible keys = 25!\n");
    printf("Approximate value = 1.55 x 10^25\n");
    printf("Approximate power of 2 = 2^%.2f\n\n", log2Keys);

    printf("Considering equivalent keys:\n");
    printf("Effectively unique keys ≈ 25! / 2\n");

    log2Keys = log2Keys - 1;

    printf("Approximate power of 2 = 2^%.2f\n", log2Keys);

    return 0;
}
