#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
 struct node* create()
 {
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node) ");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("Enter left child of %d\n",x);
    newnode->left=create();
    printf("Enter right child of %d\n",x);
    newnode->right=create();
    return newnode;
 }
 void display(struct node *root, int level)
{
    int i;
    if(root == 0)
        return;
    display(root->right, level + 1);
    printf("\n");
    for(i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", root->data);
    display(root->left, level + 1);
}
void main()
{
    int x;
    struct node* root;
    root=0;
    root=create();
    display(root, 0);
}