#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *next;
}*Linklist,Node;
Linklist initlinklist(Linklist L)   //��ʼ����������һ���յ�����
{
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;
	return L;
}m
void creat(Linklist L)         //ͷ�巨��������
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
void print(Linklist L)   //�������
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