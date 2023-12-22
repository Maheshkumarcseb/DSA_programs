#include<stdio.h>
#define Qsize 5;
void insert()
{
    int r=-1,f=0,item;
    printf("enter the item");
    scanf("%d ",&item);
    if(r==Qsize-1)
    printf("queue is full");
    else
    q[++r]=item;
}
void delete()
{
    if(f==0&&r==-1)
    printf("empty");
    else
    printf("deleted %d",q[f]);
    f++;
}
void display()
{
    for(i=front;i<=rear;i++)
    {
        printf("%d",q[i]);
    }
}