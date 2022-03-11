#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}bstnode,*bstree;
void inserbst(bstree *bst,int key)   //插入
{
	bstree s;
	if(*bst==NULL)
	{
		s=(bstree)malloc(sizeof(bstnode));
		s->key=key;
		s->lchild=NULL;s->rchild=NULL;
		*bst=s;
	}
	if((*bst)->key>key)
		inserbst(&((*bst)->lchild),key);
	if((*bst)->key<key)
		inserbst(&((*bst)->rchild),key);
}
void creat(bstree *bst)   //创建二叉排序树
{
	int key;
	*bst=NULL;
	scanf("%d",&key);
	while(key!=0)
	{
		inserbst(bst,key);
		scanf("%d",&key);
	}
}
void inorder(bstree bst)   //中序遍历
{
	if(bst==NULL)return;
	else
	{
		inorder(bst->lchild );
		printf("%d ",bst->key );
		inorder(bst->rchild );
	}
}
void print(bstree bst,int n)  //按树状打印
{
	if(bst==NULL)return;
	print(bst->rchild ,n+1);
	for(int i=0;i<n;i++)
		printf("   ");
	printf("%d\n",bst->key );
	print(bst->lchild ,n+1);
}
bstree search(bstree bst,int key)  //查找的递归算法
{
	if(bst==NULL)return NULL;
	if(bst->key ==key) return bst;
	if(bst->key <key)return search(bst->rchild ,key);
	else return search(bst->lchild ,key);
}
/*bstree search(bstree bst,int key)  //查找非递归算法
{
bstree q;
q=bst;
while(q!=NULL)
{
if(q->key ==key) return q;
if(q->key >key) q=q->lchild ;
else
q=q->rchild ;
}
return NULL;
}*/
bstree delbst(bstree t,int k)  //删除结点
{
	bstree p,f,s,q;
	p=t;f==NULL;
	while(p)
	{
		if(p->key==k)break;
		f=p;                              //f指向p的双亲节点
		if(p->key>k)p=p->lchild;
		else p=p->rchild;
	}
	if(p==NULL)return t;  //若找不到，返回原来的二叉树
	if(p->lchild==NULL)   //p无左子树
	{
		if(f==NULL) t=p->lchild;  //p是原二叉树的根
		else if(f->lchild==p)  //p是f的左孩子
			f->lchild=p->rchild;   //将p的右子树链到f的左链上
		else          //p是f的右孩子
			f->rchild=p->rchild  //将p的右子树链到f的右链上
			free(p);
	}
	else  //p有左子树
	{
		q=p;s=p->lchild;
		while(s->rchild)   //在p的左子树中查找最右下结点
		{
			q=s;
			s=s->rchild;
		}
		if(q==p)q->lchild=s->lchild;  //将s的左子树链到q上
		else q->rchild=s->lchild;
		p->key=s->key;
		free(s);
	}
	return t;
}
void main()
{
	bstree bst,result;
	int key;
	printf("请输入结点，以0为结束\n");
	creat(&bst);
	printf("中序遍历输出为:\n");
	inorder(bst);
	printf("按树状打印为\n");
	print(bst,0);
	printf("请输入要查找的数\n");
	scanf("%d",&key);
	result=search(bst,key);
	if(result==NULL)
		printf("查找不到这个数\n");
	else
		printf("查找到的数为%d\n",result->key );
}