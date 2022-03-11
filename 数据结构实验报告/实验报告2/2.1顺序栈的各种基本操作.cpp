#include<stdio.h>
#define max 50
typedef struct
{
	int a[50];
	int top;
}Seqstack;
void initstack(Seqstack *S)     //初始化顺序栈
{
	S->top=-1;
}
int push(Seqstack *S,int x)     //进栈
{
	if(S->top==max-1) return 0;
	S->top++;
	S->a[S->top]=x;
	return 1;
}
int pop(Seqstack *S,int *x)      //出栈
{
	if(S->top==-1)
		return 0;
	else
	{
		*x=S->a[S->top];
		S->top--;
		return 1;
	}
}
int gettop(Seqstack *S,int *x)       //读取栈顶元素
{
	if(S->top==-1)
	{
		return 0;
	}
	else
	{
		*x=S->a[S->top];
		return 1;
	}
}
void printstack(Seqstack *S)        //输出栈中的元素
{
	int i;
	for(i=0;i<=S->top;i++)
		printf("%d ",S->a[i]);
	printf("\n");
}
int main()
{
	Seqstack S;
	int n,i,e;
	initstack(&S);
	printf("请输入要进栈元素的个数\n");
	scanf("%d",&n);
	printf("请输入要进栈的元素\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		push(&S,e);
	}
	printf("输出栈的元素\n");
	printstack(&S);
	printf("执行出栈操作\n");
	pop(&S,&e);
	printf("出栈后栈中的元素为\n");
	printstack(&S);
	printf("输出栈顶元素");
	gettop(&S,&e);
	printf("%d\n",e);
	return 0;
}