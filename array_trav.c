// traversion
#include <stdio.h>
int main()
{
    int a[50], size;
    printf("enter the size of the array: ");
    scanf("%d", &size);
    printf("enter the elements of the array");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the elements are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}