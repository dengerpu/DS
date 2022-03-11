#include<stdio.h>
typedef struct lnode *list;
struct lnode
{
	int data;
	link next;
};
struct lnode l;


//���
int length(list ptrl)
{
	list *p=ptrl;
	int j=0;
	while(p)
	{
		p=p->next;
		j++;
	}
	return j;
}

//����Ų���
list find(int k,list ptrl)
{
	list *p=ptrl;
	int i=1;
	while(p!=NULL&&i<k)
	{
		p=p->next;
		i++;
	}
	if(i==k)
		return p;
	else
		return NULL;
}
//��ֵ����
list find(int e,list ptrl)
{
	list *p=ptrl;
	while(p!=NULL&&p->data/!=e)
		p=p->next;
	return p;
}

//����
list insert(int x,int i,list ptrl)
{
	list *p,*s;
	if(i==1)
	{
		s=(list)malloc((sizeof)(struct lnode));
		s->data=x;
		s->next=ptrl;
		return s;
	}
	p=find(i-1,ptrl);
	if(p==NULL)
	{
		printf("��������\n");
		return NULL;
	}
	else
	{
		s=(list)malloc(sizeof(struct lnode));
		s->data=x;
		s->next=p->next;
		p->next=s;
		return ptrl;
	}
	
	
}

//ɾ��
list dele(int i,list ptrl)
{
	list *p,*s;
	if(i==1)
	{
		s=ptrl;
		if(ptrl!=NULL)
			ptrl=ptrl->next;
		else
			return NULL;
		free(s);
		return ptrl;
	}
	p=find(i-1,ptrl);
	if(p==NULL)
	{
		printf("��%d����㲻����",i-1);
		return NULL;
	}
	else
		if(p->next==NULL)
		{
			printf("��%d����㲻����",i);
			return NULL;
		}
		else
		{
			s=p->next;
			p->next=s->next;
			free(s);
			return ptrl;
		}
}