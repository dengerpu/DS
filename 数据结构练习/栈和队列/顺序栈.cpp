#include<stdio.h>
#include<malloc.h>
#define max 1024
typedef struct zhan
{
	int a[max];
	int top;
}*seqstact;
void out_stact(seqstact l)  //���ջ
{
	int i;
	for(i=0;i<=l->top;i++)
		printf("%d ",l->a[i]);
	printf("\n");
}
void  creat_stact(seqstact l)  //����һ��ջ
{
	int n,i;
	printf("������ջ��\n");
	scanf("%d",&n);
	l->top=n;
/*	if(l->top<0||l->top>max)
		printf("������󣬳�����Χ\n");*/
	for(i=0;i<=l->top;i++)
		scanf("%d",&l->a[i]);
	printf("�����\n");
	out_stact(l);
	
}
int enter_stact(seqstact l,int e)  //��ջ
{
	if(l->top>max-1)
	{
		printf("ջ������\n");
		return 0;
	}
	l->top++;
	l->a[l->top]=e;
	printf("�����\n");
	out_stact(l);
	return 0;
}
int pulsh(seqstact l)   //��ջ
{
	l->top--;
	printf("�����\n");
	out_stact(l);
	return 0;
}
int main()
{
	struct zhan s;    //˼��ΪʲôҪ����һ����û����һ������Windows��������
	seqstact l=&s;
	/*seqstact l;
	l=(seqstact)malloc(sizeof(struct zhan));*/   //�������ֶ�����ʹ�����������С�
	int j;
	creat_stact(l);
	printf("������Ҫ�����ջ��Ԫ��\n");
	scanf("%d",&j);
	enter_stact(l,j);
	pulsh(l);
		return 0;
}