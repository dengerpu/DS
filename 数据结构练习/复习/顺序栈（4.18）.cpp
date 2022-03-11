#include<stdio.h>
#include<malloc.h>
#define maxsize 100
typedef struct node
{
	int a[maxsize];
	int top;
}*Seqstact;
void creat_stact(Seqstact L)
{
	int i,n;
	printf("请输入顺序栈的长度\n");
	scanf("%d",&n);
	L->top=n;
	printf("请输入栈元素\n");
	for(i=0;i<L->top;i++)
	{
		scanf("%d",&L->a[i]);
	}
}
void out_stact(Seqstact L)
{
	int i;
	for(i=0;i<L->top;i++)
	{
		printf("%d ",L->a[i]);
	}
	printf("\n");
}
void insert_stact(Seqstact L)
{
	int x;
	printf("请输入要插入的数字\n");
	scanf("%d",&x);
	L->a[L->top]=x;
	L->top++;
	out_stact(L);
}
void dele_stact(Seqstact L)
{
	L->top --;
	out_stact(L);
}
main()
{
	Seqstact L;
	L=(Seqstact)malloc(sizeof(struct node));
	creat_stact(L);
	out_stact(L);
	insert_stact(L);
	dele_stact(L);
}

