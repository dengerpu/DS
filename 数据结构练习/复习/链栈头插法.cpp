#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*Linkstact;
void creat_stact(Linkstact L)
{
	int i,n;
	printf("请输入栈长度\n");
	scanf("%d",&n);
	Linkstact p;
	printf("请输入元素\n");
	for(i=0;i<n;i++)
	{
		p=(Linkstact)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		L->next=p;
		L=p;
		L->next=NULL;
	}
	
}
void out_stact(Linkstact L)
{
	Linkstact p;
	p=L;
	while(p->next!=NULL)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
	printf("\n");
}
void insert_stact(Linkstact L)
{
	Linkstact p,s;
	p=L;
	int x;
	printf("请输入要插入的数\n");
	scanf("%d",&x);
	while(p->next!=NULL)
	{
		p=p->next;
	}
	s=(Linkstact)malloc(sizeof(struct node));
	s->data =x;
	p->next  =s->next ;
	p=s;
	out_stact(L);
}
void delete_stact(Linkstact L)
{
	Linkstact p;
	p=L->next;
	L->next=p->next;
	free(p);
	out_stact(L);
}
main()
{
	Linkstact L;
	L=(Linkstact)malloc(sizeof(struct node));
	creat_stact(L);
	out_stact(L);
//	insert_stact(L);
	delete_stact(L);
}