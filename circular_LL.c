#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
} *tail;
void create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    tail = 0;
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail=newnode;
    }
}

void display()
{
    struct node *temp;
    temp = tail->next;
    if (tail == 0)
    {
        printf("empty list");
    }
    else
    {
        printf("The list is: \n");

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
         while (temp != tail->next);
        // printf("%d ",temp->data);
    }
}

int main()
{
    int x;
    printf("how many values do you want to enter?\n");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        create();
    }
    display();
    return 0;
}
