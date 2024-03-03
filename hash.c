#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define mod(x) x % MAX

void linear_prob(int a[], int num, int key)  //num-->number to inserted
{                                           //key->index of hash table
    if (a[key] == -1)   // checking whether space is empty or not
        a[key] = num;   
    else
    {
        printf("\nCollision detected!!");
        int i;
        for (i = mod(key + 1); i != key; i = mod(++i))//mod() will give index of hash table.it is defined in outside of all program
        {
            if (a[i] == -1)
                break;  // if next slot is full then it will break the loop
        }
        if (i != key)
        {
            printf("\nCollision avoided successfully\n");
            a[i] = num;  //asigning the num into specific slot
        }
        else
            printf("\nHash table is full\n");
    }
}

void display(int a[])
{
    short ch, i;
    printf("\n1.Filtered display\n2.Display all\nEnter choice:");//filtered display will show only non-empty slots
    scanf("%hd", &ch);                                           // display will show all slot of hash table
    printf("\nHash table is :\n");
    for (i = 0; i < MAX; i++)
    {
        if (a[i] > 0 || ch - 1)
            printf("%d  %d\n", i, a[i]);
    }
}

int main()
{
    int a[MAX], num, i;
    printf("\nCollision handling by linear probing");
    for (i = 0; i < MAX; a[i++] = -1);
        
    do
    {
        printf("\nEnter the data:");
        scanf("%d", &num);
        linear_prob(a, num, mod(num));  //calling the linear function with three argument
        printf("Do u wish to continue(1/0):");
        scanf("%d", &i);
    } while (i);
    display(a);  
    return 0;
}
