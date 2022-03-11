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
void initqueue(linkqueue *l)
{
	l->front=(Qnode)malloc(sizeof(struct node));
	l->rear=l->front;
	l->front->next=NULL;
}
void enterqueue(linkqueue *l,int e)
{
	Qnode p;
	p=(Qnode)malloc(sizeof(struct node));
	p->data=e;
	p->next=NULL;
	l->rear->next=p;
	l->rear=p;
}
void deletequeue(linkqueue *l,int *a)
{
	Qnode p;
	p=l->front->next;
	*a=p->data;
	l->front->next=p->next;
	free(p);
}
void gethead(linkqueue *l,int *x)
{
	*x=l->front->next->data;
}
int isempty(linkqueue *l)
{
	if(l->front==l->rear)
		return 1;
	else
		return 0;
}
main()
{
	int i,j,x,temp,n;
	scanf("%d",&n);
	linkqueue l;
	initqueue(&l);
	enterqueue(&l,1);   //第一行元素入队
	for(i=2;i<=n;i++)
	{
		enterqueue(&l,1);
		for(j=1;j<=i-2;j++)
		{
			deletequeue(&l,&temp);
			printf("%d",temp);
			gethead(&l,&x);
			temp+=x;
			enterqueue(&l,temp);
		}
		deletequeue(&l,&x);
		printf("%d\n",x);
		enterqueue(&l,1);
	}
	while(!isempty(&l))
	{
	deletequeue(&l,&x);
	printf("%d",x);
	}
}