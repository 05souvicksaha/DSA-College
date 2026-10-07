
#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int *arr;
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed");
        return 0;
    }
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The array elements are:\n");
    display(arr, n);
    free(arr);
    return 0;
}
