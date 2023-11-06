#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char string1[20];
    printf("Enter a string:");
    gets(string1);
    int len=strlen(string1);
    int flag=0;
    for(int i=0;i<len/2;i++)
    {
        if(string1[i]!=string1[len-i-1])
        {
            flag=1;
            break;
        }
    }
        if(flag)
        {
            printf("not palindrome");
        }
        else{
            printf("palindrome.");
        }
    return 0;
}