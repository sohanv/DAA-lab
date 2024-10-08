#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

bool flag = 0;
unsigned long long int operationCount = 0;

void PrintSubsetSum(int i, int n, int set[], int targetSum, int subset[], int subsetSize) {
    operationCount++;

    if (targetSum == 0) {
        flag = 1;
        printf("[ ");
        for (int j = 0; j < subsetSize; j++) {
            printf("%d ", subset[j]);
        }
        printf("]");
        return;
    }

    if (i == n) {
        return;
    }

    PrintSubsetSum(i + 1, n, set, targetSum, subset, subsetSize);

    if (set[i] <= targetSum) {
        subset[subsetSize] = set[i];
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset, subsetSize + 1);
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int n, sum;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the target sum: ");
    scanf("%d", &sum);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
    	scanf("%d", &arr[i]);
    
    int subset[MAX_SIZE];
    int subsetSize = 0;
    
    start = clock();
    PrintSubsetSum(0, n, arr, sum, subset, subsetSize);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.8f seconds\n", cpu_time_used);
    printf("Number of operations: %llu\n", operationCount);
    printf("\n");
    flag = 0;
    operationCount = 0;

    return 0;
}

