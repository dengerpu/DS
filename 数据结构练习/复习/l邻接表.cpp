#include<stdio.h>
#include<malloc.h>
#define max 50
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
	int vexnum,arcnum,v1,v2,i;
	arcnode *ptr;
	printf("�����붥�����ͱ���\n");
	scanf("%d%d",&vexnum,&arcnum);
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
		//��������ͼ�������ľ�Ҫɾ��
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v1;
		ptr->next=adjlist[v2].firstarc;
		adjlist[v2].firstarc=ptr;
	}
	return vexnum;
}
void main()
{
	int n;
	n=creat();
	arcnode *p;
	printf("����ͼ���ڽӱ�Ϊ:\n");
	for(int i=1;i<=n;i++)
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