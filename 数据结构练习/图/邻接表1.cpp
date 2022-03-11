#include<stdio.h>
#include<malloc.h>
typedef struct node    //表结点
{
	int adjvex;
	struct node *next;
}arcnode;
typedef struct    //头结点
{
	int vertex;
	arcnode *firstarc;
}vexnode;
vexnode adjlist[100];
int creat()
{
	arcnode *ptr;
	int vexnum,arcnum,i,v1,v2;
	printf("请输入顶点数目和弧的边数\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		adjlist[i].firstarc =0;
	for(i=0;i<arcnum;i++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v2;
		ptr->next=adjlist[v1].firstarc;
		adjlist[v1].firstarc=ptr;
		//以下代码有向图可以删除
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v1;
		ptr->next=adjlist[v2].firstarc;
		adjlist[v2].firstarc=ptr;
	}
	return vexnum;
}
void main()
{
	int i,n;
	n=creat();
	arcnode *p;
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
	
}