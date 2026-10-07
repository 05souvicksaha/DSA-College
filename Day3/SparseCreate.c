// Addition of two sparse matrices using shortcut representation
#include <stdio.h>

    void createSparse(int matrix[10][10], int rows, int cols, int sparse[100][3])
{
    int i, j, k = 1;
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(matrix[i][j] != 0)
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
    printf("\nShortcut Form:\n");
    printf("Row\tColumn\tValue\n");
    for(i = 0; i <= sparse[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }
}

int main()
{
    int matrix[10][10];
    int sparse[100][3];
    int rows, cols;
    int i, j;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("Enter the matrix elements:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    createSparse(matrix, rows, cols, sparse);
    displaySparse(sparse);
    return 0;
}