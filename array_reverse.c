// REVERSE AN ARRAY
#include <stdio.h>
#define MAX 50
void array_reverse(int a[], int s, int e)
{
    int temp = 0;
    while (s < e)
    {
        temp = a[s];
        a[s] = a[e];
        a[e] = temp;
        s++;
        e--;
    }
}

void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX], n;
    printf("enter the size of array: \n");
    scanf("%d", &n);
    if (n > MAX)
    {
        printf("Overflow Condition!!\n");
    }
    else
    {
        printf("enter the elements of the array: \n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Original array:\n");
        display(arr, n);
        printf("Updated array:\n");
        array_reverse(arr, 0, n - 1);
        display(arr, n);
        return 0;
    }
}