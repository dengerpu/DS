#include<stdio.h>
#include<malloc.h>
#define max 1024
typedef struct zhan
{
	int a[max];
	int top;
}*seqstact;
void out_stact(seqstact l)  //输出栈
{
	int i;
	for(i=0;i<=l->top;i++)
		printf("%d ",l->a[i]);
	printf("\n");
}
void  creat_stact(seqstact l)  //创建一个栈
{
	int n,i;
	printf("请输入栈顶\n");
	scanf("%d",&n);
	l->top=n;
/*	if(l->top<0||l->top>max)
		printf("输入错误，超出范围\n");*/
	for(i=0;i<=l->top;i++)
		scanf("%d",&l->a[i]);
	printf("输出：\n");
	out_stact(l);
	
}
int enter_stact(seqstact l,int e)  //进栈
{
	if(l->top>max-1)
	{
		printf("栈是满的\n");
		return 0;
	}
	l->top++;
	l->a[l->top]=e;
	printf("输出：\n");
	out_stact(l);
	return 0;
}
int pulsh(seqstact l)   //出栈
{
	l->top--;
	printf("输出：\n");
	out_stact(l);
	return 0;
}
int main()
{
	struct zhan s;    //思考为什么要加这一步，没有这一步程序Windows发生错误；
	seqstact l=&s;
	/*seqstact l;
	l=(seqstact)malloc(sizeof(struct zhan));*/   //以上两种都可以使程序正常运行。
	int j;
	creat_stact(l);
	printf("请输入要插入的栈顶元素\n");
	scanf("%d",&j);
	enter_stact(l,j);
	pulsh(l);
		return 0;
}