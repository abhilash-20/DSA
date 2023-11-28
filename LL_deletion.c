#include <stdlib.h>
#include <stdio.h>
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
int length()
{
    int c = 0;
    temp = head;
    while (temp != 0)
    {
        c++;
        temp = temp->next;
    }
    return c;
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
void delBegin()
{
    // struct node *temp;
    temp = head;
    if (head == 0)
    {
        printf("empty.\n");
    }
    else
    {
        head = head->next;
        free(temp);
    }
    display();
}

void delEnd()
{
    struct node *prev;
    temp = head;
    while (temp->next != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = 0;
    free(temp);
    display();
}
void delPos()
{
    int pos, i = 1;
    temp = head;
    struct node *nextnode;
    printf("enter pos: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > length())
    {
        printf("Invalid Position.\n");
    }
    else if (pos == 1)
    {
        delBegin();
    }
    else
    {
        while (i < pos - 1)
        {
            // prev=temp;
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
        display();
    }
}
int main()
{
    create();
    display();
    //printf("%d ", length());
     delBegin();
     delEnd();
     delPos();
    return 0;
}
