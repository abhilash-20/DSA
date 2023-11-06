// Insertion
#include <stdio.h>
#define MAX 50
int main()
{
    int a[MAX], size, pos, item;
    printf("enter the size of the array: ");
    scanf("%d", &size);
    if (size > MAX)
    {
        printf("overflow condition");
    }
    else
    {
        printf("enter the elements of the array\n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("enter the element you want to enter: ");
        scanf("%d", &item);
        printf("enter the position in which you want to enter the element: ");
        scanf("%d", &pos);
        for (int i = size - 1; i >= pos - 1; i--)// always insert from the end.
        {
            a[i + 1] = a[i];
        }
        a[pos - 1] = item;
        size++;
        printf("Updated array is:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d\t", a[i]);
        }
    }

    return 0;
}