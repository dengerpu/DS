#include<stdio.h>
#include<malloc.h>
#define max 100
typedef struct node
{
	int a[max];
	int front,rear;
}*queue;
void initqueue(queue l)
{
	l->front=-1;
	l->rear=-1;
}
void creat_queue(queue l)
{
	int i,n;
	printf("请输入队列长度\n");
	scanf("%d",&n);
	l->front=1;
	l->rear=n;
	printf("请输入队列元素\n");
	for(i=l->front;i<=l->rear;i++)
		scanf("%d",&l->a[i]);
	
}
void out_queue(queue l)
{
	int i;
	for(i=l->front;i<=l->rear;i++)
		printf("%d ",l->a[i]);
	printf("\n");
}
void enter_queue(queue l)
{
	int x;
	printf("请输入要进队的元素\n");
	scanf("%d",&x);
	l->rear++;
	l->a[l->rear]=x;
	out_queue(l);
}
void push_queue(queue l)
{
	l->rear--;
	out_queue(l);
}
main()
{
	queue l;
	l=(queue)malloc(sizeof(struct node));
	//initqueue(l);
	creat_queue(l);
	out_queue(l);
	enter_queue(l);
	push_queue(l);
}