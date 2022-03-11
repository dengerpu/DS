#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#define max 100
typedef struct node
{
	int a[max];
	int top;
}*seqstact;
void stactinitiate(seqstact s)
{
	s->top=-1;
}
int kong_stact(seqstact s)  //判断栈是否为空
{
	if(s->top<0)
		return 0;
	else
		return 1;
}
int enter_stact(seqstact s,int x)  //进栈
{
	if(s->top>=max)
	{
		printf("栈已满\n");
		return 0;
	}
	else
	{
		s->top++;
		s->a[s->top]=x;
		return 1;
	}
	
}
int chu_stact(seqstact s,int *x)   //出栈
{
	if(s->top<0)
	{
		printf("栈为空\n");
		return 0;
	}
	else
	{
		*x=s->a[s->top];
		s->top--;
		return 1;
	}
}
/*
红心：0-12
方块：13-25
梅花：26-38
黑桃：39-51
*/
main()
{
	seqstact s;
	s=(seqstact)malloc(sizeof(struct node));
	int i,x;
	int card[52];    //扑克牌数组
	int pos=0;        //牌代码
	long temptime;
	stactinitiate(s);
	srand(time(&temptime)%60);  //使用时间初始化随机数
	for(i=0;i<52;i++)
		card[i]=0;   //清除扑克牌数组
	i=0;
	while(i!=52)
	{
		pos=rand()%52+0;//产生随机数值0-51
		if(card[pos]==0)
		{
			enter_stact(s,pos);//存此张牌进栈
			card[pos]=1;   //设置此张牌洗过
			i++;     //进行下一张牌
		}
	}
	
	printf("1	2	3	4\n");
	printf("========================\n");
	for(i=0;i<5;i++)   //发牌给四个人的循环
	{
		chu_stact(s,&x);
		printf("[%c %2d]",x/13+3,x%13+1);
		chu_stact(s,&x);
		printf("[%c %2d]",x/13+3,x%13+1);
		chu_stact(s,&x);
		printf("[%c %2d]",x/13+3,x%13+1);
		chu_stact(s,&x);
		printf("[%c %2d]",x/13+3,x%13+1);
		printf("\n");
	}
}