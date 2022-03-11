#include<stdio.h>
#include<malloc.h>
#define max 100
typedef struct node
{
	int adjcex;
	struct node *next;
}arcnode;
typedef struct
{
	int vertex;
	arcnode *firstarc;
}vexnode;
vexnode adjlist[max];
int  creat()
{
	int vexnum,arcnum,i ,v1,v2;
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
		ptr->adjcex =v2;
		ptr->next =adjlist[v1].firstarc ;
		adjlist[v1].firstarc =ptr;
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjcex =v1;
		ptr->next =adjlist[v2].firstarc ;
		adjlist[v2].firstarc =ptr;
	}
	return vexnum;
}
void dfs(int v)   //深度优先搜索
{
	int w;
	arcnode *p;
	printf("%d ",v);
	adjlist[v].vertex=1;
	p=adjlist[v].firstarc ;
	while(p!=NULL)
	{
		w=p->adjcex  ;
		if(adjlist[w].vertex ==0)
			dfs(w);
		p=p->next ;
	}
	
}
void bfs(int v)  //广度优先搜索
{
	int queue[max];
	int front=0,rear=1;
	arcnode *p;
	queue[rear]=v;
	adjlist[v].vertex =1;
	while(front!=rear)
	{
		front++;
		v=queue[front];
		printf("%d ",v);
		p=adjlist[v].firstarc;
		while(p!=NULL)
		{
			if(adjlist[p->adjcex ].vertex ==0)
			{
				adjlist[p->adjcex ].vertex =1;
				rear++;
				queue[rear]=p->adjcex ;
			}
			p=p->next ;
			
		}
	}
}
void main()
{
	int i,n,v;
	n=creat();
	arcnode *p;
	for(i=1;i<=n;i++)
	{
		p=adjlist[i].firstarc ;
		printf("%d==>",i);
		while(p!=NULL)
		{
			printf("-->%d",p->adjcex );
			p=p->next ;
		}
		printf("\n");
	}
	printf("请输入起始搜索地点\n");
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
