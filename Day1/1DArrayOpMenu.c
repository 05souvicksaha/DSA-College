
#include <stdio.h>
#include <stdlib.h>

    
    void display(int *arr, int n)
{
    int i;
    if (n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int **arr, int *n)
{
    int pos, value, i;
    int *temp;
    printf("Enter position for insertion: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);
    temp = (int *)realloc(*arr, (*n + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    *arr = temp;
    
    for (i = *n; i >= pos; i--)
    {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[pos - 1] = value;
    (*n)++;
    printf("Element inserted successfully\n");
}

void delete(int **arr, int *n)
{
    int pos, i;
    int *temp;
    if (*n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Enter position for deletion: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > *n)
    {
        printf("Invalid position\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
    {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*n)--;
    if (*n == 0)
    {
        free(*arr);
        *arr = NULL;
    }
    else
    {
        temp = (int *)realloc(*arr, (*n) * sizeof(int));
        if (temp != NULL)
        {
            *arr = temp;
        }
    }
    printf("Element deleted successfully\n");
}

int main()
{
    int *arr;
    int n, i, choice;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Display array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display(arr, n);
                break;
            case 2:
                insert(&arr, &n);
                break;
            case 3:
                delete(&arr, &n);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(arr);
    return 0;
}
