//Deletion
#include <stdio.h>
#define MAX 50
int main()
{
    int a[MAX], size, item, pos;
    printf("enter the size of the array:\n");
    scanf("%d", &size);
    if (size > MAX)
    {
        printf("Overflow condition!!\n");
    }
    else
    {
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < size; i++)
        {  
            scanf("%d", &a[i]);
        }
        printf("enter the position from where you want to delete an element");
        scanf("%d", &pos);
        if (pos <= 0 || pos > size)
        {
            printf("Invalid position entered");
        }
        else
        {
            item = a[pos - 1];
            for (int i = pos - 1; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }
            size--;
            printf("Popped off element is: %d\n", item);
            printf("Updated array:\n");
            for (int i = 0; i < size; i++)
            {
                printf("%d\t", a[i]);
            }
        }
    }
    return 0;
}