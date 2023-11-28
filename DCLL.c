#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next, *prev;
} *head, *tail;
void create()
{
    struct node *newnode;
    head = 0;
    int ch;
    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("Do you want to continue?(0/1)");
        scanf("%d", &ch);
    }
}

void display()
{
    struct node *temp;
    temp = head;
    printf("The doubly circular linked list is: ");
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}
void insertatBegin()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to insert at the beginning: ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = tail = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode;
    }
    display();
}

void insertatEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to insert at the end: ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = tail = newnode;
        newnode->prev = head;
        newnode->next = head;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
    display();
}

void insertatPos()
{
    int pos, i = 1;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position where you want to insert the data: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid.\n");
    }
    else if (pos == 1)
    {
        insertatBegin();
    }
    else
    {
        temp = head;
        printf("Enter the data you want to enter: ");
        scanf("%d", &newnode->data);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
    display();
}

void delBegin()
{
    struct node *temp;
    temp = head;
    if (head == 0)
    {
        printf("Empty");
    }
    else if (head->next == head)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
    display();
}

void delEnd()
{
    struct node *temp;
    temp = tail;
    if (head == 0)
    {
        printf("Empty.\n");
    }
    else if (head->next == head)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
    display();
}

void delPos()
{
    int pos, i = 1;
    struct node *temp;
    printf("Enter the position from where you want to delete the data: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid,\n");
    }
    else if (pos == 1)
    {
        delBegin();
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp->next == head) // means it's the last node
        {
            tail = temp->prev;
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
    display();
}

int main()
{
    create();
    display();
    int ch, ch1, ch2;
    while (1)
    {
        printf("\nYou can perform the following operations: 1)Insertion \n2)Deletion.\n 3 to Exit.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter:\n 1 to Insert At the Beginning \n 2 to insert at the end 3 to insert at a position.\n 4 to exit.\n");
            scanf("%d", &ch1);
            switch (ch1)
            {
            case 1:
                insertatBegin();
                printf("\n");
                break;
            case 2:
                insertatEnd();
                printf("\n");
                break;
            case 3:
                insertatPos();
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
            }
            break;
        case 2:
            printf("Enter:\n 1 to Delete from the Beginning \n 2 to Delete from the End. \n 3 to Delete from a position.\n 4 to exit.\n");
            scanf("%d", &ch2);
            switch (ch2)
            {
            case 1:
                delBegin();
                printf("\n");
                break;
            case 2:
                delEnd();
                printf("\n");
                break;
            case 3:
                delPos();
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
    return 0;
}