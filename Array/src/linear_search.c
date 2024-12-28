#include <stdio.h>


int main()
{
    int array[] = {1, 3, 5};
    int n = 3;

    printf("Array before search: \n");

    for (int i = 0; i < n; i++)
    {
        printf("array[%d] = %d \n", i, array[i]);
    }

    char searched_value = 5;

    printf("Searching for value %d \n", searched_value);

    for (int i = 0; i < n; i++)
    {
        if (array[i] == searched_value)
        {
            printf("Value %d was found at index %d \n", searched_value, i);
            return 0;
        }
    }

    printf("Value %d was not found \n", searched_value);

    return 0;
}