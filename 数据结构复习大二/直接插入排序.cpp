#include<stdio.h>
void insort(int a[],int n)   //ֱ�Ӳ���������һ���ȶ������򷽷��������ڴ����м�¼��Ŀ�����һ�����������
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		a[0]=a[i];
		j=i-1;
		while(a[0]<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}
}
void main()
{
	int a[11];
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	insort(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");

}