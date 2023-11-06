#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;
void insertBegin()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to insert at the beginning:\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertPos(int c)
{
    int pos, i = 1;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to enter:\n");
    scanf("%d", &newnode->data);
    printf("Enter the position where you want to enter the element:\n");
    scanf("%d", &pos);
    if (pos <= 0 || pos > c)
    {
        printf("Invalid\n");
    }
    else
    {
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insertEnd()
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to enter:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void display()
{
    temp = head;
    printf("The Linked list is : \n");
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int ch1 = 1;
    head = 0;
    int c, ch2;
    while (ch1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("Enter the data you want to enter: ");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue(1/0)?\n");
        scanf("%d", &ch1);
    }
    temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        c++;
    }
    display();
    printf("\n");
    while (1)
    {
        printf("The following opertions can be performed\n");
        printf("PRESS:\n");
        printf("Press\n 1 to insert at the beginning \n 2 to insert at any position \n 3 to insert at the end\n 4 to exit\n");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
            insertBegin();
            display();
            printf("\n");
            break;
        case 2:
            insertPos(c);
            display();
            printf("\n");
            break;
        case 3:
            insertEnd();
            display();
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong input");
            break;
        }
    }
    return 0;
}