/* ������� */

/* ������ʵ�� */
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node * next;
}LinkQueueNode;
typedef struct
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;
void InitQueue(LinkQueue * Q)
{
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(!Q->front)
		return ;
	Q->rear=Q->front;
	Q->front->next=NULL;
}
void EnterQueue(LinkQueue * Q,int x)
{
	LinkQueueNode * Newbase;
	Newbase=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(!Newbase)
		return ;
	Newbase->data=x;
	Newbase->next=Q->rear->next;
	Q->rear->next=Newbase;
	Q->rear=Newbase;
}
void DeleteQueue(LinkQueue * Q,int * x)
{
	LinkQueueNode * p;
	if(Q->front==Q->rear)
		return ;
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	* x=p->data;
	free(p);
}
void GetTop(LinkQueue Q,int * x)
{
	if(Q.front==Q.rear)
		return ;
	* x=Q.front->next->data;
}
int IsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return 1;
	return 0;
}
void YangHuiTriangle(LinkQueue Q,int n)
{
	int i,j,temp,x;
	EnterQueue(&Q,1);	//��һ��Ԫ�����
	for(i=2;i<=n;i++)	//������n��Ԫ�ز���ӣ�ͬʱ��ӡ��n-1�е�Ԫ��
	{
		EnterQueue(&Q,1);	//��n�еĵ�һ��Ԫ�����
		for(j=1;j<=i-2;j++)	//���ö��е�n-1��Ԫ�ز�����n�е��м�n-2��Ԫ�ز����
		{
			DeleteQueue(&Q,&temp);
			printf("%d ",temp);	//��ӡ��n-1�е�Ԫ��
			GetTop(Q,&x);
			temp=temp+x;	//���ö��е�n-1��Ԫ�ز�����n��Ԫ��
			EnterQueue(&Q,temp);
		}
		DeleteQueue(&Q,&temp);
		printf("%d ",temp);	//��ӡ��n-1�е����һ��Ԫ��
		EnterQueue(&Q,1);	//��n�е����һ��Ԫ�����
		printf("\n");
	}
	while(!(IsEmpty(Q)))	//��ӡ���һ��Ԫ��
	{
		DeleteQueue(&Q,&temp);
		printf("%d ",temp);
	}
	printf("\n");
}
int main()
{
	LinkQueue Q;
	int n;
	InitQueue(&Q);
	printf("������Ҫ��ӡ������ǵ�������");
	scanf("%d",&n);
	YangHuiTriangle(Q,n);
	return 0;
}
*/
/* ѭ������ʵ�� */

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
	int elem[MAXSIZE];
	int front;
	int rear;
}SeqQueue;
void InitQueue(SeqQueue * Q)
{
	Q->front=Q->rear=0;
}
void EnterQueue(SeqQueue * Q,int x)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
		return ;
	Q->elem[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;
}
void DeleteQueue(SeqQueue * Q,int * x)
{
	if(Q->front==Q->rear)
		return ;
	* x=Q->elem[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
}
void GetTop(SeqQueue Q,int * x)
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return ;
	* x=Q.elem[Q.front];
}
int IsEmpty(SeqQueue Q)
{
	if(Q.rear==Q.front)
		return 1;
	return 0;
}
void YangHuiTriangle(SeqQueue Q,int n)
{
	int i,j,temp,x;
	EnterQueue(&Q,1);	//��һ��Ԫ�����
	for(i=2;i<=n;i++)	//������n��Ԫ�ز���ӣ�ͬʱ��ӡ��n-1�е�Ԫ��
	{
		EnterQueue(&Q,1);	//��n�еĵ�һ��Ԫ�����
		for(j=1;j<=i-2;j++)	//���ö��е�n-1��Ԫ�ز�����n�е��м�n-2��Ԫ�ز����
		{
			DeleteQueue(&Q,&temp);
			printf("%d ",temp);	//��ӡ��n-1�е�Ԫ��
			GetTop(Q,&x);
			temp=temp+x;	//���ö��е�n-1��Ԫ�ز�����n��Ԫ��
			EnterQueue(&Q,temp);
		}
		DeleteQueue(&Q,&temp);
		printf("%d ",temp);	//��ӡ��n-1�����һ��Ԫ��
		EnterQueue(&Q,1);	//��n�е����һ��Ԫ�����
		printf("\n");
	}
	while(!(IsEmpty(Q)))	//��ӡ���һ��Ԫ��
	{
		DeleteQueue(&Q,&temp);
		printf("%d ",temp);
	}
	printf("\n");
}
int main()
{
	SeqQueue Q;
	int n;
	InitQueue(&Q);
	printf("������Ҫ��ӡ������ǵ�������");
	scanf("%d",&n);
	YangHuiTriangle(Q,n);
	return 0;
}