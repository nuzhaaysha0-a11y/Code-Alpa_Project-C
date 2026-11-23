#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], sum[10][10];
    int mul[10][10], trans[10][10];
    int r, c, i, j, k;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &r, &c);

    printf("Enter elements of first matrix:\n");
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            scanf("%d", &b[i][j]);

    // Matrix Addition
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("\nMatrix Addition:\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    // Matrix Multiplication
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
        {
            mul[i][j] = 0;
            for(k=0; k<c; k++)
                mul[i][j] += a[i][k] * b[k][j];
        }

    printf("\nMatrix Multiplication:\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d ", mul[i][j]);
        printf("\n");
    }

    // Transpose of First Matrix
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            trans[j][i] = a[i][j];

    printf("\nTranspose of First Matrix:\n");
    for(i=0; i<c; i++)
    {
        for(j=0; j<r; j++)
            printf("%d ", trans[i][j]);
        printf("\n");
    }

    return 0;
}
