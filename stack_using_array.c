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
    if(ptr->top == -1)
    {
        return 1;
    }
    else{
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
int main()
{
    struct stack *s=(struct stack *) malloc ( sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    // printf("hfu");
    s->arr = (int *) malloc (s->size * sizeof(int));
    // isEmpty(s);
    // isFull(s);
    if(isEmpty(s))
        printf("the stack is empty\n");
     else
        printf("the stack is not empty\n");

    //      printf("%d\n",isFull(s));
    // printf("%d\n",isEmpty(s));
    return 0;
}