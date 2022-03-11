/* 顺序栈类型结构定义 */
typedef int StackElementType
#define Stack_Size 50	/* 设栈中元素个数为50 */
#define TRUE 1
#define FALSE 0
typedef struct
{
	StackElementType elem[Stack_Size];	/* 用来存放栈中元素的一维数组 */
	int top;	/* 用来存放栈顶元素的下标，top为-1表示空栈 */
}SeqStack;
/* 【算法3.1】	初始化顺序栈 */
void InitStack(SeqStack * S)
{	/* 构造一个空栈 */
	S->top=-1;
}
/* 【算法3.2】	顺序栈进栈运算 */
int Push(SeqStack * S,StackElementType x)
{	/* 将x置入S栈新栈顶 */
	if(S->top==Stack_Size-1)	return (FALSE);	/* 栈已满 */
	S->top++;
	S->elem[S->top]=x;	/* x进栈 */
	return (TRUE);
}
/* 【算法3.3】	顺序栈出栈运算 */
int Pop(SeqStack * S,StackElementType * x)
{	/* 将S栈顶元素弹出，放到x所指的存储空间中带出 */
	if(S->top==-1)	return (FALSE);	/* 栈为空 */
	else
	{
		* x=S->elem[S->top];	/* 栈顶元素赋给x */
		S->top--;	/* 修改栈顶元素 */
		return (TRUE);
	}
}
/* 【算法3.4】	顺序栈读栈顶元素运算 */
int GetTop(SeqStack * S,StackElementType *x)
{	/* 将栈S栈顶元素读出，放到x所指的存储空间中，栈顶指针保持不变 */
	if(S->top==-1)	return (FALSE);	/* 栈为空 */
	else
	{
		* x=S->elem[S->top];	/* 栈顶元素赋给x */
		return (TRUE);
	}
}
/***************************************************************/
/* 多栈共享技术 */
/* 两栈共享类型结构定义 */
typedef int StackElementType
#define M 100
#define TRUE 1
#define FALSE 0
typedef struct
{
	StackElementType Stack[M];	/* Stack[M]为栈区 */
	StackElementType top[2];	/* top[0]和top[1]分别为两个栈顶指示器 */
}DqStack;
/* 【算法3.5】	双端顺序栈初始化 */
void InitStack(DqStack * S)
{
	S->top[0]=-1;
	S->top[1]=M;
}
/* 【算法3.6】	双端顺序栈进栈操作 */
int Push(DqStack * S,StackElementType x,int i)
{	/* 把数据元素x压入i号堆栈 */
	if(S->top[0]+1==S->top[1])	return (FALSE);	/* 栈已满 */
	switch(i)
	{
		case 0:		/* 0号栈 */
			S->top[0]++;
			S->Stack[S->top[0]]=x;break;
		case 1:		/* 1号栈 */
			S->top[1]--;
			S->Stack[S->top[1]]=x;break;
		default:	/* 参数错误 */
			return (FALSE);
	}
	return (TRUE);
}
/* 【算法3.7】	双端顺序栈出栈操作 */
int Pop(DqStack * S,StackElementType * x,int i)
{	/* 从i号栈堆中弹出栈顶元素并送到x中 */
	switch (i);
	{
		case 0:	/* 从0号栈出栈 */
			if(S->top[0]==-1)	return -1;
			* x=S->Stack[S->top[0]];
			S->top[0]--;break;
		case 1:	/* 1号栈出栈 */
			if(S->top[1]==M)	return (FALSE);
			* x=S->Stack[S->top[1]];
			S->top[1]++;break;
		default:
			return (FALSE);
	}
	return (TRUE);
}
/***************************************************************/
/* 链栈类型结构定义 */
typedef int StackElementType
#define TRUE 1
#define FALSE 0
typedef struct node
{
	StackElementType data;
	struct node * next;
}LinkStackNode;
typedef LinkStackNode * LinkStack;
/* 【算法3.8】	链栈进栈操作 */
int Push(LinkStack top,StackElementType x)
/* 将数据元素x压入栈top中 */
{
	LinkStackNode * temp;
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
	if(temp==NULL)	return (FALSE);	/* 申请空间失败 */
	temp->data=x;
	temp->next=top->next;
	top->next=temp;	/* 修改当前栈顶指针 */
	return (TRUE);
}
/* 【算法3.9】	链栈出栈操作 */
int Pop(LinkStack top,StackElementType * x)
{	/* 将栈top的栈顶元素弹出，放到x所指的存储空间中 */
	LinkStackNode * temp;
	temp=top->next;
	if(temp==NULL)	return (FALSE);	/* 栈为空 */
	top->next=temp->next;
	* x=temp->data;
	free(temp);	/* 释放存储空间 */
	return (TRUE);
}
/***************************************************************/
/* 多栈运算 多栈类型结构定义 */
#define M 10	/* M个链栈 */
typedef int StackElementType
typedef struct node
{
	StackElementType data;
	struct node * next;
}LinkStackNode,* LinkStack;
LinkStack top[M];
/***************************************************************/
/* 栈的应用举例 */
/* 【算法3.10】	括号匹配算法 */
void BracketMatch(char * str)
/* str[]中为输入的字符串，利用堆栈技术来检查该字符串中的括号是否匹配 */
{
	Stack S; int i; char ch;
	InitStack(&S);
	for(i=0;str[i]!='\0';i++)	/* 对字符串中的字符逐一扫描 */
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
				{ printf("\n右括号多余！"); return ; }
				else
				{
					GetTop(&S,&ch);
					if(Match(ch,str[i]))	/* 用Match判断两个括号是否匹配 */
						Pop(&S,&ch);	/* 已匹配的左括号出栈 */
					else
					{ printf("\n对应的左右括号不同类！"); return ;}
				}
		}/* switch */
	}/*for*/
	if(IsEmpty(S))
		printf("\n括号匹配！");
	else
		printf("\n左括号多余！");
}
/* 【算法3.11】 无括号算术表达式处理方法 */
int ExpEvaluation()
/* 读入一个简单算术表达式并计算其值。OPTR和OVS分别为运算符栈和运算数栈，OPSet为运算符集合 */
{
	InitStack(&OPTR);
	InitStack(&OVS);
	Push(&OPTR,'#');	/* 为方便操作，首先将#压入OPTR栈 */
	printf("\n\nPlease input an expression (Ending with #) :");
	ch=getchar();
	while(ch!='#'||GetTop(OPTR)!='#')	/* GetTop()通过函数值返回栈顶元素 */
	{
		if(!In(ch,OPSet))	/* 不是操作符，是操作数，进OVS栈 */
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
				case '<':Pop(&OPTR,&op);	/* 形成运算 */
				Pop(&OVS,&b);
				Pop(&OVS,&a);
				v=Execute(a,op,b);	/* 对a和b进行op运算 */
				Push(&OVS,v);
				break;
			}
	}
	v=GetTop(OVS);
	return (v);
}
/* 【算法3.12】 汉诺塔递归算法 */
void hanoi(int n,char x,char y,char z)
/* 将塔座x上从上到下编号为1至n，且按直径由小到大叠放的n个圆盘，按规则搬到塔座z上，y用作辅助塔座 */
{
	if(n==1)
		move(x,1,z);	/* 将编号为1的圆盘从x移动z */
	else
	{
		hanoi(n-1,x,z,y);	/* 将x上编号为1至n-1的圆盘移到y，z作辅助塔 */
		move(x,n,z);	/* 将编号为n的圆盘从x移到z */
		hanoi(n-1,y,x,z);	/* 将y上编号为1至n-1的圆盘移到z，x作辅助塔 */
	}
}
/* 【算法3.13】 斐波那契数列的非递归算法 */
int Fib(int n)
{
	int x,y,z;
	if(n==0||n==1)	return n;	/* 计算Fib(0)或Fib(1) */
	else
	{
		x=0,y=1;	/* x=Fib(0) y=Fib(1) */
		for(i=2;i<=n;i++)
		{
			z=y;	/* z=Fib(i-1) */
			y=x+y;	/* y=Fib(i-1)+Fib(i-2),求Fib(i) */
			x=z;	/* x=Fib(i-1) */
		}
		return y;
	}
}
/* 【算法3.14】 求n!的递归算法 */
long Fact(int n)
{
	if(n==1)	return 1;
	return n*Fact(n-1);
}
/* 【算法3.15】 求n!非递归算法 */
long Fact(int n)
{
	int fac=1;
	for(int i=1;i<=n;i++)	/* 依次计算f(1),...,f(n) */
		fac=fac*i;	/* f(i)=f(i-1)*i */
	return fac;
}
/***************************************************************/
/* 链队列类型结构定义 */
#define TRUE 1
#define FLASE 0
typedef int QueueElementType;
typedef struct Node
{
	QueueElementType data;	/* 数据域 */
	struct Node * next;	/* 指针域 */
}LinkQueueNode;
typedef struct
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;
/* 【算法3.16】 链队列初始化*/
int InitQueue(LinkQueue * Q)
{	/* 将Q初始化为一个空的链队列 */
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
		return (TRUE);
	}
	else
		return (FALSE);	/* 溢出！ */
}
/* 【算法3.17】 链队列入队操作算法*/
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
		return (FALSE);	/* 溢出！ */
}
/* 【算法3.18】 链队列出队操作算法*/
int DeleteQueue(LinkQueue * Q,QueueElementType * x)
{	/* 将队列Q的队头元素出队，并存放到x所指的存储空间中 */
	LinkQueueNode * p;
	if(Q->rear==Q->front)
		return (FALSE);
	p=Q->front->next;
	Q->front->next=p->next;	/* 队头元素p出队 */
	if(Q->rear==p)	/* 如果队中只有一个元素p，则p出队后成为空队 */
		Q->rear=Q->front;
	* x=p->data;
	free(p);	/* 释放存储空间 */
	return (TRUE);
}
/***************************************************************/
/* 循环队列类型结构定义 */
#define MAXSIZE 50	/* 队列的最大长度 */
typedef int QueueElementType;
typedef struct
{
	QueueElementType element[MAXSIZE];	/* 队列的元素空间 */
	int front;	/* 头指针指示器 */
	int rear;	/* 尾指针指示器 */
}SeqQueue;
/* 【算法3.19】 循环队列初始化操作*/
void InitQueue(SeqQueue * Q)
{	/* 将* Q初始化为一个空的循环队列 */
	Q->front=Q->rear=0;
}
/* 【算法3.20】 循环队列入队操作*/
int EnterQueue(SeqQueue * Q,QueueElementType x)
{	/* 将元素x入队 */
	if((Q->rear+1)%MAXSIZE==Q->rear)	/* 尾指针加1追上头指针，标志队列已经满了 */
		return (FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;	/* 重新设置队尾指针 */
	return (TRUE);	/* 操作成功 */
}
/* 【算法3.21】 循环队列出队操作*/
int DeleteQueue(SeqQueue * Q,QueueElementType * x)
{
	if(Q->front==Q->rear)	/* 队列为空 */
		return (FALSE);
	* x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;	/* 重新设置队头指针 */
	return (TRUE);	/* 操作成功 */
}
/* 【算法3.22】 打印杨辉三角形前n行元素算法*/
void YangHuiTriangle()
{
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q,1);	/* 第一行元素入队 */
	for(n==2;n<=N;n++)	/* 产生第n行元素并入队，同时打印第n-1行的元素 */
	{
		EnterQueue(&Q,1);	/* 第n行的第一个元素入队 */
		for(i=1;i<n-2;i++)	/* 利用队中第n-1行元素产生的第n行的中间n-2个元素并入队 */
		{
			DeleteQueue(&Q,&temp);
			print("%d ",temp);	/* 打印第n-1行的元素 */
			GetHead(Q,&x);
			temp=temp+x;	/* 利用队中第n-1行元素产生第n行元素 */
			EnterQueue(&Q,temp);
		}
		DeleteQueue(&Q,&x);
		printf("%d ",x);	/* 打印第n-1行的最后一个元素 */
		EnterQueue(&Q,1);
	}
	while(!IsEmpty(Q))	/* 打印最后一行元素 */
	{
		DeleteQueue(&Q,&x);
		printf("%d ",x);
	}
}
/* 【算法3.23】 键盘输入循环缓冲区算法 */
#include<stdio.h>
#include<conio.h>
#include<queue.h>
int main()
{	/* 模拟键盘输入循环缓冲区 */
	char ch1,ch2;
	SeqQueue Q;
	int f;
	InitQueue(&Q);	/* 队列初始化 */
	for(;;)
	{
		for(;;)	/* 第一个进程 */
		{
			printf("A");
			if(kbhit())
			{
				ch1=getch();	/* 读取键入的字符，但屏幕上不显示 */
				if(ch1==';'||ch1==',') break;	/* 第一个进程正常中断 */
				f=EnterQueue(&Q,ch1);
				if(f==FALSE)
				{
					printf("循环队列已满\n");
					break;	/* 循环队列满时，强制中断第一个进程 */
				}
			}
		}
		while(!IsEmpty(Q))	/* 第二个进程 */
		{
			DeleteQueue(&Q,&ch2);
			putchar(ch2);	/* 显示输入缓冲区的内容 */
		}
		if(ch1==';') break;	/* 整个程序结束 */
	}
	return 0;
}