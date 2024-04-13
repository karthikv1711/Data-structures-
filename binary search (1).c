/* Binary search using recursive function */
#include<stdio.h>
int binarysearch(int*,int,int,int);
int a[20], key;
int main() {
    int i, n, pos,key;
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter %d elements:",n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("enter key: ");
    scanf("%d",&key);
    pos = binarysearch(a,0, n-1,key);
    if(pos==-1)
        printf("search unsuccessful");
    else
        printf("Key is found at the index:%d",pos);
    return 0;
}
int binarysearch (int a[], int low,int high,int key)
{
    int mid;
    if(low>high)
        return(-1);
    else {
        mid=(low+high)/2;
        if(key==a[mid])
            return(mid);
        else
        {   if(key<a[mid])
                return(binarysearch(a,low,mid-1,key));
            else
                return(binarysearch(a,mid+1,high,key));
        }
    }
}
