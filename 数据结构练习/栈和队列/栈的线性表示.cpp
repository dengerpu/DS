#include<stdio.h>
#include<malloc.h>
#define max 100
typedef struct node
{
	int a[max];
	int top;
}*seqstact;
void out_stact(seqstact l)
{
	int i;
	for(i=0;i<l->top;i++)
		printf("%d ",l->a[i]);
	printf("\n");
}
void creat_stact(seqstact l)
{
	int n,i;
	printf("������ջ�ĳ���\n");
	scanf("%d",&n);
	l->top=n;
	if(l->top<0||l->top>max)
		printf("������Χ\n");
	printf("����������Ԫ��\n");
	for(i=0;i<l->top;i++)
		scanf("%d",&l->a[i]);
	printf("���\n");
	out_stact(l);
}
void enter_stact(seqstact l)
{
	int n;
	printf("������Ҫ�����Ԫ��\n");
	scanf("%d",&n);
	l->a[l->top]=n;
	l->top++;
	printf("���\n");
	out_stact(l);
}
void push_stact(seqstact l)
{
	l->top--;
	printf("���\n");
	out_stact(l);
}
void main()
{
	seqstact l;
	l=(seqstact)malloc(sizeof(struct node));
	creat_stact(l);
	enter_stact(l);
	push_stact(l);
}