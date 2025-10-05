//to find wether the given string is palindrome or not
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
typedef struct
{
    char str[SIZE];
    int top;

} STACK;
void push(STACK *s, char c)
{
    if (s->top != SIZE - 1)
    {
        s->str[++(s->top)] = c;
    }

}
char pop(STACK *s)
{
    if (s->top != -1)
    {
        return s->str[(s->top)--];
    }

}
int ispalindrome(char str[])
{
    STACK s;
    s.top = -1;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(&s, str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i] != pop(&s))
        {
            return 0;
        }

    }
    return 1;

}
int main()
{
    char str[SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    if (ispalindrome(str))
    {
        printf("%s is a palindrome\n", str);
    }
    else
    {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}
