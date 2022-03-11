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
void initlinkqueue(linkqueue *l)
{
	l->front=(Qnode)malloc(sizeof(struct node));
	l->rear=l->front;
	l->front->next=NULL;
}
void creat_queue(linkqueue *l)
{
	int i,n;
	Qnode p;
	
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
void out_queue(linkqueue *l)
{
	printf("输出\n");
	Qnode p;
	p=l->front->next;
	while(p!=NULL)
	{
		printf("%3d",p->data);
		p=p->next;
	}
	printf("\n");
}
void dele_linkqueue(linkqueue *l)
{
	Qnode p;
	p=l->front->next;
	l->front->next =p->next;
	free(p);
	out_queue(l);
}
void enter_linkqueue(linkqueue *l)
{
	int x;
	Qnode p;
	p=(Qnode)malloc(sizeof(struct node));
	printf("请输入要进队的元素\n");
	scanf("%d",&x);
	p->data =x;
	p->next =NULL;
	l->rear ->next=p;
	l->rear =p;
	out_queue(l);
}
/*void gethead(linkqueue *l,int *x)
{
	*x=l->front->next->data;
	printf("%d\n",*x);
}*/
main()
{
	linkqueue l;
//	int x;
	initlinkqueue(&l);
	printf("%请输入队列长度\n");
	creat_queue(&l);
	out_queue(&l);
//	gethead(&l,&x);
	enter_linkqueue(&l);
	dele_linkqueue(&l);
}