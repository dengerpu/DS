#include<stdio.h>
#include<malloc.h>
typedef struct node    //����
{
	int adjvex;
	struct node *next;
}arcnode;
typedef struct    //ͷ���
{
	int vertex;
	arcnode *firstarc;
}vexnode;
vexnode adjlist[100];
int creat()
{
	arcnode *ptr;
	int vexnum,arcnum,i,v1,v2;
	printf("�����붥����Ŀ�ͻ��ı���\n");
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
		//���´�������ͼ����ɾ��
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
	printf("����ͼ���ڽӱ�Ϊ:\n");
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