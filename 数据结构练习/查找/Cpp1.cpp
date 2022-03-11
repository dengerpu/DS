#include <stdio.h>
int main()
{
    int a[10],i;
    void sort(int*,int);
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    sort(a,10);
    printf("\nthe result date is:");
    for(i=0;i<10;i++)
        printf("%d",a[i]);
    return 0;
}
void sort(int *p,int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        if(p[i]>p[j])
    {
        t=p[i];
        p[i]=p[j];
        p[j]=t;
    }
}