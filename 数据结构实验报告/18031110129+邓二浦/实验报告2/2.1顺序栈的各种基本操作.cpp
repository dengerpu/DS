#include<stdio.h>
#define max 50
typedef struct
{
	int a[50];
	int top;
}Seqstack;
void initstack(Seqstack *S)     //��ʼ��˳��ջ
{
	S->top=-1;
}
int push(Seqstack *S,int x)     //��ջ
{
	if(S->top==max-1) return 0;
	S->top++;
	S->a[S->top]=x;
	return 1;
}
int pop(Seqstack *S,int *x)      //��ջ
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
int gettop(Seqstack *S,int *x)       //��ȡջ��Ԫ��
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
void printstack(Seqstack *S)        //���ջ�е�Ԫ��
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
	printf("������Ҫ��ջԪ�صĸ���\n");
	scanf("%d",&n);
	printf("������Ҫ��ջ��Ԫ��\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		push(&S,e);
	}
	printf("���ջ��Ԫ��\n");
	printstack(&S);
	printf("ִ�г�ջ����\n");
	pop(&S,&e);
	printf("��ջ��ջ�е�Ԫ��Ϊ\n");
	printstack(&S);
	printf("���ջ��Ԫ��");
	gettop(&S,&e);
	printf("%d\n",e);
	return 0;
}