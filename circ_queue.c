#include <stdio.h>
#define size 5;
void insertcq(int q)
{
    if (count == size)
        printf("full");
    r = (r + 1) % size;
    printf("enter item");
    scanf("%d", &item)
        q[r] = item;
    count++;
}
void delete()
{
    if (count == 0)
    {
        printf("empty");
    }
    printf("element deleted %d", q[f]);
    f = (f + 1) % size;
    count--;
}
void display()
{
    j = f;
    for (int i = 1; i <= count; i++)
    {
        printf("%d", q[j])
            j = (j + 1) % size;
    }
}
int main()
{
    int *q, size, f = 0, r = -1, count = 0;
    insertcq() return 0;
}