#include<stdio.h>
int father[100];
int find_root(int x)//���Ҹ��ڵ�
{
	if(x!=father[x])
		father[x]=find_root(father[x]);
	return father[x];
}
int merge(int x,int y)   //�ж��Ƿ���Ժϲ�
{
	int t1=find_root(x);
	int t2=find_root(y);
	if(t1!=t2)   //�������ͬһ�������У��Ϳ��Ժϲ�
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
			printf("�������\n");
	}
	for(i=1;i<=n;i++)
		printf("%d",father[i]);
}
