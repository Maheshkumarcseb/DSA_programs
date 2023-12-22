#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* ptr,int val)
{
    if(isFull(ptr)){
        printf("stack overflow! can't push %d to the stack",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("stack underflow can't pop");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main()
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    // printf("lkl");
    s->size=60;
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));
    printf("stack has been created successfully");
    printf("before pushing,full:%d\n",isFull(s));
    printf("before pushing,Empty:%d\n",isEmpty(s));
    // printf("popped %d frm the stack\n",pop(s));
    // printf("popped %d frm the stack\n",pop(s));
    // printf("popped %d frm the stack\n",pop(s));
    // return 0;
}