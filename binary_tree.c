#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node) ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d\n", x);
    newnode->left = create();
    printf("Enter right child of %d\n", x);
    newnode->right = create();
    return newnode;
}
struct node *find(struct node *root,int key)
{
    if(root==0)
    {
        return 0;
    }
    if(key<root->data)
    {
        return find(root->left,key);
    }
    else if(key>root->data)
    {
        return find(root->right,key);
    }
    return root;
}
void display(struct node *root, int level)
{
    int i;
    if (root == 0)
    {
        return ;
    }
    display(root->right, level + 1);
    printf("\n");
    for (i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->data);
    display(root->left, level + 1);
}
void inorder(struct node *root)
{
    if(root==0)
    {
        return ;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root==0)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void main()
{
    int key;
    struct node *root,*temp;
    root = 0;
    root = create();
    display(root, 0);
    printf("\nInorder traversal is: ");
    inorder(root);
    printf("\nPreorder traversal is: ");
    preorder(root);
    printf("\nPostorder traversal is: ");
    postorder(root);
    printf("\n Enter the element you want to search in the BST: ");
    scanf("%d ",&key);
    if(find(root,key)==0)
    {
        printf("%d not found",key);
    }
    else 
    {
        printf("%d found",key);
    }
    return ;
}