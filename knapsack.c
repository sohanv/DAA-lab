#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int max(int a, int b) { return (a>b)?a:b;}

int knapsack(int n, int m, int wt[], int p[])
{
int i, w;
int K[n+1][m+1];

for(i = 0; i <= n; i++)
{
for(w = 0; w <=m; w++)
{
count++;
if(w == 0 || i == 0)
K[i][w] = 0;
else if(wt[i-1] <= w)
K[i][w] = max(p[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
else
K[i][w] = K[i-1][w];
}
}
return K[n][m];
}

int main()
{
int n, m;
printf("Enter number of elements: ");
scanf("%d",&n);
int weights[n], profits[n];
printf("Enter weights and their corresponding profits: ");
for(int i = 0; i < n; i++)
scanf("%d %d", &weights[i], &profits[i]);
printf("Enter maximum weight: ");
scanf("%d",&m);

clock_t timer;
timer = clock();
int res = knapsack(n, m, weights, profits);
timer = clock() - timer;

printf("Maximum profit possible: %d\n", res);
printf("Time taken = %.8f\n",(float)timer/CLOCKS_PER_SEC);
printf("Count = %d\n", count);
}

