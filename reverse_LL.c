#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
} *head, *temp, *newnode;
void create()
{
    int ch = 1;
    head = 0;
    // struct node* newnode;
    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue?(0/1)");
        scanf("%d", &ch);
    }
}

void display()
{
    // struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverse()
{
    struct node *prev,*curr,*nextnode;
    prev=0;
    curr=nextnode=head;
    while(nextnode!=0)
    {
        nextnode=nextnode->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    head=prev;
    display();
}
int main()
{
    create();
    display();
    printf("reverse: ");
    reverse();
    return 0;
}