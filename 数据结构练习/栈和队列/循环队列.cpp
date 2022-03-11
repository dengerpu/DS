#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define max 100
typedef struct queue
{
	int a[max];
	int front,rear;
}*sequeue;
void initqueue()
{
	sequeue p;
	p->front=0;
	p->rear=0;
}
void enter_queue(sequeue q)  //进队
{
	int x;
	printf("请输入要插入的元素\n");
	scanf("%d",&x);
	if((q->front+1)%max==q->rear)
	{
		printf("队列为空\n");
		exit(0);
	}
	q->rear=(q->rear+1)%max;
	q->a[q->rear]=x;
}
void delqueue(sequeue q)  //出队
{
	if(q->front==q->rear)
	{
		printf("队列为空\n");
		exit(0);
	}
	q->front=(q->front+1)%max;
}