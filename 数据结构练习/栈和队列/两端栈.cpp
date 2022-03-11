#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define M 100
#define TURE 1
#define FALSE 0
typedef struct
{
	int stact[M];  //stact[M]为栈区
	int top[2];   //top[0]和top[1]为两个栈顶指示器
}dqstact;
void initstact(dqstact *s)  //初始化
{
	s->top[0]=-1;
	s->top[1]=M;
}
int push(dqstact *s,int x,int i)  //进栈操作
{
	if(s->top[0]+1==s->top[1])   //判断是否栈满
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