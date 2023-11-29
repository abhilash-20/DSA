#include<stdio.h>
#define N 5
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble(int a[])
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1-i;j++)
        {
            if(a[j]>a[j+1]) // for descending, make a[j]<a[j+1]
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
void display(int a[])
{
    for(int i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertionsort(int a[])
{
    int temp,j;
    for(int i=1;i<N;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]<temp)// descending order. for ascending order just make a[j]>temp
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

void selectionsort(int a[])
{
    int i,j,min;
    for(i=0;i<N;i++)
    {
        min=i;
        for(j=i+1;j<N;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            if(min!=i)
            {
                swap(&a[i],&a[min]);
            }
        }
    }
}
int main()
{
    int arr[N];
    printf("Enter the elements of the array: ");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    //bubble sort
    bubble(arr);
    display(arr);
    //insertion sort
    printf("Insertion sort descending order: ");
    insertionsort(arr);
    display(arr);
    //selection sort
    selectionsort(arr);
    display(arr);
    return 0;
}