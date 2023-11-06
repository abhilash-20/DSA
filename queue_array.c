#include <stdlib.h>
#include <stdio.h>
#define N 5
int queue[N];
int front = -1, rear = -1;
void enqueue(int data)
{
    if (rear == (N - 1))
    {
        printf("Oveflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[front] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow Condition");
    }
    else if (front == rear)
    {
        printf("The popped element is %d",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("The popped element is: %d", queue[front]);
        printf("\n");
        front++;
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("empty");
    }
    else
    {
        printf("%d ", queue[front]);
    }
    printf("\n");
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("empty");
    }
    else
    {
        printf("The Queue is: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    enqueue(2);
    enqueue(9);
    enqueue(8);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    peek();
    display();
}
