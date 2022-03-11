#include<stdio.h>
#include<stdlib.h>
typedef struct lnode
{
	int data;
	struct lnode *next;
}linklist;
int clear(linklist *l)
{
	linklist *temp;
	temp=l->next;
	while(temp->next!=NULL)
		temp=l->next;
	l->next=l->next->next;
	free(temp);
}
int length(linklist *l)         //��������
{
	int len=0;
	linklist *temp;
	temp=l;
	while(temp->next!=NULL)
	{
		len++;
		temp=temp->next;
	}
	return len;
}
int loc(linklist *l,int e)
{
	int i=1;
	linklist *temp;
	temp=l->next;
	while(temp!=NULL&&temp->data!=e)
	{
		i++;
		temp=temp->next;
	}
	if(temp==NULL)
		return 0;
	else
		return i;
}
int insert(linklist *l,int i,int e)
{
	int j=1;
	linklist *node,*temp;
	node=(linklist)malloc(sizeof(linklist));
	if(node==NULL)            //�洢�ռ���䲻�ɹ�
		return FALSE;
	node->data=e;    //����Ҫ��ӵĽڵ�
	temp=l->next;
	if(temp=NULL) //�ձ����
	{
		if(i==0)
		{
			l->next=node;
			node->next=NULL;
			return TURE;
		}
		else
			return FALSE;
	}
	while(j<i&&temp!=NULL)   //Ѱ�ҵ�i-1�����
	{
		temp=temp->next;
		j++;
	}
	if(temp==NULL)   //û���ҵ����ʵ�λ��
		return FALSE;
	node->next=temp->next;
	temp->next=node;
	return TURE;
	
}

int dele(linklist *l,int i)
{
	linklist *temp,*p;
	int j=1;
	temp=l;
	if(temp==NULL)
		return FALSE;
	while(j<i-1&&temp!=NULL)   
	{
		j++;
		temp=temp->next;
	}
	if(temp==BULL||temp->next==NULL)   //��i-1����㲻����
		return FALSE;
	p=temp->next;
	temp->next=temp->next->next;
	free(p);
	return TURE;
} 