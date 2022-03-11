#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define max 100
typedef struct queue 
{
	int a[max];
	int front,rear;
}*sequeue;
void init_sequeue()  //初始化队列
{
	sequeue q;
	q->front=-1;
	q->rear=-1;
}
void entersequeue(sequeue p)  //入队
{
	int x;
	printf("请输入插入的数\n");
	scanf("%d",&x);
	if(p->rear>max-1)
	{
		printf("插入失败\n");
		exit(0);
	}
	else
	{
		p->a[p->rear]=x;
		p->rear++;
	}
}
void delsequeue(sequeue p)  //出队
{
	if(p->front==p->rear)
	{
		printf("队列为空\n");
		exit(0);
	}
	else
	{
		p->front++;
	}
	
}
void creat_queue(sequeue p)
{
	int i,n;
	printf("请输入队列元素数目:\n");
	scanf("%d",&n);
	p->front=0;
	p->rear=n;
	printf("请输入队列元素\n");
	for(i=p->front;i<p->rear;i++)
		scanf("%d",&p->a[i]);
}
void out_queue(sequeue p)
{
	int i;
	if(p->front!=p->rear)
	{
		printf("输出队列元素\n");
		for(i=p->front;i<p->rear;i++)
			printf("%d ",p->a[i]);
	}
	printf("\n");
	
}
void main()
{
	sequeue p;
	p=(sequeue)malloc(sizeof(struct queue));
	creat_queue(p);
	out_queue(p);
	entersequeue(p);
	out_queue(p);
	delsequeue(p);
	out_queue(p);
	
}
