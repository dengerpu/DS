#include<stdio.h>
#include<malloc.h>
#define max_vex 100
typedef struct node   //定义表结点
{
	int adjvex;
	struct node *next;
}arcnode;
typedef struct          //定义头结点
{
	int vertex;
	arcnode *firstarc;
}vexnode;
vexnode adjlist[max_vex];
int creatadjlist()
{
	arcnode *ptr;
	int arcnum,vexnum,k,v1,v2;
	printf("请输入顶点数和边数（输入格式为：顶点数，边数）：");
	scanf("%d%d",&vexnum,&arcnum );    //输入图的顶点数和边数
	for(k=1;k<=vexnum;k++)
		adjlist[k].firstarc=0;
	for(k=0;k<arcnum;k++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(arcnode));
		ptr->adjvex=v2;
		ptr->next=adjlist[v1].firstarc;  //尾插实现
		adjlist[v1].firstarc=ptr;
        /*对于有向图，接下来的四句要删除*/
		/*	
		ptr=(arcnode*)malloc(sizeof(arcnode));
		ptr->adjvex=v1;
		ptr->next=adjlist[v2].firstarc;
		adjlist[v2].firstarc=ptr;
		*/
	}
	return (vexnum);
}
void main()
{
	int i,n;
	arcnode *p;
	n=creatadjlist();
	printf("所建图的邻接表为：\n");
	for(i=1;i<=n;i++)
	{
		printf("%d==>",i);
		p=adjlist[i].firstarc;
		while(p!=NULL)
		{
			printf("---->%d",p->adjvex);
			p=p->next;
		}
		printf("\n");
	}
}