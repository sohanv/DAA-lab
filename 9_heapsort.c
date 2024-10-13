#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int largest = i;
    if(l < N && arr[l] > arr[largest])
        largest = l;

    if(r < N && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapsort(int arr[], int N)
{
    int i;
    for(i = N/2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for(i = N-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[SIZE];
    int i, n;
    printf("Enter number of elements initially: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i  = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapsort(arr, n);

    printf("The sorted array is: ");
    for(i = 0; i < n; i ++)
        printf("%d ", arr[i]);    

}