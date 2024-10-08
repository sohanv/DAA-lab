#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int main()
{
    int arr[SIZE];
    int i;
    for(i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % (101);
        printf("%d, ", arr[i]);
    }
    int max = -1;

    for(i = 0; i < SIZE; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    printf("\nMax element is: %d\n",max);
}