#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ERROR 0;
typedef struct lnode
{
	int data;
	struct lnode *next;
}lnode,*linklist;
int listlength(linklist l)       //求表长
{
	int i=0;
	linklist p=NULL;p=l;
	while(p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
linklist creatlist(linklist l,int n)    //输入数据
{
	int i;
	linklist p;
	for(i=1;i<=n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		p->next=l->next;
		l->next=p;
	}
	return l;
}
linklist listinsert(linklist l,int i,int e)   //插入数字
{
	int j=0;
	linklist s,p;
	p=l;
	while(!p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		printf("输入位置不合法\n");
		return l;
	}
	s=(linklist)malloc(sizeof(lnode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return l;
}
linklist listdele(linklist l,int i)   //删除
{
	int j=0;
	linklist p,s;
	p=l;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p->next==NULL&&j>i-1)
	{
		printf("输入的位置不合法\n");
		return l;
	}
	s=p->next;
	p->next=s->next;
	free(s);
	return l;
}
int getelem(linklist l,int i)   //查找第几个数为多少
{
	int j,e;
	linklist p;
	if(i<1||i>listlength(l))
	{
		printf("输入的位置不合法\n");
		return 0;
	}
	p=l->next;
	j=1;
	while(j<i)
	{
		p=p->next;
		j++;
	}
	e=p->data;
	printf("第%d位的数据元素为%d\n",i,e);
	return e;
}
void main()
{
	int n,m,i,e;
	linklist l,p;
	printf("请输入元素个数\n");
	scanf("%d",&n);
	printf("依次输入\n");
	l=creatlist(l,n);
//	printf("共有%d个元素\n",listlength(l));
	printf("请输入插在第几个数以及要插入的数值\n");
	scanf("%d%d",&i,&e);
	listinsert(l,i,e);
		p=l;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("请输入要删除第几个数\n");
	scanf("%d",&m);
	listdele(l,m);
	p=l;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}