#include<stdio.h>
typedef struct lnode
{
	int data;
	linklist *next;
}linklist;
//求表长
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
//清除链表内容
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

//查找(按数字查找)
int loc(linklist *l,int e)
{
	while(l!=NULL&&l->data!=e)
		l=l->next;
	return l;
}

//查找(按序号查找)
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

//插入
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
			printf("参数错误\n");
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


//删除
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
		printf("第%d个结点不存在",i+1);
		return NULL;
	}
	else
		if(p->next==NULL)
		{
			printf("第%d个结点不存在",i);
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