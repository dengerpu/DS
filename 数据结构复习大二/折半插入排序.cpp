#include<stdio.h>
void binsort(int a[],int length)  //�۰��������һ���ȶ������򷽷������Լ��ٹؼ��ʵıȽϴ������۰�������򷨵ıȽϴ�����ֱ�Ӳ��������������Ҫ�úܶ࣬������������Ҫ��
{
	int i,low,high,mid,x,j;
	for(i=2;i<=length;i++)
	{
		x=a[i];
		low=1;high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(x<a[mid])high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=low;j--)
			a[j+1]=a[j];
		a[low]=x;
	}
}
void main()
{
	int a[11];
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	binsort(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");

}
