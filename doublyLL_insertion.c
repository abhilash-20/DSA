#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *prev, *next;
};
struct node *head, *tail;

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

void insertAtbegin()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to enter:\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertAtend()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertAtpos()
{
    struct node *newnode, *temp;
    temp = head;
    int pos, i = 1;
    printf("enter the position where you want to enter the data\n");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("invalid position\n");
    }
    else if (pos == 1)
    {
        insertAtbegin();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data: ");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
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
        printf("enter 1 to insert at beginning:\n 2 to insert at the end\n 3 to insert at a position\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtbegin();
            display();
            printf("\n");
            break;
        case 2:
            insertAtend();
            display();
            printf("\n");
            break;
        case 3:
            insertAtpos();
            display();
            printf("\n");
        default:
            printf("Invalid Choice!!!\n");
            exit(0);
        }
    }
    return 0;
}