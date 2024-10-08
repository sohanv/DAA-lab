#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right)
{
    int i, j, pivot;
    pivot = arr[left];
    i = left+1;
    j = right;
    while(1)
    {
        while(pivot >= arr[i] && i <= right)
            i++;
        while(pivot < arr[j] && j >= left)
            j--;
        
        if(i < j)
            swap(&arr[i], &arr[j]);
        else
        {
            swap(&arr[left], &arr[j]);
            return j;
        }
    }
}

void quicksort(int arr[], int left, int right)
{
    int S;
    if(left < right)
    {
        S = partition(arr, left, right);
        quicksort(arr, left, S-1);
        quicksort(arr, S+1,right);
    }

}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
        
    quicksort(arr, 0, n-1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");

}