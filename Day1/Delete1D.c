
#include <stdio.h>

void delete(int arr[], int *n, int pos)
{
    int i;
    for (i = pos - 1; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
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
    int n, i, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    delete(arr, &n, pos);

    printf("Array after deletion:\n");
    display(arr, n);
    return 0;
}
