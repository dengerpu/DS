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
int creatadjlist()
{
	arcnode *ptr;
	int arcnum,vexnum,k,v1,v2;
	printf("\n请输入顶点数和边数\n");
		scanf("%d%d",&vexnum,&arcnum);
	for(int i=1;i<=vexnum;i++)
	{
		adjlist[i].firstarc=NULL;
		adjlist[i].vertex=0;               //各顶点的入度赋初值为0
	}
	for(i=0;i<arcnum;i++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v2;
		ptr->next=adjlist[v1].firstarc;
		adjlist[v1].firstarc=ptr;
		adjlist[v2].vertex++;
	}
	return vexnum;
}
void toposort(int n)
{
	int queue[max];
	int front=0,rear=0;
	int v,w,n1;
	arcnode *p;
	n1=0;
	for(v=1;v<=n;v++)   //循环检测入度为0的顶点并入队
		if(adjlist[v].vertex==0)
		{
			rear++;
			queue[rear]=v;
		}
		printf("拓扑排序的结果：\n");
		while(front!=rear)
		{
			front++;
			v=queue[front];
			printf("%d ",v);
			n1++;
			p=adjlist[v].firstarc;
			while(p!=NULL)
			{
				w=p->adjvex;
				adjlist[w].vertex--;  //将邻接于顶点v的入度减1
				if(adjlist[w].vertex==0)
				{
					rear++;
					queue[rear]=w;
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
	n=creatadjlist();
	toposort(n);
}