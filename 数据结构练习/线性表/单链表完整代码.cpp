#include<stdio.h>
#include<stdlib.h>
typedef struct lnode
{
	int data;
	struct lnode *next;
}linklist;
//��
int length(linklist l)
{

	int i=0;
	while(l.next!=NULL)
	{
		l=l.next;
		i++;
	}
	return i;
}
//����
linklist chazhao(linklist l,int k)
{
	linklist p;
	p=l;
	int i=1;
	while(p!=NULL&&i<k)
	{
		p=p.next;
		i++;
	}
	if(i==k)
		return p;
	else
		return NULL;
}
//����
linklist insert(linklist l,int i,int e)
{
	linklist p,s;
	if(i==1)
	{
		s=(linklist)malloc(sizeof(struct lnode));
		s.data=e;
		s.next=l
			return s;
	}
	p=chazhao(l,i-1)
		
		else
	{
		s=(linklist)malloc(sizeof(struct lnode));
		s.data=e;
		s.next=p.next;
		p.next=s;
		return l;
	}
}
// ɾ��
linklist dele(linklist l,int i)
{
	linklist p,s;
	p=chazhao(l,i-1);
	if(i==1)
	{
		s=l;
		if(l!=NULL)
			l=l.next;
		else
			return NULL;
		free(s);
		return l;
	}
	else
	{
		if(p==NULL)
		{
			printf("��%d����㲻����",i-1);
			return NULL;
		}
		else
			if(p.next==NULL)
			{
				printf("��%d����㲻����",i);
				return NULL;
			}
			else
			{
				s=p.next;
				p.next=s.next;
				free(s);
				return l;
			}	
	}
}
void main()
{
	linklist l;
	linklist *p;
	p=l;
	int n,i,k,e,x;
	printf("���������鳤��\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p->data);
		p=p->next;
	}
	printf("%d\n",length(l));
	printf("������Ҫ���ڵڼ����Լ��������\n");
	scanf("%d%d",&k,&e);
	insert(l,k,e)
		p=l;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
		printf("������Ҫɾ���ڼ�����\n");
		dele(l,i);
		p=l;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
}