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
int initqueue(Linkqueue *Q)           //��ʼ������
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
int enterqueue(Linkqueue *Q,int x)       //��������Ӳ���
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
int deletequeue(Linkqueue *Q,int *x)     //���ӳ��Ӳ���
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
int printqueue(Linkqueue *Q)          //��������е�Ԫ��
{
	Linkqueuenode *p;
	p=Q->front->next ;
	if(Q->front==Q->rear)
	{
		printf("����һ���ն���\n");
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
	printf("������Ҫ��ӵ�Ԫ�صĸ���\n");
	scanf("%d",&n);
	printf("������Ҫ��ӵ�Ԫ��\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		enterqueue(&Q,x);
	}
	printf("����Ԫ�����Ϊ:\n");
	printqueue(&Q);
	printf("ִ�г��Ӳ���\n");
	deletequeue(&Q,&x);
	printf("���Ӳ���Ϊ:\n");
	printqueue(&Q);
	return 0;
}