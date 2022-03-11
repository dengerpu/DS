/* ˳��ջ���ͽṹ���� */
typedef int StackElementType
#define Stack_Size 50	/* ��ջ��Ԫ�ظ���Ϊ50 */
#define TRUE 1
#define FALSE 0
typedef struct
{
	StackElementType elem[Stack_Size];	/* �������ջ��Ԫ�ص�һά���� */
	int top;	/* �������ջ��Ԫ�ص��±꣬topΪ-1��ʾ��ջ */
}SeqStack;
/* ���㷨3.1��	��ʼ��˳��ջ */
void InitStack(SeqStack * S)
{	/* ����һ����ջ */
	S->top=-1;
}
/* ���㷨3.2��	˳��ջ��ջ���� */
int Push(SeqStack * S,StackElementType x)
{	/* ��x����Sջ��ջ�� */
	if(S->top==Stack_Size-1)	return (FALSE);	/* ջ���� */
	S->top++;
	S->elem[S->top]=x;	/* x��ջ */
	return (TRUE);
}
/* ���㷨3.3��	˳��ջ��ջ���� */
int Pop(SeqStack * S,StackElementType * x)
{	/* ��Sջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��д��� */
	if(S->top==-1)	return (FALSE);	/* ջΪ�� */
	else
	{
		* x=S->elem[S->top];	/* ջ��Ԫ�ظ���x */
		S->top--;	/* �޸�ջ��Ԫ�� */
		return (TRUE);
	}
}
/* ���㷨3.4��	˳��ջ��ջ��Ԫ������ */
int GetTop(SeqStack * S,StackElementType *x)
{	/* ��ջSջ��Ԫ�ض������ŵ�x��ָ�Ĵ洢�ռ��У�ջ��ָ�뱣�ֲ��� */
	if(S->top==-1)	return (FALSE);	/* ջΪ�� */
	else
	{
		* x=S->elem[S->top];	/* ջ��Ԫ�ظ���x */
		return (TRUE);
	}
}
/***************************************************************/
/* ��ջ������ */
/* ��ջ�������ͽṹ���� */
typedef int StackElementType
#define M 100
#define TRUE 1
#define FALSE 0
typedef struct
{
	StackElementType Stack[M];	/* Stack[M]Ϊջ�� */
	StackElementType top[2];	/* top[0]��top[1]�ֱ�Ϊ����ջ��ָʾ�� */
}DqStack;
/* ���㷨3.5��	˫��˳��ջ��ʼ�� */
void InitStack(DqStack * S)
{
	S->top[0]=-1;
	S->top[1]=M;
}
/* ���㷨3.6��	˫��˳��ջ��ջ���� */
int Push(DqStack * S,StackElementType x,int i)
{	/* ������Ԫ��xѹ��i�Ŷ�ջ */
	if(S->top[0]+1==S->top[1])	return (FALSE);	/* ջ���� */
	switch(i)
	{
		case 0:		/* 0��ջ */
			S->top[0]++;
			S->Stack[S->top[0]]=x;break;
		case 1:		/* 1��ջ */
			S->top[1]--;
			S->Stack[S->top[1]]=x;break;
		default:	/* �������� */
			return (FALSE);
	}
	return (TRUE);
}
/* ���㷨3.7��	˫��˳��ջ��ջ���� */
int Pop(DqStack * S,StackElementType * x,int i)
{	/* ��i��ջ���е���ջ��Ԫ�ز��͵�x�� */
	switch (i);
	{
		case 0:	/* ��0��ջ��ջ */
			if(S->top[0]==-1)	return -1;
			* x=S->Stack[S->top[0]];
			S->top[0]--;break;
		case 1:	/* 1��ջ��ջ */
			if(S->top[1]==M)	return (FALSE);
			* x=S->Stack[S->top[1]];
			S->top[1]++;break;
		default:
			return (FALSE);
	}
	return (TRUE);
}
/***************************************************************/
/* ��ջ���ͽṹ���� */
typedef int StackElementType
#define TRUE 1
#define FALSE 0
typedef struct node
{
	StackElementType data;
	struct node * next;
}LinkStackNode;
typedef LinkStackNode * LinkStack;
/* ���㷨3.8��	��ջ��ջ���� */
int Push(LinkStack top,StackElementType x)
/* ������Ԫ��xѹ��ջtop�� */
{
	LinkStackNode * temp;
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
	if(temp==NULL)	return (FALSE);	/* ����ռ�ʧ�� */
	temp->data=x;
	temp->next=top->next;
	top->next=temp;	/* �޸ĵ�ǰջ��ָ�� */
	return (TRUE);
}
/* ���㷨3.9��	��ջ��ջ���� */
int Pop(LinkStack top,StackElementType * x)
{	/* ��ջtop��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	LinkStackNode * temp;
	temp=top->next;
	if(temp==NULL)	return (FALSE);	/* ջΪ�� */
	top->next=temp->next;
	* x=temp->data;
	free(temp);	/* �ͷŴ洢�ռ� */
	return (TRUE);
}
/***************************************************************/
/* ��ջ���� ��ջ���ͽṹ���� */
#define M 10	/* M����ջ */
typedef int StackElementType
typedef struct node
{
	StackElementType data;
	struct node * next;
}LinkStackNode,* LinkStack;
LinkStack top[M];
/***************************************************************/
/* ջ��Ӧ�þ��� */
/* ���㷨3.10��	����ƥ���㷨 */
void BracketMatch(char * str)
/* str[]��Ϊ������ַ��������ö�ջ�����������ַ����е������Ƿ�ƥ�� */
{
	Stack S; int i; char ch;
	InitStack(&S);
	for(i=0;str[i]!='\0';i++)	/* ���ַ����е��ַ���һɨ�� */
	{
		switch(str[i])
		{
			case '(':
			case '[':
			case '{':
				Push(&S,str[i]);
				break;
			case ')':
			case ']':
			case '}':
				if(IsEmpty(&S))
				{ printf("\n�����Ŷ��࣡"); return ; }
				else
				{
					GetTop(&S,&ch);
					if(Match(ch,str[i]))	/* ��Match�ж����������Ƿ�ƥ�� */
						Pop(&S,&ch);	/* ��ƥ��������ų�ջ */
					else
					{ printf("\n��Ӧ���������Ų�ͬ�࣡"); return ;}
				}
		}/* switch */
	}/*for*/
	if(IsEmpty(S))
		printf("\n����ƥ�䣡");
	else
		printf("\n�����Ŷ��࣡");
}
/* ���㷨3.11�� �������������ʽ������ */
int ExpEvaluation()
/* ����һ�����������ʽ��������ֵ��OPTR��OVS�ֱ�Ϊ�����ջ��������ջ��OPSetΪ��������� */
{
	InitStack(&OPTR);
	InitStack(&OVS);
	Push(&OPTR,'#');	/* Ϊ������������Ƚ�#ѹ��OPTRջ */
	printf("\n\nPlease input an expression (Ending with #) :");
	ch=getchar();
	while(ch!='#'||GetTop(OPTR)!='#')	/* GetTop()ͨ������ֵ����ջ��Ԫ�� */
	{
		if(!In(ch,OPSet))	/* ���ǲ��������ǲ���������OVSջ */
		{
			n=GetNumber(ch);
			Push(&OVS,n);
			ch=getchar();
		}
		else
			switch(Compare(ch,GetTop(OPTR)))
			{
				case '>':Push(&OPTR,ch);
					ch=getchar(); break;
				case '=':
				case '<':Pop(&OPTR,&op);	/* �γ����� */
				Pop(&OVS,&b);
				Pop(&OVS,&a);
				v=Execute(a,op,b);	/* ��a��b����op���� */
				Push(&OVS,v);
				break;
			}
	}
	v=GetTop(OVS);
	return (v);
}
/* ���㷨3.12�� ��ŵ���ݹ��㷨 */
void hanoi(int n,char x,char y,char z)
/* ������x�ϴ��ϵ��±��Ϊ1��n���Ұ�ֱ����С������ŵ�n��Բ�̣�������ᵽ����z�ϣ�y������������ */
{
	if(n==1)
		move(x,1,z);	/* �����Ϊ1��Բ�̴�x�ƶ�z */
	else
	{
		hanoi(n-1,x,z,y);	/* ��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z�������� */
		move(x,n,z);	/* �����Ϊn��Բ�̴�x�Ƶ�z */
		hanoi(n-1,y,x,z);	/* ��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��x�������� */
	}
}
/* ���㷨3.13�� 쳲��������еķǵݹ��㷨 */
int Fib(int n)
{
	int x,y,z;
	if(n==0||n==1)	return n;	/* ����Fib(0)��Fib(1) */
	else
	{
		x=0,y=1;	/* x=Fib(0) y=Fib(1) */
		for(i=2;i<=n;i++)
		{
			z=y;	/* z=Fib(i-1) */
			y=x+y;	/* y=Fib(i-1)+Fib(i-2),��Fib(i) */
			x=z;	/* x=Fib(i-1) */
		}
		return y;
	}
}
/* ���㷨3.14�� ��n!�ĵݹ��㷨 */
long Fact(int n)
{
	if(n==1)	return 1;
	return n*Fact(n-1);
}
/* ���㷨3.15�� ��n!�ǵݹ��㷨 */
long Fact(int n)
{
	int fac=1;
	for(int i=1;i<=n;i++)	/* ���μ���f(1),...,f(n) */
		fac=fac*i;	/* f(i)=f(i-1)*i */
	return fac;
}
/***************************************************************/
/* ���������ͽṹ���� */
#define TRUE 1
#define FLASE 0
typedef int QueueElementType;
typedef struct Node
{
	QueueElementType data;	/* ������ */
	struct Node * next;	/* ָ���� */
}LinkQueueNode;
typedef struct
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;
/* ���㷨3.16�� �����г�ʼ��*/
int InitQueue(LinkQueue * Q)
{	/* ��Q��ʼ��Ϊһ���յ������� */
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
		return (TRUE);
	}
	else
		return (FALSE);	/* ����� */
}
/* ���㷨3.17�� ��������Ӳ����㷨*/
int EnterQueue(LinkQueue * Q,QueueElementType x)
{
	LinkQueueNode * NewNode;
	NewNode=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(NewNode!=NULL)
	{
		NewNode->data=x;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear=NewNode;
		return (TRUE);
	}
	else
		return (FALSE);	/* ����� */
}
/* ���㷨3.18�� �����г��Ӳ����㷨*/
int DeleteQueue(LinkQueue * Q,QueueElementType * x)
{	/* ������Q�Ķ�ͷԪ�س��ӣ�����ŵ�x��ָ�Ĵ洢�ռ��� */
	LinkQueueNode * p;
	if(Q->rear==Q->front)
		return (FALSE);
	p=Q->front->next;
	Q->front->next=p->next;	/* ��ͷԪ��p���� */
	if(Q->rear==p)	/* �������ֻ��һ��Ԫ��p����p���Ӻ��Ϊ�ն� */
		Q->rear=Q->front;
	* x=p->data;
	free(p);	/* �ͷŴ洢�ռ� */
	return (TRUE);
}
/***************************************************************/
/* ѭ���������ͽṹ���� */
#define MAXSIZE 50	/* ���е���󳤶� */
typedef int QueueElementType;
typedef struct
{
	QueueElementType element[MAXSIZE];	/* ���е�Ԫ�ؿռ� */
	int front;	/* ͷָ��ָʾ�� */
	int rear;	/* βָ��ָʾ�� */
}SeqQueue;
/* ���㷨3.19�� ѭ�����г�ʼ������*/
void InitQueue(SeqQueue * Q)
{	/* ��* Q��ʼ��Ϊһ���յ�ѭ������ */
	Q->front=Q->rear=0;
}
/* ���㷨3.20�� ѭ��������Ӳ���*/
int EnterQueue(SeqQueue * Q,QueueElementType x)
{	/* ��Ԫ��x��� */
	if((Q->rear+1)%MAXSIZE==Q->rear)	/* βָ���1׷��ͷָ�룬��־�����Ѿ����� */
		return (FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;	/* �������ö�βָ�� */
	return (TRUE);	/* �����ɹ� */
}
/* ���㷨3.21�� ѭ�����г��Ӳ���*/
int DeleteQueue(SeqQueue * Q,QueueElementType * x)
{
	if(Q->front==Q->rear)	/* ����Ϊ�� */
		return (FALSE);
	* x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;	/* �������ö�ͷָ�� */
	return (TRUE);	/* �����ɹ� */
}
/* ���㷨3.22�� ��ӡ���������ǰn��Ԫ���㷨*/
void YangHuiTriangle()
{
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q,1);	/* ��һ��Ԫ����� */
	for(n==2;n<=N;n++)	/* ������n��Ԫ�ز���ӣ�ͬʱ��ӡ��n-1�е�Ԫ�� */
	{
		EnterQueue(&Q,1);	/* ��n�еĵ�һ��Ԫ����� */
		for(i=1;i<n-2;i++)	/* ���ö��е�n-1��Ԫ�ز����ĵ�n�е��м�n-2��Ԫ�ز���� */
		{
			DeleteQueue(&Q,&temp);
			print("%d ",temp);	/* ��ӡ��n-1�е�Ԫ�� */
			GetHead(Q,&x);
			temp=temp+x;	/* ���ö��е�n-1��Ԫ�ز�����n��Ԫ�� */
			EnterQueue(&Q,temp);
		}
		DeleteQueue(&Q,&x);
		printf("%d ",x);	/* ��ӡ��n-1�е����һ��Ԫ�� */
		EnterQueue(&Q,1);
	}
	while(!IsEmpty(Q))	/* ��ӡ���һ��Ԫ�� */
	{
		DeleteQueue(&Q,&x);
		printf("%d ",x);
	}
}
/* ���㷨3.23�� ��������ѭ���������㷨 */
#include<stdio.h>
#include<conio.h>
#include<queue.h>
int main()
{	/* ģ���������ѭ�������� */
	char ch1,ch2;
	SeqQueue Q;
	int f;
	InitQueue(&Q);	/* ���г�ʼ�� */
	for(;;)
	{
		for(;;)	/* ��һ������ */
		{
			printf("A");
			if(kbhit())
			{
				ch1=getch();	/* ��ȡ������ַ�������Ļ�ϲ���ʾ */
				if(ch1==';'||ch1==',') break;	/* ��һ�����������ж� */
				f=EnterQueue(&Q,ch1);
				if(f==FALSE)
				{
					printf("ѭ����������\n");
					break;	/* ѭ��������ʱ��ǿ���жϵ�һ������ */
				}
			}
		}
		while(!IsEmpty(Q))	/* �ڶ������� */
		{
			DeleteQueue(&Q,&ch2);
			putchar(ch2);	/* ��ʾ���뻺���������� */
		}
		if(ch1==';') break;	/* ����������� */
	}
	return 0;
}