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
		adjlist[v2].vertex++;
	}
	return vexnum;
}
void topusort(int n)
{
	int queue[100];
	int front=0,rear=0;
	int i,w,n1=0;
	arcnode *p;
	for(i=1;i<=n;i++)
	{
		if(adjlist[i].vertex==0)
		{
			rear++;                  //将入度为0的进入队列
			queue[rear]=i;
		}
	}
	printf("拓扑排序结果如下\n");
	while(front!=rear)
	{
		front++;
		i=queue[front];
		printf("%d ",i);
		n1++;
		p=adjlist[i].firstarc;
		while(p!=NULL)
		{
			w=p->adjvex;
			adjlist[w].vertex--;   //入度-1
			if(adjlist[w].vertex==0)
			{
				rear++;
				queue[rear]=w;
			}
			p=p->next;
		}
	}
	if(n1<n)
		printf("not set a of partial order\n");
}
void main()
{
	int n;
	n=creat();
	topusort(n);
}