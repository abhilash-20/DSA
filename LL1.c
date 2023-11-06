#include <stdio.h>
#include <stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    int ch, c = 0;
    struct node *head, *newnode, *temp;
    head = 0;
    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of element:\n ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue? (0,1)\n");
        scanf("%d", &ch);
    }
    temp = head;
    printf("The linked list is :\n");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        c++;
    }
    printf("The number of elements: %d", c);
}