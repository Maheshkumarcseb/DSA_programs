#include <stdio.h>
int main()
{
int n, a[100], i, key, high, low, mid, loc=0; 
printf("Enter the size of the array\n"); 
scanf("%d",&n);
printf("Enter the elements of array in sorted and roated order\n"); 
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter the key element to be searched\n");
scanf("%d",&key);
low=0;
high=n-1;
while(low<=high)
{
mid=(low+high)/2; 
if(key==a[mid])
{
 loc = mid; //if mid element is key then we are storing the index of key element in loc
 break;
}
if(a[low]<a[mid])   // checking weather left part of array from mid  is sorted or not.
{
    if(key>=a[low]&&key<a[mid])
    {
        high=mid-1;
    }
    else
    low=mid+1;
}
else
{
    if(key>a[mid]&&key<a[high])
    low=mid+1;
    else
    high=mid-1;
}
}
if(loc>=0)
printf("\n The element %d is found at index %d ",key,loc);
else
printf("\nThe search is unsuccessful");
return 0;
}