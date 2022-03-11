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
}linkqueue;
void creat_queue(linkqueue l)   
{
	
	
	int i,n;
	printf("请输入队列长度\n");
	scanf("%d",&n);
	printf("请输入队列元素\n");
	for(i=0;i<n;i++)
	{
		Qnode p;
		p=(Qnode)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->next=NULL;
		l.rear->next=p;
		l.rear=p;
	}	
}
void out_queue(linkqueue l)
{
	printf("输出\n");
	Qnode p;
	p=l.front->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void enter_queue(linkqueue l)   //入队
{
	int x;
	Qnode p;
	p=(Qnode)malloc(sizeof(struct node));
	printf("请输入要入队的元素\n");
	scanf("%d",&x);
	p->data=x;
	p->next=NULL;
	l.rear->next=p;
	l.rear=p;
}
void dele_queue(linkqueue l)  //出队
{
	Qnode q;
	q=l.front->next;
	l.front->next=q->next;
	free(q);
}
void main()
{
	linkqueue l;
	l.front=l.rear=(Qnode)malloc(sizeof(struct node));
	l.front->next=NULL;
	creat_queue(l);
	out_queue(l);
	enter_queue(&l);
	out_queue(l);
	printf("出队\n");
	dele_queue(&l);
	out_queue(l);
	
}