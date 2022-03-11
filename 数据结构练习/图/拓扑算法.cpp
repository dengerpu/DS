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
	printf("\n�����붥�����ͱ���\n");
		scanf("%d%d",&vexnum,&arcnum);
	for(int i=1;i<=vexnum;i++)
	{
		adjlist[i].firstarc=NULL;
		adjlist[i].vertex=0;               //���������ȸ���ֵΪ0
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
	for(v=1;v<=n;v++)   //ѭ��������Ϊ0�Ķ��㲢���
		if(adjlist[v].vertex==0)
		{
			rear++;
			queue[rear]=v;
		}
		printf("��������Ľ����\n");
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
				adjlist[w].vertex--;  //���ڽ��ڶ���v����ȼ�1
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