#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*Qnode;
typedef struct
{
	Qnode front;
	Qnode rear;
}*linkqueue;
void initlinkqueue(linkqueue l)
{
	l->front=(Qnode)malloc(sizeof(struct node));
	if(l->front!=NULL)
	{
		l->rear=l->front;
		l->front->next=NULL;
	}
}
void creat_queue(linkqueue l)
{
	Qnode p;
	int i,n;
	printf("请输入队列长度\n");
	scanf("%d",&n);
	printf("请输入队列元素\n");
	for(i=0;i<n;i++)
	{
		
		p=(Qnode)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->next=NULL;
		l->rear->next=p;
		l->rear=p;
	}
}
void enterqueue(linkqueue l)
{
	int x;
	Qnode p;
	p=(Qnode)malloc(sizeof(struct node));
	printf("请输入要入队的元素\n");
	scanf("%d",&x);
	p->data=x;
	p->next=NULL;
	l->rear->next=p;
	l->rear=p;
}
void delequeue(linkqueue l)
{
	Qnode q;
	q=l->front->next;
	l->front->next=q->next;
	free(q);
}
void out_queue(linkqueue l)
{
	Qnode p;
	p=l->front->next;
	printf("输出\n");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void main()
{
	linkqueue l;
    initlinkqueue(l);
	creat_queue(l);
	out_queue(l);
}