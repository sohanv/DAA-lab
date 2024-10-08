#include <stdio.h>
#include <stdlib.h>
#define size 20

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertionSort(int arr[], int n)
{
    int i, j;
    for(i = 1; i < n; i++)
    {
        j = i;
        while(arr[j] < arr[j-1] && j>=1)
        {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

void main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array: ");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    insertionSort(arr, n);

    printf("Sorted array:");
    for(int i = 0; i < n; i++)
        printf("%d, ",arr[i]);
    printf("\n");
}