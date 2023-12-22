#include <stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int* arr;
};
void push()
    {
        if (top==stacksize-1)
        {
            printf("stack full");
            stacksize++;
            s = (int *)realloc(s,stacksize*sizeof(int));
        }
        s[++top] = item;
    }
    void pop()
    {
        if (top == -1)
        {
            printf("stack is empty");
        }
    }
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    int size=40;
    int *s;
    int top = -1;
    s->arr =(int*)malloc(stacksize *sizeof(int));\
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    
    
    
    printf("deleted %d ", s[top--]);
    stacksize--;
    s = (int *)realloc(s,stacksize*sizeof(int));
    return 0;
}
