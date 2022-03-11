#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	char data;
	int Ltag,Rtag;
	Node * LChild,* RChild;
}BiTNode,* BiTree;
typedef struct
{
	BiTree data[100];
	int top;
}SeqStack,* Stack;
void InitTree(BiTree root)
{
	root=(BiTree)malloc(sizeof(BiTNode));
	root->LChild=NULL;
	root->RChild=NULL;
}

void CreateTree(BiTree * bt)
{
	char ch;
	ch=getchar();
	if(ch=='.')
		(* bt)=NULL;
	else
	{
		(* bt)=(BiTree)malloc(sizeof(BiTNode));
		(* bt)->data=ch;
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
int LeafCount=0;
void leaf(BiTree bt)
{
	if(bt!=NULL)
	{
		leaf(bt->LChild);
		leaf(bt->RChild);
		if(bt->LChild==NULL && bt->RChild==NULL)
			LeafCount++;
	}
}
void PrintTree(BiTree root,int nLayer)
{
	if(root!=NULL)
	{
		PrintTree(root->RChild,nLayer+1);
		for(int i=0;i<nLayer;i++)
			printf("   ");
		printf("%c\n",root->data);
		PrintTree(root->LChild,nLayer+1);
	}
}
int PostTreeDepth(BiTree bt)
{
	int hl,hr,max;
	if(bt!=NULL)
	{
		hl=PostTreeDepth(bt->LChild);
		hr=PostTreeDepth(bt->RChild);
		max=hl>hr?hl:hr;
		return max+1;
	}
	else
		return 0;
}
int depth=0;
void PreTreeDepth(BiTree bt,int h)
{
	if(bt!=NULL)
	{
		if(h>depth)
			depth=h;
		PreTreeDepth(bt->LChild,h+1);
		PreTreeDepth(bt->RChild,h+1);
	}
}
void PreLeaf(BiTree bt)
{
	if(bt!=NULL)
	{
		if(bt->LChild==NULL && bt->RChild==NULL)
			printf("%2c",bt->data);
		PreLeaf(bt->LChild);
		PreLeaf(bt->RChild);
	}
}
void InitStack(Stack s)
{
	s->top=0;
}
void inorder(BiTree root)
{
	SeqStack s;
	BiTree p=root;
	InitStack(&s);
	do
	{
		while(p!=NULL)
		{
			if(s.top>50)
				return ;
			s.data[++s.top]=p;
			p=p->LChild;
		}
		if(s.top!=0)
		{
			p=s.data[s.top--];
			printf("%2c",p->data);
			p=p->RChild;
		}
	}while(p!=NULL || s.top!=0);
}
/*
void Push(Stack S,BiTree p)
{
	if(S->top==50)
		return ;
	S->data[++S->top]=p;
}
void Pop(Stack S,BiTree * p)
{
	if(S->top==0)
		return ;
	* p=S->data[S->top--];
}
int IsEmpty(SeqStack S)
{
	if(S.top==0)
		return 1;
	return 0;
}
void Inorder(BiTree bt)
{
	SeqStack S;
	InitStack(&S);
	BiTree p=bt;
	while(p!=NULL || !IsEmpty(S))
	{
		if(p!=NULL)
		{
			Push(&S,p);
			p=p->LChild;
		}
		else
		{
			Pop(&S,&p);
			printf("%2c",p->data);
			p=p->RChild;
		}
	}
}
void GetTop(Stack sS,BiTree * p)
{
	if(sS->top==0)
		return ;
	* p=sS->data[sS->top];
}
void Postorder(BiTree bt)
{
	BiTree p,q;
	SeqStack sS;
	InitStack(&sS);
	p=bt;
	q=NULL;
	while(p!=NULL || !IsEmpty(sS))
	{
		if(p!=NULL)
		{
			Push(&sS,p);
			p=p->LChild;
		}
		else
		{
			GetTop(&sS,&p);
			if(p->RChild==NULL || p->RChild==q)
			{
				printf("%2c",p->data);
				q=p;
				Pop(&sS,&p);
				p=NULL;
			}
			else
				p=p->RChild;
		}
	}
}
*/
BiTree pre=NULL;
void Inthread(BiTree root)
{
	if(root!=NULL)
	{
		Inthread(root->LChild);
		if(root->LChild==NULL)
		{ root->Ltag=1; root->LChild=pre; }
		if(pre!=NULL && pre->RChild==NULL)
		{ pre->RChild=root; pre->Rtag=1; }
		pre=root;
		Inthread(root->RChild);
	}
}

BiTree InPre(BiTree p)
{
	BiTree Pre=NULL,q;
	if(p->Ltag==0)
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
	BiTree Next,q;
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
	InitTree(root);
	CreateTree(&root);
	PrintTree(root,0);
	leaf(root);
	printf("\n*%d*\n",LeafCount);
	printf("\n先序遍历输出：\n");
	PreOrder(root);
	printf("\n中序遍历输出：\n");
	InOrder(root);
	printf("\n后序遍历输出：\n");
	PostOrder(root);
	printf("\n树的深度为：%d\n",PostTreeDepth(root));
	PreTreeDepth(root,0);
	printf("\n树的深度为：%d\n",depth);
	printf("\n先序遍历输出树的叶子结点：\n");
	PreLeaf(root);
	/*
	printf("\n非递归中序遍历输出二叉树：\n");
	inorder(root);
	printf("\n非递归中序遍历输出二叉树，用栈操作函数实现：\n");
	Inorder(root);
	printf("\n非递归后序遍历输出二叉树，用栈操作函数实现：\n");
	Postorder(root);
	*/
	printf("\n建立中序线索树：\n");
	Inthread(root);
	printf("遍历中序线索树：");
	TInOrder(root);
	printf("\n");
	printf("根结点结点前驱为：%c\n",InPre(root)->data);
	printf("根结点结点后继为：%c\n",InNext(root)->data);
	printf("求中序遍历的第一个结点：\n");
	printf("%c\n",InFirst(root)->data);
	printf("遍历中序线索树：");
	TInOrder(root);
}