#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}bstnode,*bstree;
void insert(bstree *bst,int key)
{
	bstree s;
	if(*bst==NULL)
	{
		s=(bstree)malloc(sizeof(bstnode));
		s->key=key;
		s->lchild=NULL;s->rchild=NULL;
		*bst=s;
	}
	else if(key<(*bst)->key)
		insert(&((*bst)->lchild),key);
	else if(key>(*bst)->key)
		insert(&((*bst)->rchild),key);
}
void creat(bstree *bst)
{
	int key;
	*bst=NULL;
	scanf("%d",&key);
	while(key!=0)
	{
		insert(bst,key);
		scanf("%d",&key);
	}
}
void inorder(bstree bst)
{
	if(bst!=NULL) 
	{
		inorder(bst->lchild);
		printf("%d ",bst->key);
		inorder(bst->rchild);
	}
}
void main()
{
	bstree bst;
	creat(&bst);
	printf("中序遍历输出为\n");
	inorder(bst);
}