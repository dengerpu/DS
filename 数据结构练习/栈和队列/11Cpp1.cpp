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
	printf("��������г���\n");
	scanf("%d",&n);
	printf("���������Ԫ��\n");
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
	printf("���\n");
	Qnode p;
	p=l.front->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void enter_queue(linkqueue l)   //���
{
	int x;
	Qnode p;
	p=(Qnode)malloc(sizeof(struct node));
	printf("������Ҫ��ӵ�Ԫ��\n");
	scanf("%d",&x);
	p->data=x;
	p->next=NULL;
	l.rear->next=p;
	l.rear=p;
}
void dele_queue(linkqueue l)  //����
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
	printf("����\n");
	dele_queue(&l);
	out_queue(l);
	
}