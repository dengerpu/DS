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
		adjlist[i].firstarc=0;
	for(i=0;i<arcnum;i++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v2;
		ptr->next=adjlist[v1].firstarc;
		adjlist[v1].firstarc=ptr;
		//以下四行有向图可以删除
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v1;
		ptr->next=adjlist[v2].firstarc;
		adjlist[v2].firstarc=ptr;
	}
	return vexnum;
}
void dfs(int v)
{
	int w;
	arcnode *p;
	p=adjlist[v].firstarc;
	printf("%d  ",v);
	adjlist[v].vexter=1;
	while(p!=NULL)
	{
		w=p->adjvex;
		if(adjlist[w].vexter==NULL	9)
			dfs(w);
		p=p->next;
	}
	
}
void main()
{
	int i,v,n;
	arcnode *p;
	n=creat();
	printf("所建图的邻接表为:\n");
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
	printf("输入图深度优先搜索的第一个顶点\n");
	scanf("%d",&v);
	printf("图的优先搜索序列\n");
	dfs(v);
	printf("\n");
}