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
	if(i<1||i>l->length+1)
	{
		printf("�������\n");
		return 0;
	}
	for(j=l->length;j>=i;j--)
		l->a[j]=l->a[j-1];
	l->a[i-1]=e;
	l->length++;
}
int dele(linklist *l,int i)   //ɾ��
{
	int j;
	if(i<1||i>l->length)
	{
		printf("ɾ�����ݴ���\n");
		return 0;
	}
	for(j=i-1;j<l->length;j++)
		l->a[j]=l->a[j+1];
	l->length--;
}
int chazhao(linklist *l,int b)  //����
{
	int i;
	for(i=0;i<l->length;i++)
		if(b==l->a[i])
		{
			printf("���ǵ�%d����\n",i+1);
			return i+1;
		}
		printf("û�������\n");
		return 0;
}
void main()
{
	int i,n,e,j,k,b;
	linklist s,*l=&s;
	printf("���������鳤��\n");
	scanf("%d",&n);
	l->length=n;
	printf("��������ֵ\n");
	for(i=0;i<n;i++)
		scanf("%d",&l->a[i]);
	printf("��������ڵڼ��������Լ��������ֵ\n");
	scanf("%d%d",&j,&e);
	insert(l,j,e);
	for(i=0;i<l->length;i++)
		printf("%d  ",l->a[i]);
	printf("\n");
	printf("������Ҫɾ�����ֵ��±�\n");
	scanf("%d",&k);
	dele(l,k);
	for(i=0;i<l->length;i++)
		printf("%d  ",l->a[i]);
	printf("\n");
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&b);
	chazhao(l,b);
}