#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *next;
}*Linklist,Node;
Linklist initlinklist(Linklist L)   //初始化链表，创建一个空的链表
{
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;
	return L;
}m
void creat(Linklist L)         //头插法建立链表
{
	Linklist p,s;
	p=L;
	char c;
	c=getchar();
	while(c!='$')
	{
		s=(Linklist)malloc(sizeof(struct node));
		s->data=c;
		s->next=p->next;
		p->next=s;
		c=getchar();
	}
} 
void print(Linklist L)   //输出链表
{
	Linklist p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}
void main()
{
	Linklist L,p;
	L=initlinklist(p);  
	creat(L);
	print(L);
}