//���Ա�˳��洢�ṹ
#include<stdio.h>
typedef struct
{
	int a[100];
	int length;
}SeqList;
int locate(SeqList L,int e)  ///�����ݲ���
{
    int i=0;
	while(i<=L.length&&(L.a[i]!=e))
		i++;
	if(i<=L.length)
	{
		printf("%d�ڵ�%d��\n",e,i+1);
		return(i+1);
	}
	else
	{
		printf("û�������\n");
		return 0;
	}
}
int InsList(SeqList L,int i,int e)//���Ա�Ĳ�������
{
	int k;
	if(i<1||(i>L.length +2))
	{
		printf("���벻�ϸ�\n");
		return 0;
	}
	for(k=L.length ;k>=i;k--)
		L.a[k]=L.a[k-1];
	L.a[i-1]=e;
	L.length ++;
	return 1;
}
void main()
{
	int i,sum,e,b;
	SeqList L;
	printf("���������鳤��\n");
	scanf("%d",&sum);
	L.length=sum;
	printf("����������Ԫ��\n");
	for(i=0;i<sum;i++)
		scanf("%d",&L.a[i]);
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&e);
	locate(L,e);
	printf("������Ҫ��������Լ�Ҫ���ڵڼ���\n");
	scanf("%d%d",&e,&b);
	InsList(L,b,e);
	for(i=0;i<L.length ;i++)
		printf("%d ",L.a[i]);
}
