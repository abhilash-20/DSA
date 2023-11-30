#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
void create(struct node **head)
{
    int choice = 1;
    struct node *temp;
    while (choice)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of the element of the first list\n");
        scanf("%d", &newnode->value);
        newnode->next = NULL;
        if (*head == NULL)
        {
            *head = temp=newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue(0/1)");
        scanf("%d", &choice);
    }
}
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
struct node *merge(struct node *list1, struct node *list2)
{
    struct node *temp1 = list1;
    struct node *temp2 = list2;
    if (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->value < temp2->value)
        {
            temp1->next = merge(temp1->next, temp2);
            return temp1;
        }
        else
        {
            temp2->next = merge(temp1, temp2->next);
            return temp2;
        }
    }
    if (temp1 == NULL)
    {
        return temp2;
    }
    return temp1;
}
int counting(struct node **head)
{
    struct node *temp = *head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void sorting(struct node **head)
{
    int n = counting(&*head);
    for (int i = 0; i < n; i++)
    {
        struct node *temp = *head;
        struct node *next = temp->next;
        /* code */
        for (int j = 0; j < n - i - 1; j++)
        {
            if (temp->value > next->value)
            {
                int temp1 = temp->value;
                temp->value = next->value;
                next->value = temp1;
            }
            temp = temp->next;
            next = next->next;
        }
    }
}
int main()
{
    create(&head1);
    int choice = 1;
    create(&head2);
    printf("List 1: ");
    display(head1);
    printf("List 2: ");
    display(head2);
    sorting(&head1);
    sorting(&head2);
    struct node *head3 = merge(head1, head2);
    display(head3);
}