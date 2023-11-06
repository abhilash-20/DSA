#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty.");
    }
    else
    {
        printf("%d has been removed", front->data);
        printf("\n");
        front = front->next;
        free(temp);
    }
}

void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Top most element is: %d", front->data);
        printf("\n");
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The queue is: ");
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    enqueue(2);
    enqueue(8);
    enqueue(9);
    enqueue(7);
    enqueue(6);
    enqueue(12);
    display();
    peek();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}