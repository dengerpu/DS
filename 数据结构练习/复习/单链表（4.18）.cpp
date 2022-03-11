#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}*Linklist;
void creat_list(Linklist L)
{
	int i,n;
	Linklist p;
	printf("请输入数组长度\n");
	scanf("%d",&n);
	printf("请输入数据元素\n");
	for(i=0;i<n;i++)
	{
		p=(Linklist)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
}
void out_list(Linklist L)
{
	Linklist p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int length_list(Linklist L)
{
	int i=0;
	Linklist p;
	p=L->next;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
void insert_list(Linklist L)
{
	int i,x,j=0;
	Linklist p,s;    //切记不要忘记借助s
	printf("请输入要插在第几个数以及要插入的数\n");
	scanf("%d%d",&i,&x);
	if(i<0||i>length_list(L))
	{
		printf("插入错误\n");
		exit(0);
	}
	p=L;
	while(j<i&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i||p==NULL)
	{
		printf("插入错误\n");
		exit(0);
	}
	
	
	s=(Linklist)malloc(sizeof(struct node));
	s->data =x;
	s->next =p->next ;
	p->next =s;
	out_list(L);
}
void delete_list(Linklist L)
{
	int i,j=0;
	Linklist p,q;
	printf("请输入需要删除的数\n");
	scanf("%d",&i);
	if(i<0||i>length_list(L))
	{
		printf("删除错误\n");
		exit(0);
	}
	p=L;
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
	q=p->next ;
	p->next =q->next ;
	free(q);
	out_list(L);
}
main()
{
	Linklist L;
	L=(Linklist)malloc(sizeof(struct node));
	L->next=NULL;
	creat_list(L);
	out_list(L);
	printf("链表长度为：%d\n",length_list(L));
	insert_list(L);
	delete_list(L);
}