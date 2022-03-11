#include<stdio.h>
int father[100];
int find_root(int x)//查找根节点
{
	if(x!=father[x])
		father[x]=find_root(father[x]);
	return father[x];
}
int merge(int x,int y)   //判断是否可以合并
{
	int t1=find_root(x);
	int t2=find_root(y);
	if(t1!=t2)   //如果不在同一个集合中，就可以合并
	{
		father[t2]=t1;
		return 1;
	}
	return 0;
}
void main()
{
	
	int m,n,i,x,y;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		father[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(!merge(x,y))
			printf("输入错误\n");
	}
	for(i=1;i<=n;i++)
		printf("%d",father[i]);
}
