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
	printf("请输入数组个数\n");
	scanf("%d",&n);
	printf("请输入数值\n");
	l=creatlist(l,n);
	printf("输出链表数据元素\n");
	p=l->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}