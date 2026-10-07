
#include <stdio.h>

void insert(int arr[], int *n, int pos, int value)
{
    int i;

    for (i = *n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;

    (*n)++;
}

void display(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[100];
    int n, i, pos, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    insert(arr, &n, pos, value);

    printf("Array after insertion:\n");

    display(arr, n);

    return 0;
}
