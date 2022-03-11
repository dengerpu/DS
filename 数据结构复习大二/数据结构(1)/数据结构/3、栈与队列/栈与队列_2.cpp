/* ����������(˳��ջ) */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 50
typedef struct
{
	int elem[MAXSIZE];
	int top;
}SeqStack;
void InitStack(SeqStack * S)
{
	S->top=-1;
}
void Push(SeqStack * S,int x)
{
	if(S->top==MAXSIZE-1)
	{
		printf("ջ������\n");
		return ;
	}
	S->elem[++S->top]=x;
}
void Pop(SeqStack * S,int * x)
{
	if(S->top==-1)
	{
		printf("ջΪ�գ�\n");
		return ;
	}
	* x=S->elem[S->top--];
}
int GetTop(SeqStack S)
{
	if(S.top==-1)
		return 0;
	return S.elem[S.top];
}
int GetNum(char ch)
{
	return ch-'0';
}
char Compare(char ch1,char ch2)
{
	switch(ch1)
	{
		case '#':
			if(ch2=='#')
				return '=';
			return '<';
		case '+':
		case '-':
			if(ch2=='+'||ch2=='-')
				return '=';
			else if(ch2=='#')
				return '>';
			else
				return '<';
		case '*':
		case '/':
			if(ch2=='*'||ch2=='/')
				return '=';
			else if(ch2=='^')
				return '<';
			else
				return '>';
		case '^':
			if(ch2=='^')
				return '=';
			return '>';
	}
}
int Calculate(int a,char op,int b)
{
	switch(op)
	{
        case '-': return a-b;
        case '+': return a+b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a,b);
        default : return 0;
    }
}
void ExpEvaluation(SeqStack OVS,SeqStack OPTR)
{
	char ch;
	int num=0,op,a,b,v;
	Push(&OPTR,'#');
	printf("\n\nPlease input an expression(Ending with '#'):\n");
	ch=getchar();
	while(ch!='#'||(char)GetTop(OPTR)!='#')
	{
		while(ch>='0'&&ch<='9')
		{
			num=num*10+GetNum(ch);
			ch=getchar();
		}
		if(num!=0)
		{	//���num��Ϊ0���ջOVS
			Push(&OVS,num);
			num=0;	//num����Ϊ0
		}
		else
		{
			switch(Compare(ch,(char)GetTop(OPTR)))
			{	//����������ȼ����бȽϣ�ʵ�ֶ�Ӧ���ֹ�ϵ�Ĳ���
				case '>':Push(&OPTR,ch); ch=getchar(); break;
				case '=':
				case '<':
					Pop(&OPTR,&op);
					Pop(&OVS,&a);
					Pop(&OVS,&b);
					v=Calculate(b,(char)op,a);
					Push(&OVS,v);
					break;
			}
		}
	}
	v=GetTop(OVS);	//ȡջ��Ԫ�أ�����ֵ
	printf("%d\n",v);
}
void main()
{
	SeqStack OVS,OPTR;
	InitStack(&OVS);
	InitStack(&OPTR);
	ExpEvaluation(OVS,OPTR);
}