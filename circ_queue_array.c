#include<stdlib.h>
#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear=-1;
void enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front)
    {
        printf("Overflow");
    }
    else 
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("empty");
    }
    else if(front==rear)
    {
        printf("%d ",queue[front]);
        front=rear=-1;
    }
    else 
    {
        printf("%d ",queue[front]);
        front=(front+1)%N;
    }
}

void display()
{
    int i=front;
    while(i!=rear)
    {
        printf("%d ",queue[i]);
        i=(i+1)%N;
    }
    printf("%d ",queue[rear]);
}

int main()
{
    enqueue(5);
    printf("\n");
    enqueue(9);
    printf("\n");
    enqueue(8);
    printf("\n");
    enqueue(20);
    printf("\n");
    dequeue();
    printf("\n");
    display();
    printf("\n");
    dequeue();
    printf("\n");
    display();
    printf("\n");
    dequeue();
    printf("\n");
    display();
    printf("\n");
    return 0;
}