#include<stdio.h>
#include<stdlib.h>
#define max 1024
typedef struct
{
	int a[max];
	int length;
}linklist;
int insert(linklist *l,int i,int e)
{
	int j;
	if(i<1||i>l->length-1)
	{
		printf("����λ�ò��Ϸ�\n");
		return 0;
	}
	for(j=l->length;j>i-1;j--)
		l->a[j]=l->a[j-1];
	l->a[i-1]=e;
	l->length++;
}
int dele(linklist *l,int i,int e)
{
	int j;
	if(i<1||i>l->length-1)
	{
		printf("����λ�ò��Ϸ�\n");
		return 0;
	}
	
	for(j=i-1;j<l->length;j++)
		l->a[j]=l->a[j+1];
	e=l->a[i-1];
	l->length--;
}
int main()
{
	linklist s,*l=&s;
	int i,n,e,m,x,y;
	printf("���������鳤�ȣ�\n");
	scanf("%d",&n);
	printf("��������ֵ\n");
	l->length=n;
	for(i=0;i<n;i++)
		scanf("%d  ",&l->a[i]);
	printf("������Ҫ����ĵڼ������Ͳ������ֵ��\n");
	scanf("%d%d",&e,&m);
	insert(l,e,m);
	for(i=0;i<l->length;i++)
		printf("%d  ",l->a[i]);
	printf("������Ҫɾ���ĵڼ�������\n");
	scanf("%d",&x);
	dele(l,x,y);
	for(i=0;i<l->length;i++)
		printf("%d",l->a[i]);
	return 0;
}
