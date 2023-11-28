#include <stdio.h>
#include<stdlib.h>
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
            *head =  newnode;
            temp =newnode;
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
 void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
 }
struct node* merge(struct node * list1, struct node * list2){
    struct node* temp1=list1;
    struct node* temp2=list2;
    if(temp1!=NULL&&temp2!=NULL){
        if(temp1->value<temp2->value){
            temp1->next=merge(temp1->next,temp2);
            return temp1;
        }
        else{
            temp2->next=merge(temp1,temp2->next);
            return temp2;
        }
    }
    if(temp1==NULL){
        return temp2;
    }
    return temp1;
}
int main()
{
    create(&head1);
    int choice=1;
    create(&head2);
    printf("List 1: ");
    display(head1);
    printf("List 2: ");
    display(head2);
    struct node* head3=merge(head1,head2);
    display(head3);
}