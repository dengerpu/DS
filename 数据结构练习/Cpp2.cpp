#include<stdio.h>
#include<malloc.h>
#define maxsize 100
typedef struct node
{
	char stact[maxsize];
	int top;
}*seqstact;
int initstact(seqstact s)
{
	if((s=(seqstact)malloc(sizeof(struct node)))==NULL) return 0;
	s->top=-1;
	return 1;
}
int push(seqstact s,char x)
{
	if(s->top>=maxsize-1) return 0;
	s->top++;
	s->stact[s->top]=x;
	return 1;
}
int pop(seqstact s,char ch)
{
	if(s->top<0) return 0;
	ch=s->stact [s->top ];
	s->top --;
	return (ch);
}
int gettop(seqstact s)
{
	if(s->top<0) return 0;
	return (s->stact[s->top]);
}
int empty(seqstact s)
{
	if(s->top<0)return 1;
	else
		return 0;
}
int In(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		return 1;
	else
		return 0;
}
int operate(int a,char theta,int b)
{
	if(theta=='+')
		return (a+b);
	if(theta=='-')
		return(a-b);
	if(theta=='*')
		return (a*b);
	if(theta=='/')
		return(a/b);
	
}
char Precede(char a,char b)
{
	char c;
	if(a=='#'&&(b=='+'||b=='-'||b=='*'||b=='/'))
	{
		c='>';
		return (c);
	}
	if((a=='+'||a=='-')&&(b=='*'||b=='/'))
	{
		c='<';
		return (c);
	}
	if((a=='*'||a=='/')&&(b=='+'||b=='-'))
	{
		c='>';
		return (c);
	}
	if((a=='+'||a=='-')&&(b=='+'||b=='-'))
	{
		c='=';
		return (c);
	}
	if((a=='*'||a=='/')&&(b=='+'||b=='-'))
	{
		c='=';
		return (c);
	}
}
int main()
{ 
int a,b,v,temp;
char theta;
char ch;  //ch���ڱ��������ʽ���ַ�
seqstact optr,opnd;  //OPTR�����ջ��OPND������ջ
initstact(optr);initstact(opnd);
push(optr,'#');
ch=getchar();
while(ch!='#'||gettop(optr)!='#')
{
	if(!In(ch))  //�����ж��ַ��Ƿ�Ϊ������������������1���ǲ���������0
	{
		{
			//������ֵ���ʱ����
			temp=ch-'0';   //���ַ�ת��Ϊʮ������
			ch=getchar();
		}
		while(!In(ch))
		{
			temp=temp*10+ch-'0';ch=getchar();   //��ÿ������Ĳ�������λת��Ϊʮ������
		}
		push(opnd,temp);  //����������Ľ�ջ
	}
	else
	{
		switch(Precede(gettop(optr),ch))
		{
		case'<':push(optr,ch);ch=getchar();break;
		case'=':pop(optr,ch);ch=getchar();break;
		case'>':pop(optr,theta);pop(opnd,b);pop(opnd,a);
			push(opnd,operate(a,theta,b));break;
		}
		v=gettop(opnd);
		printf("%d\n",v);
	}
}
return 0;
}