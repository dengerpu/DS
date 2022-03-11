#include<stdio.h>
#include<malloc.h>
typedef struct stact
{
	int a[100];
	int top;
}*seqstact;
void creat_stact(seqstact L)   //创建栈
{
	int i,n;
	printf("请输入栈长度\n");
	scanf("%d",&n);
	L->top=n;
	printf("请输入元素\n");
	for(i=0;i<L->top;i++)
	{
		scanf("%d",&L->a[i]);
	}
}
void out_stact(seqstact L)  //输出栈
{
	int i;
	printf("输出\n");
	for(i=0;i<L->top;i++)
		printf("%d ",L->a[i]);
	printf("\n");
}
void insert_stact(seqstact L)  //进栈
{int n;
printf("请输入要插入的数\n");
scanf("%d",&n);
L->a[L->top]=n;
L->top++;
out_stact(L);
}
void dele_stact(seqstact L)
{
	L->top--;
	out_stact(L);
}
void main()
{
	seqstact L;
	L=(seqstact)malloc(sizeof(struct stact));
	creat_stact(L);
	out_stact(L);
	insert_stact(L);
	dele_stact(L);
}