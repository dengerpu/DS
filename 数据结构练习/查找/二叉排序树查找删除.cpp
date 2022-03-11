//17 6 43 12 123 26 34 40 8 90 45 0
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}bstnode,*bstree;
void insertbst(bstree *bst,int key)
{
	bstree s;
	if(*bst==NULL)
	{
		s=(bstree)malloc(sizeof(bstnode));
		s->key=key;
		s->lchild=NULL;s->rchild=NULL;
		*bst=s;
	}
	if(key>(*bst)->key)
		insertbst(&((*bst)->rchild),key);
	if(key<(*bst)->key)
		insertbst(&((*bst)->lchild),key);
}
void creat(bstree *bst)
{
	int key;
	*bst=NULL;
	scanf("%d",&key);
	while(key!=0)
	{
		insertbst(bst,key);
		scanf("%d",&key);
	}
}
void inorder(bstree bst)
{
	if(bst==NULL)return;
	else
	{
		inorder(bst->lchild );
		printf("%d ",bst->key );
		inorder(bst->rchild );
	}
}
void print(bstree bst,int n)
{
	if(bst==NULL)return;
	print(bst->rchild ,n+1);
	for(int i=0;i<n;i++)
		printf("   ");
	printf("%d\n",bst->key );
	print(bst->lchild ,n+1);
}
/*bstree search(bstree bst,int key)
{
if(bst->key ==key) return bst;
else if(key<bst->key ) search(bst->lchild ,key);
else if(key>bst->key ) search(bst->rchild ,key);
else return NULL;
}*/
bstree search(bstree bst,int key)
{
	bstree q;
	q=bst;
	while(q!=NULL)
	{
		if(q->key ==key) return q;
		if(q->key >key)
			q=q->lchild ;
		else
			q=q->rchild ;
	}
	return NULL;
}
bstnode *delbst(bstree t,int k)
{
	bstree p,f,s,q;
	p=t;f=NULL;
	while(p)
	{
		if(p->key ==k)break;
		f=p;                            //f指向p的双亲节点
		if(p->key >k)p=p->lchild ;
		else p=p->rchild ;
	}
	if(p==NULL) return t;  //若找不到，返回原来的二叉排序树
	if(p->lchild ==NULL)     //p无左子树
	{
		if(f==NULL)t=p->lchild ;
		else if(f->lchild ==p)
			f->lchild =p->rchild ;
		else //p是f的右孩子
			f->rchild =p->rchild ;
		free(p);
	}
	else
	{  //p有左子树
		q=p; s=p->lchild ;
		while(s->rchild )  //在p的左子树中查找最右下结点
		{
			q=s;s=s->rchild ;
		}
		if(q==p)q->lchild =s->lchild ;  //将s的左子树链到q上
		else q->rchild =s->lchild ;
		p->key =s->key ;     //将s的值赋给p
		free(s);
	}
	return t;
}
void main()
{
	bstree bst,result;
	int key,k;
	printf("请输入结点，以0结束\n");
	creat(&bst);
	printf("中序遍历输出为:\n");
	inorder(bst);
	printf("按树状打印为：\n");
	print(bst,0);
	printf("请输入要查找的数\n");
	scanf("%d",&key);
	result=search(bst,key);
	if(result==NULL)
		printf("没有这个数\n");
	else
		printf("查找的这个数为%d\n",result->key );
	printf("请输入要删除的数\n");
	scanf("%d",&k);
	delbst(bst,k);
		printf("按树状打印为：\n");
	print(bst,0);
}