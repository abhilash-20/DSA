#include <stdio.h>
int linearsrch(int arr[], int x)
{
    int flag = 0;
    for (int i = 0; i < 20; i++)
    {
        if (arr[i] == x)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    return flag;
}
int binarysrch(int a[],int y)
{
    int s=0,e=19,flag=0;
    int mid=(s+e)/2;
    while(s<=e)
    {
        if(a[mid]==y)
        {
            return mid;
        }
        else if(y>a[mid])
        {
            s=mid+1;
        }
        else 
        {
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return -1;
}
int main()
{
    int a[50], key;
    printf("enter the elements of the array: \n");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the element you want to search:\t");
    scanf("%d",&key);
    int check = linearsrch(a, key);
    if (check == 1)
    {
        printf("found(using linear search)\n");
    }
    else
    {
        printf("not found(using linear search).\n");
    }
    int chk=binarysrch(a,key);
    if(chk!=-1)
    {
        printf("Found (using binary search).\n");
    }
    else 
    {
        printf("Not found(using binary search).\n");
    }
    return 0;
}
