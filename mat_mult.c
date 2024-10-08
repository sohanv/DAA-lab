#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m1, n1, m2, n2, i, j, k;
    printf("Enter m and n for first matrix: ");
    scanf("%d %d", &m1, &n1);
    printf("Enter m and n for second matrix: ");
    scanf("%d %d", &m2, &n2);
    if(n1 != m2)
    {        
        printf("These matrices cannot be multiplied!");
        exit(1);
    }      

    int a[m1][n1];
    int b[m2][n2];
    int c[m1][n2];
    printf("Enter elements for first matrix: ");
    for(i  = 0; i < m1; i++)
        for(j = 0; j < n1; j++)
            scanf("%d", &a[i][j]);
    printf("Enter elements for second matrix: ");
    for(i  = 0; i < m2; i++)
        for(j = 0; j < n2; j++)
            scanf("%d", &b[i][j]);

    for(i = 0; i < m1; i++)
        for(j = 0; j < n2; j++)
        {
            c[i][j] = 0;
            for(k = 0; k < n1; k++)
                c[i][j] += a[i][k]*b[k][j];
        }

    printf("Multiplied matrix:\n");
    for(i = 0; i < m1; i++)
    {
        for(j = 0; j < n2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}