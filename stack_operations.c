#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
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
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("stack under flow!! cannot pop from the stack");
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
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;printf("stack has been created successfully\n");

    sp->arr = (int *)malloc(sp->size * sizeof(int));
    
    printf("before pushing,full:%d\n", isFull(sp));
    printf("before pushing,full:%d\n", isEmpty(sp));

    push(sp, 45);
    push(sp, 35);
    push(sp, 4);
    push(sp, 40);
    push(sp, 32);

    printf("after pushing,full :%d\n", isFull(sp));
    printf("after pushing,Empty%d\n", isEmpty(sp));

    printf("popped %d from the stack\n",pop(sp));
     printf("popped %d from the stack\n",pop(sp));
      printf("popped %d from the stack\n",pop(sp));
     

    return 0;
}