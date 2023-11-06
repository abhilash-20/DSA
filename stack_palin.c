#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *stack;
int top = -1;
void push(char ele)
{
    stack[++top] = ele;
}
char pop()
{
    return stack[top--];
}

int check(char str[])
{
    int len = strlen(str);
    stack = (char *)malloc(len * sizeof(char));
    int i;
    for (i = 0; i < (strlen(str)) / 2; i++)
    {
        push(str[i]);
    }
    if (len % 2 != 0)
    {
        i++;
    }
    while (str[i] != '\0')
    {
        char ele = pop();
        if (ele != str[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main()
{
    char str[100];
    printf("Enter a word: ");
    gets(str);
    if (check(str))
    {
        printf("Yes, it's a palindrome.");
    }
    else
    {
        printf("No, its not a palindrome.");
    }
    return 0;
}