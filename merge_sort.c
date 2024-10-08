#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int merge(int arr[], int l, int m, int h)
{
    int temp[SIZE];
    int i = l;
    int j = m+1;
    int k = 0;

    while(i <= m && j <= h)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= m)
            temp[k++] = arr[i++];
    while(j <= h)
        temp[k++] = arr[j++];

    for(i = l, k = 0; i <= h; i++, k++)
        arr[i] = temp[k];
}

void merge_sort(int arr[], int l, int h)
{
    if(l < h)
    {
        int m = (l+h)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, h);
        merge(arr,l,m,h);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i = 0;i < n; i++)
        scanf("%d",&arr[i]);

    merge_sort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d, ",arr[i]);

    printf("\n");
}