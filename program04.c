#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int partition(int a[], int low, int high)
{
    int i, j, key,temp;
    key=a[low];
    i=low;
    j=high+1;
    while(i<=j)
    {
        do
        {
            i++;
        }
        while(key>=a[i]);
        do
        {
            j--;
        }
        while(key<a[j]);
        if(i<j)
        {
//swap the elements in position i and j
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
//swap key element with element in position 'j'
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void quick_sort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=partition(a,low,high);
        quick_sort(a,low,mid-1);
        quick_sort(a,mid+1,high);
    }
}
int main()
{
    int n, a[100],k;
    clock_t st,et;
    double ts;
    printf("\n Enter How many Numbers: ");
    scanf("%d", &n);
    srand(time(0));
    printf("\nThe Random Numbers are:\n");
    for(k=0; k<n; k++)
    {
        a[k]=rand()%100;
        printf("%d\t",a[k]);
    }
    st=clock();
    quick_sort(a, 0, n-1);
    et=clock();
    ts=(double)(et-st)/CLK_TCK;
    printf("\n\n\nSorted Numbers are: \n ");
    for(k=0; k<n; k++)
        printf("%d\t", a[k]);
    printf("\nThe time taken is %e",ts);
}
