#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next,*front,*rear;
}qnode,*linkqueue;
int enterlinkqueue(linkqueue p)  //����
{
	int x;
	printf("������Ҫ��ӵ�Ԫ��\n");
	scanf("%d",&x);
	linkqueue q;
	q=(linkqueue)malloc(sizeof(qnode));
	if(q!=NULL)
	{
		q->data=x;
		q->next=NULL;
		p->rear->next=q;
		p->rear=q;
	}
	return 1;
}
int dellinkqueue(linkqueue p)
{
	linkqueue q;
	if(p->front==p->rear)
	{
		printf("����Ϊ��\n");
		exit(0);
	}
	q=p->front->next;
	p->front->next=q->next;
	free(q);
	return 1;
}