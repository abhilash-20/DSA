#include <stdlib.h>
#include <stdio.h>
#define N 5
int stacks[N];
int top = -1;
void push()
{
    int data;
    printf("Enter the value you want to push into the stack:\n");
    scanf("%d",&data);
    if(top==N-1)
    {
        printf("Overflow condition.\n");
    }
    else
    {
        top++;
        stacks[top]=data;
        printf("%d is pushed into the stack.",data);
        printf("\n");
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("Underflow Condition.");
    }
    else
    {
        item=stacks[top];
        top--;
        printf("The item popped is:%d",item);
        printf("\n");
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Empty stack.\n");
    }
    else
    {
        printf("The top-most item is: %d",stacks[top]);
        printf("\n");
    }
}
void display()
{
    int i;
    printf("The stack is:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d ",stacks[i]);
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("Enter your choice: ");
        printf("\n1 to push\n2 to pop \n3 to peek\n4 to display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("wrong choice\n");
            break;
        }
    }
    return 0;
}