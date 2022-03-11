#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int date;
	struct node *next;
}Node,Linklist;
void initlist(Linklist *L)           //初始化链表
{
	L=(Linklist *)malloc(sizeof(struct node));
	L->next=NULL;
}
void creatlist(Linklist *L)        //创建链表
{
	int n,i,e;
	Linklist *p,*s;
	p=L;
	printf("请输入链表的长度\n");
	scanf("%d",&n);
	printf("请输入链表中的元素\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		s=(Linklist *)malloc(sizeof(struct node));
		s->date=e;
		p->next=s;
		p=s;
		p->next=NULL;
	}
}
void printlist(Linklist *L)   //输出链表
{
	Linklist *p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->date);
		p=p->next;
	}
	printf("\n");
}
Linklist * get(Linklist *L,int i) //在链表中查找第i个元素
{
	Linklist *p;int j;
	if(i<0)
	{printf("查找不合法");return NULL;}
	p=L;j=0;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(i==j)
		return p;
	else
		return NULL;
}
int insertlist(Linklist *L,int i,int e)         //插入操作
{
	Linklist *p,*s;
	int k;
	if(i<0) return 0;
	p=L;k=0;
	while(p!=NULL&&k<i-1)
	{
		p=p->next;
		k++;
	}
	if(p==NULL)
	{
		printf("插入位置不合法\n");return 0;
	}
	s=(Linklist *)malloc(sizeof(struct node));
	s->date=e;
	s->next=p->next;
	p->next=s;
	return 1;
}
int dellist(Linklist *L,int i,int *e)    //删除操作
{
	Linklist *p,*s;
	int k;
	p=L;k=0;
	while(p->next!=NULL&&k<i-1)
	{
		p=p->next;k++;
	}
	if(p->next==NULL)
	{
		printf("删除结点的位置i不合理");
		return 0;
	}
	s=p->next;
	p->next=s->next;
	*e=s->date;
	free(s);
	return 1;
}
int main()
{
	int i,e;
	Linklist L,*p;
	initlist(&L);
	creatlist(&L);
	printf("创建的链表为:");
	printlist(&L);
	printf("请输入要查找链表中的第几个数\n");
	scanf("%d",&i);
	p=get(&L,i);
	printf("第%d个元素为%d\n",i,p->date);
	printf("请输入插在第几个数以及要插入的值\n");
	scanf("%d%d",&i,&e);
    insertlist(&L,i,e);
	printf("插入后的链表为:");
	printlist(&L);
	printf("请输入要删除第几个数\n");
	scanf("%d",&i);
	dellist(&L,i,&e);
	printf("删除后的链表为\n");
	printlist(&L);
	return 0;
}
