#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct{
int data[SIZE];
int top;
}STACK;
void push(STACK *s,int rem){
    if(s->top!=SIZE-1)
        s->data[++s->top]=rem;
}
int pop(STACK *s){
    if(s->top!=-1)
        return(s->data[s->top--]);
    return -1;

}
void dectobin(STACK *s,int num){
    int rem,bin[SIZE],i=0,j=0;
    while(num!=0)
    {
        rem=num%2;
        push(s,rem);
        num=num/2;
    }
    while(s->top!= -1){
        bin[i++]=pop(s);
    }
    printf("\n The binary equivalent is");
    for(j=0;j<i;j++)
        printf("%d",bin[j]);
}
int main(){
    STACK s;
    s.top=-1;
    int num;
    printf("Enter the number :");
    scanf("%d",&num);
    dectobin(&s,num);
    return 0;
}













