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
	printf("���������鳤��\n");
	scanf("%d",&n);
	printf("����������Ԫ��\n");
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
	Linklist p,s;    //�мǲ�Ҫ���ǽ���s
	printf("������Ҫ���ڵڼ������Լ�Ҫ�������\n");
	scanf("%d%d",&i,&x);
	if(i<0||i>length_list(L))
	{
		printf("�������\n");
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
		printf("�������\n");
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
	printf("��������Ҫɾ������\n");
	scanf("%d",&i);
	if(i<0||i>length_list(L))
	{
		printf("ɾ������\n");
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
		printf("ɾ������\n");
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
	printf("������Ϊ��%d\n",length_list(L));
	insert_list(L);
	delete_list(L);
}