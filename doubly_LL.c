#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *newnode, *temp;
void create()
{
    int ch=1;
    head = 0;
    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the element:\n");
        scanf("%d ", &newnode->data);
        //printf("\n");
        newnode->next = 0;
        newnode->prev=0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("do you want to continue?(0,1)\n");
        scanf("%d", &ch);
    }
}

void display()
{
    temp = head;
    printf("The linked list is: ");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    create();
    display();
    return 0;
}