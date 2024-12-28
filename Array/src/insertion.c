#include <stdio.h>


int main()
{
    int array[3] = {};

    printf("Array before insertion: \n");

    for (int i = 0; i < 3; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    printf("Inserting elements. \n");

    printf("Array after insertion: \n");
    for (int i = 0; i < 3; i++ )
    {
        array[i] = i + 2;
        printf("array[%d] = %d \n", i, array[i]);
    }

    return 0;
}