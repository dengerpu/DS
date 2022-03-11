#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*linklist;
void creat(linklist l)
{
	linklist p;
	int n,i;
	printf("请输入链表长度\n");
	scanf("%d",&n);
	printf("请输入链表中的元素\n");
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		/*p->next=l->next;
		l->next=p;                     //头插法*/
		l->next =p;
		l=p;
	}
	l->next =NULL;
}
void print(linklist l)   //删除重复
{
	linklist p;
	p=l->next;
	printf("链表中的元素输出为\n");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void insert(linklist l)  //插入
{
	int i,e,j;
	linklist p,q;
	p=l->next;
	printf("请输入要插在第几个以及要插入的数\n");
	scanf("%d%d",&i,&e);
	for(j=0;j<i-2;j++)
		p=p->next ;
	q=(linklist)malloc(sizeof(struct node));
	q->data=e;
	q->next =p->next ;
	p->next =q;
}
void dele(linklist l)
{
	linklist p,q;
	p=l->next;
	while(p->next !=NULL)
	{
		q=p->next ;
		if(p->data ==q->data )
		{
			p->next =q->next ;
			free(q);
		}
		else
			p=p->next ;
	}
}
void main()
{
	linklist l;
	l=(linklist)malloc(sizeof(struct node));
	//	l->next =NULL;
	creat(l);
	print(l);
	insert(l);
	print(l);
	dele(l);
	print(l);
}