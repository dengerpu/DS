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
int kong_stact(seqstact s)  //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top<0)
		return 0;
	else
		return 1;
}
int enter_stact(seqstact s,int x)  //��ջ
{
	if(s->top>=max)
	{
		printf("ջ����\n");
		return 0;
	}
	else
	{
		s->top++;
		s->a[s->top]=x;
		return 1;
	}
	
}
int chu_stact(seqstact s,int *x)   //��ջ
{
	if(s->top<0)
	{
		printf("ջΪ��\n");
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
���ģ�0-12
���飺13-25
÷����26-38
���ң�39-51
*/
main()
{
	seqstact s;
	s=(seqstact)malloc(sizeof(struct node));
	int i,x;
	int card[52];    //�˿�������
	int pos=0;        //�ƴ���
	long temptime;
	stactinitiate(s);
	srand(time(&temptime)%60);  //ʹ��ʱ���ʼ�������
	for(i=0;i<52;i++)
		card[i]=0;   //����˿�������
	i=0;
	while(i!=52)
	{
		pos=rand()%52+0;//���������ֵ0-51
		if(card[pos]==0)
		{
			enter_stact(s,pos);//������ƽ�ջ
			card[pos]=1;   //���ô�����ϴ��
			i++;     //������һ����
		}
	}
	
	printf("1	2	3	4\n");
	printf("========================\n");
	for(i=0;i<5;i++)   //���Ƹ��ĸ��˵�ѭ��
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