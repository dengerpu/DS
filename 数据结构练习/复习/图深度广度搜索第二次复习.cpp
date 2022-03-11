#include<stdio.h>
#include<malloc.h>
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
vexnode adjlist[100];
int creat()
{
	int vexnum,arcnum,i,v1,v2;
	printf("请输入顶点数和边数\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		adjlist[i].firstarc =0;
	arcnode *ptr;
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
void dfs(int v)   //深度优先搜索序列
{
	int w;
	arcnode *p;
	printf("%d ",v);
	adjlist[v].vertex =1;
	p=adjlist[v].firstarc ;
	while(p!=NULL)
	{
		w=p->adjvex ;
		if(adjlist[w].vertex ==0)
			dfs(w);
		p=p->next ;
	}
}
void bfs(int v)  //广度优先搜索
{
	int queue[100],front=0,rear=1;
	queue[rear]=v;
	printf("%d ",v);
	arcnode *p;
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
	int i,n;
	int v;
	n=creat();
	arcnode *p;
	for(i=1;i<=n;i++)
	{
		printf("%d==>",i);
		p=adjlist[i].firstarc ;
		while(p!=NULL)
		{
			printf("-->%d",p->adjvex);
			p=p->next;
		}
		printf("\n");
	}
	printf("请输入起始顶点v\n");
	scanf("%d",&v);
	printf("深度优先搜索\n");
	dfs(v);
	printf("\n");
	for(i=1;i<=n;i++)
		adjlist[i].vertex =0;
	printf("广度优先搜索\n");
	bfs(v);
	printf("\n");
	
}