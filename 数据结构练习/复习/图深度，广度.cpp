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
	int vexnum,arcnum,v1,v2,i;
	arcnode *ptr;
	printf("请输入顶点数和边数\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
	{
		adjlist[i].firstarc=0;
		adjlist[i].vertex=0;
	}
	for(i=0;i<arcnum;i++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
	ptr=(arcnode *)malloc(sizeof(struct node));
	ptr->adjvex=v2;
	ptr->next=adjlist[v1].firstarc;
	adjlist[v1].firstarc=ptr;
	ptr=(arcnode *)malloc(sizeof(struct node));
	ptr->adjvex=v1;
	ptr->next=adjlist[v2].firstarc;
	adjlist[v2].firstarc=ptr;
	}
	return vexnum;
}
void dfs(int v)   //图的深度优先遍历
{
	int w;
	arcnode *p;
	printf("%d ",v);
	adjlist[v].vertex=1;
	p=adjlist[v].firstarc;
	while(p!=NULL)
	{
		w=p->adjvex;
		if(adjlist[w].vertex==0)
			dfs(w);
		p=p->next;
	}
}
void bfs(int v)   //图的广度优先搜索遍历
{
	int queue[max];
	int front,rear,w;
	front=0;rear=1;
	queue[rear]=v;
	adjlist[v].vertex=1;
	arcnode *p;
	while(front!=rear)

	{
		front++;
		v=queue[front];
		printf("%d ",v);
		p=adjlist[v].firstarc;
		while(p!=NULL)
		{
			w=p->adjvex;
			if(adjlist[w].vertex==0)
			{
				adjlist[w].vertex=1;
				rear++;
				queue[rear]=w;
			}
			p=p->next;
		}
	}
}
void main()
{
	int n,v;
	n=creat();
	arcnode *p;
	for(int i=1;i<=n;i++)
	{
		printf("%d==>",i);
		p=adjlist[i].firstarc;
		while(p!=NULL)
		{
			printf("-->%d",p->adjvex );
			p=p->next;
		}
		printf("\n");
	}
	printf("请输入源点、\n");
	scanf("%d",&v);
	printf("图的深度优先搜索遍历为\n");
	 dfs(v);
	for(i=1;i<=n;i++)
		adjlist[i].vertex=0;
	printf("图的广度优先搜索遍历为\n");
	bfs(v);
}