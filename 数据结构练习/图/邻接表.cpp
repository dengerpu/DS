#include<stdio.h>
#include<malloc.h>
#define max_vex 100
typedef struct node   //�������
{
	int adjvex;
	struct node *next;
}arcnode;
typedef struct          //����ͷ���
{
	int vertex;
	arcnode *firstarc;
}vexnode;
vexnode adjlist[max_vex];
int creatadjlist()
{
	arcnode *ptr;
	int arcnum,vexnum,k,v1,v2;
	printf("�����붥�����ͱ����������ʽΪ������������������");
	scanf("%d%d",&vexnum,&arcnum );    //����ͼ�Ķ������ͱ���
	for(k=1;k<=vexnum;k++)
		adjlist[k].firstarc=0;
	for(k=0;k<arcnum;k++)
	{
		printf("v1,v2=");
		scanf("%d%d",&v1,&v2);
		ptr=(arcnode *)malloc(sizeof(arcnode));
		ptr->adjvex=v2;
		ptr->next=adjlist[v1].firstarc;  //β��ʵ��
		adjlist[v1].firstarc=ptr;
        /*��������ͼ�����������ľ�Ҫɾ��*/
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
	printf("����ͼ���ڽӱ�Ϊ��\n");
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