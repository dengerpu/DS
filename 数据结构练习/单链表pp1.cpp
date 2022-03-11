#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*linklist;
void initlist(linklist l)
{
	l=(linklist)malloc(sizeof(struct node));
	l->next=NULL;
}
void creatlist(linklist l)
{
	linklist p;
	int n,i;
	printf("请输入链表长度\n");
	scanf("%d",&n);
	printf("请输入链表元素\n");
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		l->next=p;
		l=p;
	}
	l->next=NULL;
}
void outlist(linklist l)
{
	linklist p;
	p=l->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
void lengthlist(linklist l)
{
	int i=0;
	linklist p;
	p=l->next;
	while(p!=NULL)
	{
		i++;
		p=p->next ;
	}
	printf("链表长度为%d\n",i);
}
void insertlist(linklist l)
{
	linklist p,s;
	p=l;
	int i,e,j=0;
	printf("请输入要插在第几个以及要插入的数字");
	scanf("%d%d",&i,&e);
while(j<i-1&&p!=NULL)
{
p=p->next;
j++;
}
if(j>i||p==NULL)
{
printf("插入失败\n");
}
	s=(linklist)malloc(sizeof(struct node));
	s->data=e;
	s->next =p->next ;
	p->next =s;
	outlist(l);
}
void deletelist(linklist l)
{
	linklist p,s;
	p=l;
	int i,e,j=0;
	printf("请输入要删除得数\n");
	scanf("%d",&i);
while(j<i-1&&p!=NULL)
{
p=p->next;
j++;
}
if(j>i||p==NULL)
{
printf("删除失败\n");
}
s=p->next ;
p->next =s->next ;
free(s);
outlist(l);
}
void main()
{
	linklist l;
	l=(linklist)malloc(sizeof(struct node));
	//	l->next=NULL;
	creatlist(l);
	outlist(l);
	lengthlist(l);
	insertlist(l);
	deletelist(l);
}