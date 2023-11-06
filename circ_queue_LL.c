#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
} *front = 0, *rear = 0;
void enqueue(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (rear == 0)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Empty\n");
    }
    else if(front==rear)
    {
        front=rear=0;
        free(temp);
    }
    else
    {
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if(front==0 && rear==0)
    {
        printf("Empty.\n");
    }
    else 
    {
        while(temp->next!=front)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}

int main()
{
    enqueue(3);
    enqueue(6);
    enqueue(9);
    enqueue(12);
    enqueue(15);
   // display();
    dequeue();
    dequeue();
    display();
}