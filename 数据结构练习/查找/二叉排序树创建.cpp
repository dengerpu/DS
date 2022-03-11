//17 6 43 12 123 26 34 40 8 90 45 0
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int  key;
	struct node *lchild,*rchild;
}bstnode,*bstree;
void insertbst(bstree *bst,int key)  //插入
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
		insertbst(&((*bst)->lchild),key);
	else if(key>(*bst)->key)
		insertbst(&((*bst)->rchild),key);
}
void creatbst(bstree *bst)    //创建二叉排序树
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
void inorder(bstree bst)   //中序遍历二叉树
{
	if(bst!=NULL)
	{
		inorder(bst->lchild );
		printf("%d ",bst->key );
		inorder(bst->rchild );
	}
}
void print(bstree bst,int n)      //按树状打印二叉树
{
	if(bst==NULL) return;
	print(bst->rchild ,n+1);
	for(int i=0;i<n;i++)
		printf("    ");
	printf("%d\n",bst->key );
	print(bst->lchild ,n+1);
}
/*bstree searchbst(bstree bst,int key)   //二叉排序树查找的递归算法
{
	if(!bst) return NULL;
	else if(bst->key ==key) return bst;
	else if(bst->key >key) return searchbst(bst->lchild ,key);
	else if(bst->key <key) return searchbst(bst->rchild ,key);
}*/
bstree searchbst(bstree bst,int key)   //二叉排序树查找的非递归算法
{
	bstree q;
	q=bst;
	while(q)
	{
		if(q->key ==key) return q;
		if(q->key >key) q=q->lchild ;
		else q=q->rchild ;
	}
	return NULL;   //查找失败
}
void main()
{
	bstree bst,result;
	int key;
	printf("建立二叉排序树，请输入序列（输入0表示结束）\n");
	creatbst(&bst);
	printf("二叉排序树中序遍历输出为:\n");
	inorder(bst);
	printf("按树状打印为:\n");
	print(bst,0);
	printf("请输入要查找的数\n");
	scanf("%d",&key);
	result=searchbst(bst,key);
	if(result!=NULL)
	{
		printf("要查找的数存在 为：%d\n",result->key );
	}
	else
		printf("要查找的数不存在\n");
}