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
void creat_queue(linkqueue l)
{
	int i,n;
	printf("��������г���\n");
	scanf("%d",&n);
	
	printf("���������Ԫ��\n");
	for(i=0;i<n;i++)
	{
		Qnode p;
		p=(Qnode)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->next=NULL;
		l->rear->next=p;
		l->rear=p;
	}
}
void out_queue(linkqueue l)
{
	Qnode p;
	p=l->front->next;
	printf("���\n");
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
	l=(Qnode)malloc(sizeof(node));
	l->rear->next=NULL;
	creat_queue(l);
	out_queue(l);
}
