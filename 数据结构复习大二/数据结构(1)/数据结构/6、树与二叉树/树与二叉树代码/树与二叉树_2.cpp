#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	char data;
	Node * LChild,* RChild;
	int Ltag,Rtag;
}BiTNode,* BiTree;
void CreateTree(BiTree * bt)
{
	char ch;
	ch=getchar();
	if(ch=='.')
		* bt=NULL;
	else
	{
		(* bt)=(BiTree)malloc(sizeof(BiTNode));
		(* bt)->data=ch;
		(* bt)->Ltag=0;
		(* bt)->Rtag=0;
		CreateTree(&((* bt)->LChild));
		CreateTree(&((* bt)->RChild));
	}
}
void PreOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		printf("%2c",bt->data);
		PreOrder(bt->LChild);
		PreOrder(bt->RChild);
	}
}
void InOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->LChild);
		printf("%2c",bt->data);
		InOrder(bt->RChild);
	}
}
void PostOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		PostOrder(bt->LChild);
		PostOrder(bt->RChild);
		printf("%2c",bt->data);
	}
}
BiTree pre=NULL;
void Inthread(BiTree bt)
{
	if(bt!=NULL)
	{
		Inthread(bt->LChild);
		if(bt->LChild==NULL)
		{ bt->Ltag=1; bt->LChild=pre; }
		if(pre!=NULL && pre->RChild==NULL)
		{ pre->RChild=bt; pre->Rtag=1; }
		pre=bt;
		Inthread(bt->RChild);
	}
}

BiTree InPre(BiTree p)
{
	BiTree q,Pre;
	if(p->Ltag==1)
		Pre=p->LChild;
	else
	{
		for(q=p->LChild;q->Rtag==0;q=q->RChild);
		Pre=q;
	}
	return Pre;
}
BiTree InNext(BiTree p)
{
	BiTree q,Next;
	if(p->Rtag==1)
		Next=p->RChild;
	else
	{
		for(q=p->RChild;q->Ltag==0;q=q->LChild);
		Next=q;
	}
	return Next;
}
BiTree InFirst(BiTree bt)
{
	BiTree p=bt;
	if(!p)
		return NULL;
	while(p->Ltag==0)
		p=p->LChild;
	return p;
}
void TInOrder(BiTree bt)
{
	BiTree p;
	p=InFirst(bt);
	while(p)
	{
		printf("%2c",p->data);
		p=InNext(p);
	}
}
void main()
{
	BiTree root;
	CreateTree(&root);
	printf("\n先序遍历输出二叉树：\n");
	PreOrder(root);
	printf("\n中序遍历输出二叉树：\n");
	InOrder(root);
	printf("\n后序遍历输出二叉树：\n");
	PostOrder(root);
	
	//printf("\n创建中序线索树并输出为：\n");
	Inthread(root);
	printf("前驱：%2c",InPre(root)->data);
	printf("后继：%2c",InNext(root)->data);
	printf("\n先序遍历二叉树：\n");
	TInOrder(root);
	
	printf("\n");
}