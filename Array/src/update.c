#include <stdio.h>
#include <stdlib.h>


void update(char* array, int length, int index, char* new_value);
void print_array(char* array, int length);


int main()
{
    char array[] = "abc";
    int n = 3;

    printf("Array before update: \n");
    print_array(array, n);

    int index_to_update = 0;
    char new_value[] = "w";

    printf("Updating value at index %i to the value \"%c\" \n", index_to_update, new_value[0]);

    update(array, 3, index_to_update, new_value);

    printf("Array after update: \n");

    print_array(array, 3);

    return 0;
}

void update(char* array,int length, int index, char* new_value)
{
    if (index >= length)
    {
        printf("[Index error]: Cannot access index %d \n", index);
        exit(EXIT_FAILURE);
    }

    array[index] = new_value[0];
}

void print_array(char* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("array[%d] = %c \n", i, array[i]);
    }
}