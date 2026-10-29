#include <stdio.h>

int main()
{
    int state = 1600;
    int block = 1024;
    int lane = 64;

    int capacity = state - block;
    int rate_lanes = block / lane;
    int capacity_lanes = capacity / lane;

    printf("State size = %d bits\n", state);
    printf("Block size = %d bits\n", block);
    printf("Rate lanes = %d\n", rate_lanes);
    printf("Capacity = %d bits\n", capacity);
    printf("Capacity lanes = %d\n", capacity_lanes);

    printf("\nInitially capacity lanes are zero.\n");
    printf("Permutation is ignored.\n");
    printf("Therefore they remain zero.\n");
    printf("Time required for all capacity lanes to become nonzero: NEVER\n");

    return 0;
}
