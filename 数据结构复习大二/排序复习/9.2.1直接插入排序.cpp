#include<stdio.h>
#define M 100000
void InsSort(int a[],int length) //ֱ�Ӳ����㷨 /*�ڽ������������㷨��a[0]�������Ԫ��
{
	int i,j;
	for(i=2;i<=length;i++)  //�ӵڶ������ݿ�ʼ�����β���
	{
		a[0]=a[i];j=i-1;		//a[0]��ΪҪ�������
		while(a[0]<a[j])		//��a[0]��һ�����ʵ�λ��
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}	
}
int main()
{
	int i,n,a[M];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	InsSort(a,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
return 0;
}
