#include<stdio.h>
#define max 100
typedef struct
{
	int a[max];
	int last;
}SeqList;
void initlist(SeqList *L)          //��ʼ��˳���
{
	L->last=-1;
}
int InsList(SeqList *L,int i,int e)    //����
{
	int k;
	if((i<1)||(i>L->last+2))
	{
		printf("����λ��iֵ���Ϸ�");
		return 0;
	}
	if(L->last>=max-1)
	{
		printf("���������޷�����\n");
		return 0;
	}
	for(k=L->last;k>=i-1;k--)
		L->a[k+1]=L->a[k];
	L->a[i-1]=e;
	L->last++;
	return 1;
}
void creatlist(SeqList *L)          //����˳���
{
	int n,i,e;
	printf("������Ҫ����˳���ĳ���\n");
	scanf("%d",&n);
	printf("������Ҫ�������\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		InsList(L,i+1,e);
	}
	
}
int dellist(SeqList *L,int i,int *e)    //ɾ��
{
	int k;
	if(i<1||i>L->last+1)
	{
		printf("ɾ��λ�ò��Ϸ�\n");
		return 0;
	}
	*e=L->a[i-1];
	for(k=i-1;k<L->last;k++)
		L->a[k]=L->a[k+1];
	L->last--;
	return 1;
}
void printlist(SeqList *L)             //���˳���
{
	int i;
	for(i=0;i<=L->last;i++)
		printf("%d ",L->a[i]);
	printf("\n");
}
int main()
{
	SeqList L;
	int i,e;
	initlist(&L);
	creatlist(&L);
	printf("������˳���Ϊ:\n");
	printlist(&L);
	printf("������Ҫ���ڵڼ������Լ�Ҫ�������\n");
	scanf("%d%d",&i,&e);
	InsList(&L,i,e);
	printf("����������Ϊ:\n");
	printlist(&L);
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&i);
	dellist(&L,i,&e);
	printf("ɾ���������Ϊ:\n");
	printlist(&L);
	return 0;
}