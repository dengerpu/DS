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
	printf("请输入顶点数和边数 \n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
	{
		adjlist[i].firstarc =0;
		adjlist[i].vertex =0;
	}
	for(i=0;i<arcnum;i++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex =v2;
		ptr->next =adjlist[v1].firstarc  ;
		adjlist[v1].firstarc  =ptr;
		adjlist[v2].vertex ++;
	}
	return vexnum;
}
void tuopusort(int n)
{
	int queue[max];
	int front=0,rear=0,v,n1=0;
	arcnode *p;
	for(int i=1;i<=n;i++)
	{
		if(adjlist[i].vertex==0)
		{
			rear++;
			queue[rear]=i;
		}
	}
	while(front!=rear)
	{
		front++;
		v=queue[front];
		printf("%d ",v);
		n1++;
		p=adjlist[v].firstarc;
		while(p!=NULL)
		{
			v=p->adjvex;
			adjlist[v].vertex--;
			if(adjlist[v].vertex==0)
			{
				rear++;
				queue[rear]=v;
			}
			p=p->next;
		}
	}
	if(n1<n)
	printf("not a set of partial order \n");
}
void main()
{
	int n;
	n=creat();
	tuopusort(n);
}