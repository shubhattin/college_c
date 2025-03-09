#include <stdio.h>

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int i, j;

    // Printing the array
    printf("Array A\n");
    for (i = 0; i < 5; i++)
        printf("%d, ", A[i]);
    printf("\n");

    int index=3;

    void * base = (void *)A;
    printf("Base address of array A is %p\n", base);
    void * address = (void *)&A[index];
    printf("Base address of array A is %p\n", address);
    printf("Difference in Adress is %p\n",  address - base);

    return 0;
}
