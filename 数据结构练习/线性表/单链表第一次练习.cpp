#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct lnode
{
	int data;
	struct lnode *next;
}lnode,*linklist;
linklist creatlist(linklist l,int n)
{
	int i=0;
	linklist p=NULL,head;
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		if(l==NULL)
		{
			l=p;
			head=l;
		}
		else
		{
			l->next=p;
		}
		l=p;
	}
	l->next=NULL;
	l=head;
	return l;
}
void main()
{
	linklist p=NULL,l=NULL;
	int n;
	printf("�������������\n");
	scanf("%d",&n);
	printf("��������ֵ\n");
	l=creatlist(l,n);
	printf("�����������Ԫ��\n");
	p=l->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}