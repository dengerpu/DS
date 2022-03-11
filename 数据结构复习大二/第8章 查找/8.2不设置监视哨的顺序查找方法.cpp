#include<stdio.h>
int SeqSearch(int a[],int length,int k)   //不设置监视的顺序查找方法,a[0]不存放元素
{
	int i=length;
	while(i>=1&&a[i]!=k)
		i--;
	if(i>=1)
		return i;
	else
		return 0;	
}
int main()
{
	int a[100],n,i,key,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("请输入要查找的数\n");
	scanf("%d",&key);
	k=SeqSearch(a,n,key);
	if(k>=1)
		printf("要查找的数为第%d个\n",k);
	else
		printf("没有查找到这个数\n");
	return 0;
}
//以上两种方法都可以通过for循环.do while循环来实现