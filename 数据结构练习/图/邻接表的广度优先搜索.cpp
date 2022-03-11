#include<stdio.h>
#include<malloc.h>
#define max 100
typedef struct node
{
	int adjvex;
	struct node *next;
}arcnode;
typedef struct
{
	int vextex;
	arcnode *firstarc;
}vexnode;
vexnode adjlist[max];
int creat()
{
	int vexnum,arcnum,i,v1,v2;
	arcnode *ptr;
	printf("�����붥�����ͱ���\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		adjlist[i].firstarc=0;
	for(i=0;i<arcnum;i++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v2;
		ptr->next=adjlist[v1].firstarc;
		adjlist[v1].firstarc=ptr;
		//����ͼ��һ�����д��룬Ҫɾ��
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v1;
		ptr->next=adjlist[v2].firstarc;
		adjlist[v2].firstarc=ptr;
	}
	return vexnum;
}
void bfs(int v)
{
	int queue[max];
	int front=0,rear=1;
	arcnode *p;
	p=adjlist[v].firstarc ;
	printf("%d",v);
	adjlist[v].vextex =1;
	queue[rear]=v;
	while(front!=rear)
	{
		front=(front+1)%max;
		v=queue[front];
		p=adjlist[v].firstarc ;
		while(p!=NULL)
		{
			if(adjlist[p->adjvex ].vextex ==0)
			{
				adjlist[p->adjvex ].vextex =1;
				printf("%d",p->adjvex );
				rear=(rear+1)%max;
				queue[rear]=p->adjvex ;
			}
			p=p->next ;
		}
	}
}
void main()
{
	int i,n,v;
	arcnode *p;
	n=creat();
	printf("����ͼ���ڽӱ�Ϊ��\n");
	for(i=1;i<=n;i++)
	{
		printf("%d==>",i);
		p=adjlist[i].firstarc;
		while(p!=NULL)
		{
			printf("-->%d",p->adjvex);
			p=p->next;
		}
		printf("\n");
	}
	printf("����������������ʼ����v:");
	scanf("%d",&v);
	printf("ͼ�Ĺ��������������bfs:");
	bfs(v);
	printf("\n");
}