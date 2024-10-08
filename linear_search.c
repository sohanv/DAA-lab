#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

void linear_search_iter(int a[], int key)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(a[i] == key)
        {
            printf("Key found at %d index\n",i);
            return;
        }
    }
    printf("Key not found in array\n");
}

void linear_search_rec(int a[], int key, int i)
{
    if(i < SIZE)
    {
        if(a[i] == key)
            printf("Key found at index %d\n", i);
        else
            linear_search_rec(a, key, i+1);
    }
    else
        printf("Key not found in array\n");
}


int main()
{
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++)
        arr[i] = rand() % 500;
    for(int i = 0; i < SIZE; i++)
        printf("%d, ",arr[i]);
    int k;
    printf("\nEnter key to be searched for: ");
    scanf("%d",&k);

    clock_t iter_time, rec_time;
    iter_time = clock();
    linear_search_iter(arr, k);
    iter_time = clock() - iter_time;
    printf("Time taken for iterative method: %.8f \n",(float)iter_time / CLOCKS_PER_SEC);

    rec_time = clock();
    linear_search_rec(arr, k, 0);
    rec_time = clock() - rec_time;
    printf("Time taken for recursive method: %.8f \n",(float)rec_time / CLOCKS_PER_SEC);
}