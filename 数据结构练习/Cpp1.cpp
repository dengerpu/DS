#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node * next;
}LinkStactNode,*LinkStact;
void InitStact(LinkStact L)  //��ʼ��ջ
{
	L=(LinkStact)malloc(sizeof(LinkStactNode));
	L->next=NULL;
}
void Push(LinkStact L,char a)   //��ջ
{
	LinkStact p;
	p->data=a;
	L->next=p;
	L=p;
	L->next=NULL;
}
int In(char ch)
{
if
}