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
	printf("������������\n");
	scanf("%d",&n);
	printf("����������Ԫ��\n");
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
	printf("������Ϊ%d\n",i);
}
void insertlist(linklist l)
{
	linklist p,s;
	p=l;
	int i,e,j=0;
	printf("������Ҫ���ڵڼ����Լ�Ҫ���������");
	scanf("%d%d",&i,&e);
while(j<i-1&&p!=NULL)
{
p=p->next;
j++;
}
if(j>i||p==NULL)
{
printf("����ʧ��\n");
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
	printf("������Ҫɾ������\n");
	scanf("%d",&i);
while(j<i-1&&p!=NULL)
{
p=p->next;
j++;
}
if(j>i||p==NULL)
{
printf("ɾ��ʧ��\n");
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