#include<stdio.h>
#include<stdlib.h>
typedef struct lnode
{
	int data;
	struct lnode *next;
}linklist;
//表长
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
//查找
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
//插入
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
// 删除
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
			printf("第%d个结点不存在",i-1);
			return NULL;
		}
		else
			if(p.next==NULL)
			{
				printf("第%d个结点不存在",i);
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
	printf("请输入数组长度\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p->data);
		p=p->next;
	}
	printf("%d\n",length(l));
	printf("请输入要插在第几个以及插入的数\n");
	scanf("%d%d",&k,&e);
	insert(l,k,e)
		p=l;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
		printf("请输入要删除第几个数\n");
		dele(l,i);
		p=l;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
}