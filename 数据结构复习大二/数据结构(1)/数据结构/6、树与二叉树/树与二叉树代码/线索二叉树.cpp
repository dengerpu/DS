#include "stdio.h"											//**************************************//
#include "stdlib.h"											//
typedef struct node											//该代码按上所示书打的，能完全遍历完线索二叉树
{															//但有点瑕疵，不知道在哪。//注：是书上的代码，不仅仅是你发生这种情况。
	int ltag,rtag;											//
	char data;												//**************************************//
	struct node * lchild;
	struct node * rchild;
}bitnode,* bitree;
bitree p;
bitree pre=NULL;
bitree creat()												//建树
{
	bitree t;
	char e;
	scanf("%c",&e);
	if(e=='.')
		t=NULL;
	else
	{
		t=(bitree)malloc(sizeof(bitnode));												
		t->data=e;
		t->lchild=creat();
		t->rchild=creat();
	}
	return t;
}
void inthread(bitree p)										//线索化
{
	if(p)
	{
		p->ltag=0;
		p->rtag=0;
		inthread(p->lchild);
		if(p->lchild == NULL)
		{
			p->ltag=1;
			p->lchild=pre;
		}
		if(pre && pre->rchild == NULL)
		{
			pre->rtag=1;
			pre->rchild=p;
		}
		pre=p;
		inthread(p->rchild);
	}
}
bitree inpre(bitree p)											//前驱
{
	bitree q,k;
	if(p->ltag==1)
		k=p->lchild;
	else
	{
		for(q=p->lchild;q->rtag==0;q=q->rchild)
			k=q;
	}
	return k;
}
bitree innext(bitree p)											//后继
{
	bitree k,q;
	if(p->rtag==1)
		k=p->rchild;
	else
	{
		for(q=p->rchild;q->ltag==0;q=q->lchild);
			k=q;
	}
	return k;
}
bitree infirst(bitree p)									//配合innext  详情见tinorder
{
	bitree k=p;
	if(!k) return NULL;
	while(k->ltag==0)
		k=k->lchild;
	return k;
}
void tinorder(bitree p)
{
	bitree k;
	k=infirst(p);					//调用infirst
	while(k)
	{
		printf("%c",k->data);
		k=inpre(k);				//调用innext			想调用inpre要自己编一个inlast从后面开始遍历找前驱。
	}
}
void main()
{
	p=creat();
	inthread(p);
	tinorder(p);
}