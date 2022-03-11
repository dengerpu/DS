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
	int vexter;
	arcnode *firstarc;
}vexnode;
vexnode adjlist[max];
int creat()
{
	int vexnum,arcnum,i,v1,v2;
	printf("请输入顶点数和边数\n");
	scanf("%d%d",&vexnum,&arcnum);
	arcnode *ptr;
	for(i=1;i<=vexnum;i++)
		adjlist[i].firstarc =0;
	for(i=0;i<arcnum;i++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex =v2;
		ptr->next =adjlist[v1].firstarc ;
		adjlist[v1].firstarc =ptr;
		//以下四句有向图要删除
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex =v1;
		ptr->next =adjlist[v2].firstarc ;
		adjlist[v2].firstarc =ptr;
	}
	return vexnum;
}
void dfs(int v) //深度优先搜索
{
	int w;
	arcnode *p;
	p=adjlist[v].firstarc ;
	adjlist[v].vexter=1;
	printf("%d ",v);
	while(p!=NULL)
	{
		w=p->adjvex;
		if(adjlist[w].vexter==0)
			dfs(w);
		p=p->next;
	}
}
void bfs(int v)  //广度优先搜索序列
{
	int queue[max];
	int front=0,rear=1;
	arcnode *p;
	printf("%d ",v);
	p=adjlist[v].firstarc ;
	adjlist[v].vexter=1;
	queue[rear]=v;
	while(front!=rear)
	{
		front=(front+1)%max;
		v=queue[front];
		p=adjlist[v].firstarc ;
		while(p!=NULL)
		{
			if(adjlist[p->adjvex ].vexter ==0)
			{
				adjlist[p->adjvex ].vexter =1;
				printf("%d ",p->adjvex );
				rear=(rear+1)%max;
				queue[rear]=p->adjvex ;
			}
			p=p->next ;
		}
	}
}
void main()
{
	arcnode *p;
	int i,n,v;
	n=creat();
	for(i=1;i<=n;i++)
	{
		printf("==>%d",i);
		p=adjlist[i].firstarc ;
		while(p!=NULL)
		{
			printf("-->%d",p->adjvex );
			p=p->next ;
		}
		printf("\n");
	}
	printf("输入起始顶点\n");
	scanf("%d",&v);
	printf("\n深度优先搜索序列\n");
	dfs(v);
	for(i=1;i<=n;i++)
		adjlist[i].vexter=0;
	printf("\n广度优先搜索序列\n");
	bfs(v);
	printf("\n");
}