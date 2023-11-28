#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    int priority;
    struct node* next;
};
struct node* newNode(int d,int p);
int peek1(struct node** head);
void push(struct node** head,int d,int p);
void pop(struct node** head);
int isEmpty(struct node** head);
struct node* newNode(int d,int p){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->value=d;
    temp->priority=p;
    temp->next=NULL;
    return temp;
}
int peek1(struct node** head){
    return (*head)->value;
}
void pop1(struct node** head){
    struct node* temp = *head;
    *head=(*head)->next;
    free(temp);
}
void push2(struct node** head,int d,int p)// d is data, p priority
{
    struct node* start = *head;
    struct node* temp=newNode(d,p);
    if(*head == NULL || (*head)->priority > p){ // lower number higher priority
        temp->next=*head;
        *head=temp;
    }
    else{
        while(start->next!=NULL&&start->next->priority<p){
            start=start->next;
        }
        temp->next=start->next;
        start->next=temp;
    }
}
int isEmpty(struct node** head){
    return (*head)==NULL;
}
int main(){
    struct node* pq=newNode(4,1);
    push2(&pq,5,2);
    push2(&pq,6,3);
    push2(&pq,7,0);
    push2(&pq,2,4);
    while(!isEmpty(&pq)){
        printf("%d",peek1(&pq));
        pop1(&pq);
    }

}