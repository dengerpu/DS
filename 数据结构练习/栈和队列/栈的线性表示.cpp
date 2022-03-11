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
	printf("请输入栈的长度\n");
	scanf("%d",&n);
	l->top=n;
	if(l->top<0||l->top>max)
		printf("超出范围\n");
	printf("请输入数据元素\n");
	for(i=0;i<l->top;i++)
		scanf("%d",&l->a[i]);
	printf("输出\n");
	out_stact(l);
}
void enter_stact(seqstact l)
{
	int n;
	printf("请输入要插入的元素\n");
	scanf("%d",&n);
	l->a[l->top]=n;
	l->top++;
	printf("输出\n");
	out_stact(l);
}
void push_stact(seqstact l)
{
	l->top--;
	printf("输出\n");
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