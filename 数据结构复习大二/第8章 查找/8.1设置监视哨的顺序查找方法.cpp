#include<stdio.h>
int SeqSearch(int a[],int length,int k)   //设置监视的顺序查找方法,a[0]不存放元素，元素从a[1]开始存放。
{
	int i=length;
	a[0]=k;  
	while(a[i]!=k)
		i--;
	return i;
	
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
	if(k!=0)
		printf("要查找的数为第%d个\n",k);
	else
		printf("没有查找到这个数\n");
	return 0;
}
//思考 如果a[0]存放有元素怎么办？
//答案：a[-1]设置为监视哨，如果没有找到，返回的值为-1。