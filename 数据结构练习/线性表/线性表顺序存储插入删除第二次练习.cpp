#include<stdio.h>
#define max 1024
typedef struct
{
	int a[max];
	int length;
}linklist;
int insert(linklist *l,int i,int e)   //����
{
	int j;
	if(i<0||i>l->length+1)
	{
		printf("��������\n");
		return 0;
	}
	for(j=l->length;j>=i;j--)
		l->a[j]=l->a[j-1];
	l->a[i-1]=e;
	l->length++;
	return 0;
}
int dele(linklist *l,int i)   //ɾ��
{
	int j;
	if(i<0||i>l->length)
	{
		printf("��������\n");
		return 0;
	}
	for(j=i-1;j<l->length;j++)
		l->a[j]=l->a[j+1];
	l->length--;
	return 0;
}
int loc1(linklist *l,int i)  //����Ų���
{
	int j;
	if(i<0||i>l->length)
	{
		printf("��������\n");
		return 0;
	}
	for(j=0;j<l->length;j++)
		if(j+1==i)
		{
			printf("��%d����Ϊ:%d\n",i,l->a[j]);
			return 0;
		}
		return 0;
}
int loc2(linklist *l,int e)  //��ֵ����
{
	int j;
	for(j=0;j<l->length;j++)
		if(l->a[j]==e)
		{
			printf("%dΪ��%d����\n",e,j+1);
			return 0;
		}
			printf("û�������\n");
		return 0;
}
void main()
{
	linklist s;
	linklist *l=&s;
	int n,i,j,k,e;
	printf("�������������\n");
	scanf("%d",&n);
	l->length=n;
	printf("����������\n");
	for(i=0;i<l->length;i++)
		scanf("%d",&l->a[i]);
	printf("������Ҫ���ڵڼ������Լ������\n");
	scanf("%d%d",&j,&k);
	insert(l,j,k);
	for(i=0;i<l->length;i++)
		printf("%d ",l->a[i]);
	printf("\n");
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&e);
	dele(l,e);
	for(i=0;i<l->length;i++)
		printf("%d ",l->a[i]);
	printf("\n");
	printf("������Ҫ���ҵڼ�����\n");
	scanf("%d",&i);
	loc1(l,i);
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&i);
	loc2(l,i);
}
