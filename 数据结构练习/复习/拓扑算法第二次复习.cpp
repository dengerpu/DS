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
	printf("�����붥�����ͱ��� \n");
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
void toupusort(int n)
{
	int queue[max];
	int front=0,rear=0;
	int i,w,v,n1=0;
	arcnode *p;
	for(i=1;i<=n;i++)
		if(adjlist[i].vertex ==0)
		{
			rear++;
			queue[rear]=i;
		}
		printf("��������Ľ�����£�\n");
		while(front!=rear)
		{
			front++;
			v=queue[front];
			printf("%d ",v);
			n1++;
			p=adjlist[v].firstarc ;
			while(p!=NULL)
			{
				w=p->adjvex ;
				adjlist[w].vertex --;
				if(adjlist[w].vertex ==0)
				{
					rear++;
					queue[rear]=w;
				}
				p=p->next ;
			}
		}
		if(n1<n)
			printf("����һ����ͨͼ\n");
}
void main()
{
	int n;
	n=creat();
	toupusort(n);
	printf("\n");
}