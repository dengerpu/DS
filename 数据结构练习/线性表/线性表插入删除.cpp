#include<stdio.h>
#define max 1024
typedef struct
{
	int a[max];
	int length;
}linklist;
int insert(linklist *l,int i,int e)
{
	int j;
	if(i<1||i>l->length+1)
	{
		printf("�������ݴ���\n");
		return 0;
	}
	for(j=l->length;j>=i;j--)
		l->a[j]=l->a[j-1];
	l->a[i-1]=e;
	l->length++;
}
int dele(linklist *l,int i)
{
	int j;
	if(i<1||i>l->length)
	{
		printf("�������ݴ���\n");
		return 0;
	}
	for(j=i-1;j<l->length;j++)
		l->a[j]=l->a[j+1];
	l->length--;
}
void main()
{
	linklist s,*l=&s;
	int n,i,j,k,x;
	printf("���������鳤�ȣ�\n");
	scanf("%d",&n);
	l->length=n;
	printf("��������ֵ:\n");
	for(i=0;i<l->length;i++)
		scanf("%d",&l->a[i]);
	printf("������Ҫ���ڵڼ������Լ���ֵ��\n");
	scanf("%d%d",&j,&k);
	insert(l,j,k);
	for(i=0;i<l->length;i++);
	printf("%d ",l->a[i]);
	printf("\n");
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&x);
	dele(l,x);
	for(i=0;i<l->length;i++)
		printf("%d  ",l->a[i]);
	printf("\n");
}