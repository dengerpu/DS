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
	arcnode *ptr;
	int vexnum,arcnum,i,v1,v2;
	printf("请输入顶点和边数\n");
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
		ptr->next =adjlist[v1].firstarc ;
		adjlist[v1].firstarc =ptr;
		adjlist[v2].vertex ++;
	}
	return vexnum;
}
void topusort(int n)
{
	int i,front=0,rear=0,v,n1=0,w;
	int queue[max];
	arcnode *p;
	for(i=1;i<=n;i++)
		if(adjlist[i].vertex ==0)
		{
			rear++;
			queue[rear]=i;
		}
		while(front!=rear)
		{
			front++;
			v=queue[front];
			p=adjlist[v].firstarc ;
			printf("%d ",v);
			n1++;
			while(p!=NULL)
			{
				w=p->adjvex ;
				adjlist[w].vertex --;
				if(adjlist[p->adjvex ].vertex ==0)
				{
					rear++;
					queue[rear]=p->adjvex ;
				}
				p=p->next ;
			}
		}
		if(n1<n)
			printf("不\n");
}
void main()
{
	int n,i;
	arcnode *p;
	n=creat();
	for(i=1;i<=n;i++)
	{
		printf("%d==>",i);
		p=adjlist[i].firstarc ;
		while(p!=NULL)
		{
			printf("-->%d",p->adjvex );
			p=p->next ;
		}
		printf("\n");
	}
	topusort(n);
	printf("\n");
}