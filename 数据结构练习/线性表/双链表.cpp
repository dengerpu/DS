#include<stdio.h>
#include<malloc.h>
trpedef struct lnode
{
	struct lnode *prior;//数据前驱的指针域
	int data;      //数据域
	struct lnode *next;  //指向后继的指针域
}node,*linklist;
int creat_list(linklist l)  //建立一个空链表
{
	l=(linklist)malloc(sizeof(node));
	if(l==NULL)
	{
		printf("分配不成功\n");
		exit(0);
	}
	l->prior=l->next=NULL;
	return 0;
}
int kong(linklist l)   //判断一个链表是否为空链表
{
	if(l->prior==l->next&&l->piror==NULL)
		printf("这是一个空链表\n");
	else
		printf("这不是一个空链表\n");
	return 0;
}
int insert_list(linklist l,int i,int e)  //插入
{
	linklist p,q;
	int j=1;
	p=l;
	while(j<i&&p->next!=NULL)
	{
		j++;
		p=p->next;
	}
	if(j>i)
		printf("插入错误\n");
	q=(linklist)malloc(sizeof(node));
	if(q==NULL)
	{
		printf("分配错误\n");
		exit(0);
	}
	q->data=e;
	q->prior=p;                     //s->next=p->next;p->next->prior=s;s->prior=p;p->next=s;
	q->next=p->next;
	if(p->next!=NULL)  //不在表尾插入  ？？？？？
		p->next->prior=q;
	p->next=q;
	return ;
}
int dele_list(linklist l,int i)  //p->next=q->next;q->next->prior=p;free(q);
{
int j=1;
linklist p;
p=l->next;
while(j<i&&p!=NULL)
{
j++;
p=p->next;
} 
if(j<i||p==NULL)   //第i个结点不存在
printf("删除错误\n");
p->piror->next=p->next;



}