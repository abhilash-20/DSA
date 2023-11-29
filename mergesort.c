#include <stdlib.h>
#include <stdio.h>
#define N 5
void merge(int a[], int lb, int m, int ub)
{
    int i = lb;
    int j = m + 1;
    int k = lb;
    int b[N];
    while (i <= m && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if (i > m)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= m)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}
void Mergesort(int arr[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        Mergesort(arr, lb, mid);
        Mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}
void display(int a[])
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[N];
    printf("elements: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    Mergesort(a, 0, N - 1);
    display(a);
    return 0;
}