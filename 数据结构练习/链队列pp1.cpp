#include<stdio.h>
#include<malloc.h>
typedef struct node 
{
	int data;
	struct node *next;
}*queue;
typedef struct
{
	queue front;
	queue rear;
}linkqueue;
void initqueue(linkqueue *q)
{
	q->front=(queue)malloc(sizeof(struct node));
	q->rear=q->front;
	q->front->next=NULL;
}
void creatqueue(linkqueue *q)
{
	queue p;
	
	int n,i;
	printf("��������г���\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(queue)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->next=NULL;
		q->rear->next=p;
		q->rear=p;
	}
}
void outqueue(linkqueue *q)
{
	printf("���\n");
	queue p;
	p=q->front->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void lengthqueue(linkqueue *q)
{
	queue p;int j=0;
	p=q->front ->next;
	while(p!=NULL)
	{
		j++;
		p=p->next;
	}
	printf("���г���Ϊ%d\n",j);
}
void gettop(linkqueue *q)
{
	printf("��ͷԪ��Ϊ%d\n",q->front ->next->data);
}
void insertqueue(linkqueue *q)
{
	int n;
	printf("������Ҫ��ӵ�Ԫ��\n");
	scanf("%d",&n);
	queue p;
	p=(queue)malloc(sizeof(struct node));
	p->data=n;
	p->next=NULL;
	q->rear->next=p;
	q->rear=p;
	outqueue(q);
}
void deletequeue(linkqueue *q)
{
	queue p;
	p=q->front ->next;
	printf("���ӵ�Ԫ��Ϊ%d\n",p->data);
	q->front ->next=p->next;
	free(p);
	outqueue(q);
}
main()
{
	linkqueue q;
	initqueue(&q);
	creatqueue(&q);
	outqueue(&q);
	lengthqueue(&q);
	gettop(&q);
	insertqueue(&q);
	deletequeue(&q);
}