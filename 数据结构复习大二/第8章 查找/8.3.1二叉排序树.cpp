#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int key;
	struct *lchild,*rchild;
}bstnode,*bstree;
void Inserbst(bstree bst,int key)
{
	bstree s;
	if(bst==NULL)
	{
		s=(bstree)malloc(sizeof(bstree));
		s->key=key;
		s->lchild=NULL;
		s->rchild=NULL;
		bst=s;
	}
	else if(key<bst->key)
		Inserbst(bst,key);
	else if(bst->key<key)
		Inserbst(bst,key);
}
void creat_bstree(bstnode *bst)
{
	int key;
	bst=NULL;
	scanf("%d",&key);
	while(key!=-1)
	{
		Inserbst(bst,key);
		scanf("%d",&key);
	}	
}
void inorder(bstree bst)
{
	if(bst!=NULL)
	{
		inorder(bst->lchild);
		printf("%d  ",bst->key);
		inorder(bst->rchild);
	}
}
int main()
{
	bstree bst;
	bst=(bstree)malloc(sizeof(bstree));
	creat_bstree(bst);
	printf("中序遍历输出为\n");
	inorder(bst);
	return 0;
}