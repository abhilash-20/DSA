#include<stdio.h>
#define V 4
void display(int graph[V][V])
{
    printf("The adjacency matrix representation of Graph is:\n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int g[V][V]={
        {1,0,0,1},
        {0,1,0,1},
        {0,0,1,1},
        {1,1,0,1}
    };
    display(g);
    return 0;
}