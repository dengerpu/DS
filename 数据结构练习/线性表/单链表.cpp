#include<stdio.h>
typedef struct lnode
{
	int data;
	linklist *next;
}linklist;
//���
int length(linklist *l)
{
	int i=0;
	while(l->next!=NULL)
	{
		i++;
		l=l->next;
	}
	return i;
}
//�����������
int delelink(linklist *l)
{
	linklist *t
		while(l->next!=NULL)
		{
			t=l->next;
			l->next=l->next->next;
			free(t);
		}
		return 0;
}

//����(�����ֲ���)
int loc(linklist *l,int e)
{
	while(l!=NULL&&l->data!=e)
		l=l->next;
	return l;
}

//����(����Ų���)
int loc(linklist *l,int k)
{
	int i=1;
	while(l!=NULL&&i<k)
	{
		l=l->next;
		i++;
	}
	if(i==k)
		return l;
	else
		return NULL;
}

//����
int insert(linklist *l,int i,int e)
{
	linklist *s,*p;
	if(i==1)
	{
		s=(linklist)maloc(sizeof(linklist));
		s->data=x;
		s->next=l;
		return s;
	}
	p=loc(l,i-1)
		if(p==NULL)
		{
			printf("��������\n");
			return NULL;
		}
		else
		{
			s=(linklst)malloc(sizeof(linklist));
			s->data=e;
			s->next=p->next;
			p->next=s;
			return s;
		}
}


//ɾ��
int dele(linklist *l,int i)
{
	linklist *p,*s;
	if(i==1)
	{
		s=l;
		if(l!=NULL)
			l=l->next;
		else
			return NULL;
		free(s);
		return l;
	}
	p=loc(l,i-1);
	if(p==NULL)
	{
		printf("��%d����㲻����",i+1);
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
			return l;
		}
		
}