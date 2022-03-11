#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*Linklist,Node;
void creat(Linklist L)    //创建链表
{
	Linklist p,s;
	p=L;
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		s=(Linklist)malloc(sizeof(Node));
		s->data=n;
		p->next=s;                    //尾插法
		p=s;
		scanf("%d",&n);
	}
	p->next=NULL;
}
void hebing(Linklist a,Linklist b,Linklist c)   //合并
{
	Linklist p,s,r;
	p=a->next;s=b->next;r=c;
	while(p!=NULL&&s!=NULL)
	{
		if(p->data<=s->data)     //从两个链表中选取最小的，给c的第一个
		{
			r->next=p;
			r=p;
			p=p->next;
		}
		
		else
		{
			r->next=s;
			r=s;
			s=s->next;
		}
	}
	while(p!=NULL)
	{
		r->next=p;
		r=p;
		p=p->next;
	}
	while(s!=NULL)
	{
		r->next=s;
		r=s;
		s=s->next;
	}
	r->next=NULL;
	
}
int main()
{
	Linklist a,b,c,p;
	a=(Linklist)malloc(sizeof(Node));
	b=(Linklist)malloc(sizeof(Node));
	c=(Linklist)malloc(sizeof(Node));
	creat(a);
	creat(b);
	hebing(a,b,c);
	p=c->next;
	if(p==NULL)
		printf("NULL");
	while(p!=NULL)
	{
		printf("%d",p->data);
		if(p->next !=NULL)
			printf(" ");
		p=p->next;
	}
	return 0;
}