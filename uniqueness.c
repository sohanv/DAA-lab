#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

int partition(int arr[], int l, int r)
{
int pivot = arr[l];
int i = l;
int j = r;

while(i < j)
{
while(i <= r && pivot >= arr[i])
{
i++;
count++;
}
while(j >= l && pivot < arr[j])
{
count++;
j--;
}
if(i < j)
swap(&arr[i], &arr[j]);
else
{
swap(&arr[j], &arr[l]);
return j;
}
}
}

void quickSort(int arr[], int l, int r)
{
if(l < r)
{
int S = partition(arr, l, r);
quickSort(arr,l,S-1);
quickSort(arr,S+1,r);
}
}

int unique(int arr[], int n)
{
for(int i = 0; i < n-1; i++)
{
count++;
if(arr[i] == arr[i+1])
return 0;
}
return 1;
}

void main()
{
int n;
printf("Enter number of elements: ");
scanf("%d",&n);
int *arr = (int *)malloc(n*sizeof(int));
int i;
printf("Enter elements: ");
for(i = 0; i < n; i++)
scanf("%d",&arr[i]);

clock_t timer;
timer = clock();
quickSort(arr, 0, n-1);

int result = unique(arr, n);
timer = clock() - timer;
if(result)
printf("Array has unique elements!");
else
printf("Array has duplicate elements!");

printf("\nTime taken: %.8f", (float)timer/CLOCKS_PER_SEC);
printf("\nCount (sorting + uniqueness): %d", count);

}