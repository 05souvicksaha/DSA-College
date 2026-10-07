
#include <stdio.h>

void createSparse(int matrix[10][10], int rows, int cols, int sparse[100][3])
{
    int i, j, k = 1;
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;
}

void displaySparse(int sparse[100][3])
{
    int i;
    printf("\nSparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i <= sparse[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }
}

void addSparse(int a[100][3], int b[100][3], int result[100][3])
{
    int i = 1, j = 1, k = 1;
    result[0][0] = a[0][0];
    result[0][1] = a[0][1];
    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1])
        {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            if (result[k][2] != 0)
                k++;
            i++;
            j++;
        }
        else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
            k++;
        }
        else
        {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++;
            k++;
        }
    }

    while (i <= a[0][2])
    {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++;
        k++;
    }
    while (j <= b[0][2])
    {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++;
        k++;
    }
    result[0][2] = k - 1;
}

int main()
{
    int a[10][10], b[10][10];
    int sparseA[100][3];
    int sparseB[100][3];
    int result[100][3];
    int rows, cols;
    int i, j;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("\nEnter first matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter second matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    createSparse(a, rows, cols, sparseA);
    createSparse(b, rows, cols, sparseB);
    printf("\nFirst Sparse Matrix:");
    displaySparse(sparseA);
    printf("\nSecond Sparse Matrix:");
    displaySparse(sparseB);
    addSparse(sparseA, sparseB, result);
    printf("\nResult after Addition:");
    displaySparse(result);
    return 0;
}
