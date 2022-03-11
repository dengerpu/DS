#include<stdio.h>
#include<malloc.h>
typedef struct lnode
{
	int date;
	struct lnode *next;
}node,*linklist;
void creat(linklist l)
{
	linklist p;
	int i,n;
	printf("ÇëÊäÈëÁ´±íÔªËØ\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&p->date);
		l->next=p;
		l=p;
	}
	l->next =NULL;
}
void print(linklist l)
{	linklist q;
	q=l->next ;
	while(q!=NULL)
	{
		printf("%d ",q->date);
		q=q->next;
	}
	printf("\n");
}
void main()
{
	linklist l;
	l=(linklist)malloc(sizeof(lnode));
	creat(l);
	print(l);
}