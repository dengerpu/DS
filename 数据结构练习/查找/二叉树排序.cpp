#include<stdio.h>
typedef struct node
{
	int key;       //关键字的值
	struct node *lchild,*rchild;
}bstnode,*bstree;
void insertbst(bstree bst,int key)   //二叉排序树插入的递归算法
{
	bitree s;
	if(bst==NULL)
	{
		s=(bstree)malloc(sizeof(sizeof(bstnode)));  //申请新的结点
		s->key=key;
		s->lchild=NULL,s->rchild=NULL;
		b=s;
	}
	else if(key<bst->key)
		insertbst(&bst->lchild,key);
	else if(key>bst->key)
		insertbst(&bst->rchild,key);
}
void creatbst(bstree bst)   //创建二叉树
{
	int key;
	bst=NULL;
	scanf("%d",&key);
	while(key!=ENDKEY)  //ENDKEY为自定义常量
	{
		insertbst(bst,key);
		scanf("%d",&key);
	}
}
bstree searchbst(bstree bst,int key)  //二叉树查找递归算法
{
	if(!bst) return NULL;
	else if(bst->key==key)  return bst;  //查找成功
	else if(bst->key>key) return searchbst(bst->lchild,key); //在左子树继续查找 
	else
		return searchbst(bst->rchild,key);          //在右子树继续查找
} 
bstree searchbst(bstree bst,int key)  //二叉树查找的非递归算法
{
	bstree q;
	q=bst;
	while(q)
	{
		if(q->key==key) return q;  //查找成功
		if(q->key>key)q=q->lchild;
		else
			q=q->rchild;
	}
	return NULL;;
}
bstnode *delbst(bstree t,int k)
{
bstnode *p,*f,*s,*q;
p=t
}