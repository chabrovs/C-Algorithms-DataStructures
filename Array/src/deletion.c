#include <stdio.h>


int main()
{
    int array[] = {1, 3, 5};
    int n = 3;

    printf("Array before deletion:\n");
    
    for (int i = 0; i < 3; i++)
    {
        printf("array[%d] = %d \n", i, array[i]);
    }
    
    int index_to_remove = 2;

    if (index_to_remove >= n){
        printf("[Index error]: Trying to remove from index that does not exist!\n");
        return 1;
    }

    printf("Deleting element with index %d: \n", index_to_remove);

    n -= 1;

    for (int i=index_to_remove; i < n; i++)
    {
        array[i] = array[i+1];
    }
    

    printf("Array after deletion: \n");

    for (int i = 0; i < n; i++)
    {
        printf("array[%d] = %d \n", i, array[i]);
    }

    return 0;
}