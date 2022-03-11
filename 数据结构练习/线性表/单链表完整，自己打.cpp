#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	int date;
	struct node *next;
}lnode,*linklist;
linklist creat_list(linklist L)   //创建链表
{
	linklist p;
	int i,n,t;
	printf("请输入链表长度\n");
	scanf("%d",&n);
	printf("请输入链表元素\n");
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&t);
		p->date=t;
		//L->next=p;
		//L=p;
		p->next=L->next;
		L->next=p;
	}
	//L->next=NULL;
	return 0;
}
void out_list(linklist L)   //输出链表
{
	printf("输出\n");
	linklist p;
	p=L;
	while(p->next!=NULL)
	{
		printf("%d ",p->next->date);
		p=p->next;	
	}
	printf("\n");
}
void insert_list(linklist L)   //插入
{
	int i,n,j=0;
	linklist p,s;
	p=L;
	
	printf("请输入要插在第几个数以及要插入的数\n");
	scanf("%d%d",&i,&n);
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i-1||p==NULL)
	{
		printf("插入错误\n");
		exit(0);
	}
	s=(linklist)malloc(sizeof(lnode));
	s->date=n;
	s->next=p->next;
	p->next=s;
	out_list(L);
}
void dele_list(linklist L)   //删除
{
	int i,j=0;
	linklist p,q;
	p=L;
	printf("请输入要删除第几个数\n");
	scanf("%d",&i);
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i-1||p==NULL)
	{
		printf("删除错误\n");
		exit(0);
	}
	q=p->next;
	p->next=q->next;
	free(q);
	out_list(L);	
}
void loc_list(linklist L)  //按序号查找
{
	int i,j=0,k;linklist p;
	printf("请输入要查找第几个数\n");
	p=L;
	scanf("%d",&i);
	while(j<i&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i||p==NULL||j<=0)
	{
		printf("查找错误\n");
		exit(0);
	}
	k=p->date;
	printf("第%d个数为%d\n",i,k);
}
void loc1_list(linklist L)   //按数值查找
{
	int j=0,k;
	linklist p;
	p=L;
	printf("请输入需要查找的数值\n");
	scanf("%d",&k);
	while(p!=NULL&&p->date!=k)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)
	{
		printf("查找失败\n");
		exit(0);
	}
	printf("%d为第%d个数\n",k,j);
}
void length_list(linklist L)  //链表长度
{
	linklist p;
	p=L;
	int i=0;
	while(p->next!=NULL)
	{
		p=p->next;
		i++;
	}
	printf("链表长度为%d\n",i);
}
void main()
{
	linklist L;
	L=(linklist)malloc(sizeof(lnode));
	creat_list(L);
	out_list(L);
	//length_list(L);
	insert_list(L);
	//dele_list(L);
	//loc_list(L);
	//loc1_list(L);
}