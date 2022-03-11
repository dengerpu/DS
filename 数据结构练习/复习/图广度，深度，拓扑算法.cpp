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
	int vertex;
	arcnode *firstarc;
}vexnode;
vexnode adjlist[max];
int creat()
{
	int vexnum,arcnum,i,v1,v2;
	arcnode *ptr;
	printf("请输入顶点数和边数\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		adjlist[i].firstarc=0;
	for(i=0;i<arcnum;i++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex =v2;
		ptr->next =adjlist[v1].firstarc ;
		adjlist[v1].firstarc =ptr;
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex =v1;
		ptr->next =adjlist[v2].firstarc ;
		adjlist[v2].firstarc =ptr;
	}
	return vexnum;
}
void dfs(int v)    //深度优先搜索
{
	arcnode *p;
	int w;
	printf("%d ",v);
	p=adjlist[v].firstarc ;
	adjlist[v].vertex =1;
	while(p!=NULL)
	{
		w=p->adjvex ;
		if(adjlist[w].vertex ==0)
			dfs(w);
		p=p->next ;
	}
}
void bfs(int v)   //广度优先搜索
{
	int queue[max];
	int front=-1,rear=0;
	arcnode *p;
	queue[rear]=v;
	printf("%d ",v);
	adjlist[v].vertex =1;
	while(front!=rear)
	{
		front++;
		v=queue[front];	
		p=adjlist[v].firstarc ;
		while(p!=NULL)
		{
			if(adjlist[p->adjvex ].vertex ==0)
			{
				adjlist[p->adjvex ].vertex =1;
				printf("%d ",p->adjvex );
				rear++;
				queue[rear]=p->adjvex ;
			}
			p=p->next ;
		}
	}
}
void main()
{
	int n,i,v;
	n=creat();
	arcnode *p;
	for(i=1;i<=n;i++)
	{
		printf("%d==>",i);
		p=adjlist[i].firstarc  ;
		while(p!=NULL)
		{
			printf("-->%d",p->adjvex );
			p=p->next ;
		}
		printf("\n");
	}
	printf("请输入起始顶点\n");
	scanf("%d",&v);
	dfs(v);
	printf("\n");
	for(i=1;i<=n;i++)
		adjlist[i].vertex =0;
	bfs(v);
}