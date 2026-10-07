
#include <stdio.h>
#include <stdlib.h>
void display(int **arr, int r, int c)
{
    int i, j;
    printf("The 2D array is:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int **arr;
    int r, c, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    arr = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int));
    }
    printf("Enter the elements:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    display(arr, r, c);
    for (i = 0; i < r; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
