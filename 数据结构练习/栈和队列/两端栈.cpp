#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define M 100
#define TURE 1
#define FALSE 0
typedef struct
{
	int stact[M];  //stact[M]Ϊջ��
	int top[2];   //top[0]��top[1]Ϊ����ջ��ָʾ��
}dqstact;
void initstact(dqstact *s)  //��ʼ��
{
	s->top[0]=-1;
	s->top[1]=M;
}
int push(dqstact *s,int x,int i)  //��ջ����
{
	if(s->top[0]+1==s->top[1])   //�ж��Ƿ�ջ��
		return (FALSE);
	switch(i)
	{
	case 0:
		s->top[0]++;
		s->stact[s->top[0]]=x;break;
	case 1:
		s->top[1]--;
		s->stact[s->top[1]]=x;break;
	default:
		return(FALSE);
	}
	return(TURE);
}
int pop(dqstact *s,int *x,int i)
{
switch(i)
{
case 0:
	if(s->top[0]==-1)
		return(FALSE);
	*x=s->stact[s->top[0]];
	s->top[0]--;
	break;

case 1:
	if(s->top[1]==M)
		return(FALSE);
	*x=s->stact[s->top[1]];
	s->top[1]++;
	break;
default:
	return(FALSE);
}
return(TURE);
}