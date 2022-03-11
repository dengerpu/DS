#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int date;
	struct node *next;
}Linkqueuenode;
typedef struct
{
	Linkqueuenode *front;
	Linkqueuenode *rear;
}Linkqueue;
int initqueue(Linkqueue *Q)           //初始化队列
{
	Q->front=(Linkqueuenode *)malloc(sizeof(struct node));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
		return 1;
	}
	else
		return 0;
}
int enterqueue(Linkqueue *Q,int x)       //链队列入队操作
{
	Linkqueuenode *s;
	s=(Linkqueuenode *)malloc(sizeof(struct node));
	if(s!=NULL)
	{
		s->date=x;	
		Q->rear->next=s;
		Q->rear=s;
		s->next=NULL;
		return 1;
	}
	else
		return 0;
}
int deletequeue(Linkqueue *Q,int *x)     //链队出队操作
{
	Linkqueuenode *p;
	if(Q->front==Q->rear)
		return 0;
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	*x=p->date;
	free(p);
	return 1;
}
int printqueue(Linkqueue *Q)          //输出队列中的元素
{
	Linkqueuenode *p;
	p=Q->front->next ;
	if(Q->front==Q->rear)
	{
		printf("这是一个空队列\n");
		return 0;
	}
	while(p!=NULL)
	{
		printf("%d ",p->date);
		p=p->next;
	}
	printf("\n");
	return 1;
}
int main()
{
	Linkqueue Q;
	int n,i,x;
	initqueue(&Q);
	printf("请输入要入队的元素的个数\n");
	scanf("%d",&n);
	printf("请输入要入队的元素\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		enterqueue(&Q,x);
	}
	printf("队列元素输出为:\n");
	printqueue(&Q);
	printf("执行出队操作\n");
	deletequeue(&Q,&x);
	printf("出队操作为:\n");
	printqueue(&Q);
	return 0;
}