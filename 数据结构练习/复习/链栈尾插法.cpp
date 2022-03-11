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
	Linkstact p;
	printf("请输入链栈长度\n");
	scanf("%d",&n);
	printf("请输入元素\n");
	for(i=0;i<n;i++)
	{
		p=(Linkstact)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
}
void out_stact(Linkstact L)
{
	Linkstact p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void insert_stact(Linkstact L)  //进栈
{
	Linkstact p;
	int x;
	printf("请输入要进栈的元素\n");
	scanf("%d",&x);
    p=(Linkstact)malloc(sizeof(struct node));
	p->data=x;
	p->next=L->next ;
	L->next =p;
	out_stact(L);
}
void delete_stact(Linkstact L)
{
	Linkstact p;
	p=L->next;
	L->next =p->next ;
	free(p);
	out_stact(L);
}
void length_stact(Linkstact L)
{
	int i=0;
	Linkstact p;
	p=L->next ;
	while(p!=NULL)
	{
		p=p->next ;
		i++;
	}
	printf("链栈长度为%d\n",i);
}
main()
{
	Linkstact L;
	L=(Linkstact)malloc(sizeof(struct node));
	L->next=NULL;
	creat_stact(L);
	out_stact(L);
	insert_stact(L);
	delete_stact(L);
	length_stact(L);
}