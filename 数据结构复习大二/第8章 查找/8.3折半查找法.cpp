#include<stdio.h>
int BinSearch(int a[],int length,int k)   //�۰����,a[0]�����Ԫ�ء�
{
	int low=1,high=length,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(k==a[mid])return mid;
		if(a[mid]>k) high=mid-1;
		else low=mid+1;
	}
	return 0;
	
}
int main()
{
	int a[100],n,i,key,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&key);
	k=BinSearch(a,n,key);
	if(k>=1)
		printf("Ҫ���ҵ���Ϊ��%d��\n",k);
	else
		printf("û�в��ҵ������\n");
	return 0;
}
