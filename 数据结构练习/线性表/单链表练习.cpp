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
int length(linklist *l)         //求链表长度
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
	if(node==NULL)            //存储空间分配不成功
		return FALSE;
	node->data=e;    //生成要添加的节点
	temp=l->next;
	if(temp=NULL) //空表情况
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
	while(j<i&&temp!=NULL)   //寻找第i-1个结点
	{
		temp=temp->next;
		j++;
	}
	if(temp==NULL)   //没有找到合适的位置
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
	if(temp==BULL||temp->next==NULL)   //第i-1个结点不存在
		return FALSE;
	p=temp->next;
	temp->next=temp->next->next;
	free(p);
	return TURE;
} 