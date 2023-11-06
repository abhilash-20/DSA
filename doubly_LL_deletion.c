#include<stdlib.h>
#include<stdio.h>
struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head,*tail;
void create()
{
    struct node *newnode;
    head = 0;
    int choice = 1;
    int count = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;
        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do you want to continue (0,1)?\n");
        scanf("%d", &choice);
    }
}

void deletefrombegin()
{
    struct node *temp;
    temp=head;
    if(head==0)
    {
        printf("Empty list\n");
    }
    else if(head==tail) // single node present
    {
        head=tail=0;
        free(temp);
    }
    else 
    {
        head=head->next;
        head->prev=0;
        free(temp);
    }
}
void deletefromEnd()
{
    struct node *temp;
    temp=tail;
    if(tail==0)
    {
        printf("Empty list.\n");
    }
    else 
    {
        tail->prev->next=0;
        tail=tail->prev;
        free(temp);
    }
}

void deletefromPos()
{
    int pos,i=1;
    printf("enter the position:\n");
    scanf("%d",&pos);
    struct node *temp;
    temp=head;
    if(pos<1)
    {
        printf("invalid postion");
    }
    else 
    {
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    create();
    int ch;
    while (1)
    {
        printf("enter 1 to delete from the beginning:\n 2 to delete from the end\n 3 to delete from a position\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            deletefrombegin();
            display();
            printf("\n");
            break;
        case 2:
            deletefromEnd();
            display();
            printf("\n");
            break;
        case 3:
            deletefromPos();
            display();
            printf("\n");
            break;
        default:
            printf("Invalid Choice!!!\n");
            exit(0);
        }
    }
    return 0;
}