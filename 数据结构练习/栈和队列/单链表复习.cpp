#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*linklist;
void creat_list(linklist l)
{
	int i,n;
	linklist p;
	printf("������������\n");
	scanf("%d",&n);
	printf("����������Ԫ��\n");
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		l->next=p;
		l=p;
		//	p->next =l->next ;
		//	l->next =p;
	}
	l->next=NULL;
}
void out_list(linklist l)
{
	printf("���\n");
	printf("\n");
	linklist p;
	p=l->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int insert_list(linklist l)
{
	int x,i,j=0;
	linklist p,s;
	//	p=(linklist)malloc(sizeof(struct node));
	p=l;
	printf("������Ҫ���ڵڼ������Լ�Ҫ�������\n");
	scanf("%d%d",&i,&x);
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i-1||p==NULL)
	{
		printf("����ʧ��\n");
		return 0;
	}
	s=(linklist)malloc(sizeof(struct node));
	s->data=x;
	s->next=p->next;
	p->next=s;
	out_list(l);
	return 1;
}
int dele_list(linklist l)
{
	int i,j=0;
	linklist p,s;
	p=l;
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&i);
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i-1||p==NULL)
	{
		printf("����ʧ��\n");
		return 0;
	}
	s=p->next ;
	p->next =s->next ;
	free(s);
	out_list(l);
	return 1;
}
main()
{
	linklist l;
	l=(linklist)malloc(sizeof(struct node));
	//l->next=NULL;
	creat_list(l);
	out_list(l);
	insert_list(l);
	dele_list(l);
}