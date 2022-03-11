#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
void creatbitree(bitree bt)
{
	char ch;
	ch=getchar();
	if(ch=='0') bt=NULL;
	else
	{
		bt=(bitree)malloc(sizeof(struct node));
		bt->data=ch;
		creatbitree(bt->lchild);
		creatbitree(bt->rchild);
	}
}
void preorder(bitree bt)
{
	if(bt!=NULL)
	{
		printf("%3c ",bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
void main()
{
	bitree bt;
    creatbitree(bt);
	preorder(bt);
}