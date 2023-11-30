#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*tail;

void create()
{
    struct node *newnode;
    tail=0;
    int ch=1;
    while(ch)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Data: ");
        scanf("%d",&newnode->data);
        if(tail==0)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("0/1? ");
        scanf("%d",&ch);
    }
}
void delend()
{
    struct node *curr,*prev;
    curr=tail->next;
    if(tail==0)
    {
        printf("Empty.");
    }
    else if(curr->next==curr)
    {
        tail=0;
        free(curr);
    }
    else
    {
        while(curr->next!=tail->next)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=tail->next;
        tail=prev;
        free(curr);
    }
    display();
}

void display()
{
    struct node *temp;
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

int main()
{
    create();
    display();
    delend();
    return 0;
}