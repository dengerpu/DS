#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ERROR 0;
typedef struct lnode
{
	int data;
	struct lnode *next;
}lnode,*linklist;
int listlength(linklist l)       //���
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
linklist creatlist(linklist l,int n)    //��������
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
linklist listinsert(linklist l,int i,int e)   //��������
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
		printf("����λ�ò��Ϸ�\n");
		return l;
	}
	s=(linklist)malloc(sizeof(lnode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return l;
}
linklist listdele(linklist l,int i)   //ɾ��
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
		printf("�����λ�ò��Ϸ�\n");
		return l;
	}
	s=p->next;
	p->next=s->next;
	free(s);
	return l;
}
int getelem(linklist l,int i)   //���ҵڼ�����Ϊ����
{
	int j,e;
	linklist p;
	if(i<1||i>listlength(l))
	{
		printf("�����λ�ò��Ϸ�\n");
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
	printf("��%dλ������Ԫ��Ϊ%d\n",i,e);
	return e;
}
void main()
{
	int n,m,i,e;
	linklist l,p;
	printf("������Ԫ�ظ���\n");
	scanf("%d",&n);
	printf("��������\n");
	l=creatlist(l,n);
//	printf("����%d��Ԫ��\n",listlength(l));
	printf("��������ڵڼ������Լ�Ҫ�������ֵ\n");
	scanf("%d%d",&i,&e);
	listinsert(l,i,e);
		p=l;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&m);
	listdele(l,m);
	p=l;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}