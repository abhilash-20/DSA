#include <stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[], int lb, int ub)
{
    int pivot, start, end;
    pivot = a[lb];
    start = lb, end = ub;
    while (start < end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}

void quicksort(int a[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}

void display(int a[],int n)
{
    printf("The array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[50];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    display(a,n);
    return 0;
}