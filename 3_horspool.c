#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
int table[MAX];

void shiftTable(char P[])
{
    int i, m;
    m = strlen(P);
    for(i = 0; i < MAX; i++)
        table[i] = m;
    for(i = 0; i < m-2; i++)
        table[P[i]] = m-1-i;
}

int horspool(char P[], char T[])
{
    shiftTable(P);
    int n, m, k, i;
    n = strlen(T);
    m = strlen(P);
    i = m-1;

    while(i <= n-1)
    {
        k = 0;
        while((k < m) && (P[m-1-k]==T[i-k]))
            k++;
        
        if(k == m)
            return i-m+1;
        else
            i += table[T[i]];
    }
    return -1;
}

int main()
{
    char T[100], P[25];
    printf("Enter text: ");
    scanf("%s", T);
    printf("Enter pattern: ");
    scanf("%s", P);

    int res = horspool(P, T);
    if(res == -1)
        printf("Pattern not found!");
    else
        printf("Pattern found at position %d",res);
}