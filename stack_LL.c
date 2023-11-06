#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top = 0;
void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    //temp=top;
    if (top == 0)
    {
        printf("Empty Stack.\n");
    }
    else
    {
        printf("%d has been popped.", top->data);
        printf("\n");
        top = top->link;
        free(temp);
    }
}

void peek()
{
    if (top == 0)
    {
        printf("empty stack");
    }
    else
    {
        printf("Top element is %d", top->data);
        printf("\n");
    }
}

void display()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("empty stack.");
    }
    else
    {
        printf("Stack is:\n");
        while (temp != 0)
        {
            printf("%d \n", temp->data);
            temp = temp->link;
        }
    }
}

int main()
{
    push(2);
    push(3);
    push(10);
    push(8);
    display();
    //peek();
    pop();
    pop();
    pop();
   // peek();
    display();
    return 0;
}