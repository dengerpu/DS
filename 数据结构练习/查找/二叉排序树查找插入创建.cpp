//17 6 43 12 123 26 34 40 8 90 45 0
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}bstnode,*bstree;
void insertbst(bstree *bst,int key)    //插入
{
	bstree s;
	if(*bst==NULL)
	{
		s=(bstree)malloc(sizeof(bstnode));
		s->key=key;
		s->lchild=NULL;
		s->rchild=NULL;
		*bst=s;
	}
	if(key>(*bst)->key)
		insertbst(&((*bst)->rchild),key);
	if(key<(*bst)->key)
		insertbst(&((*bst)->lchild),key);
}
void creat(bstree *bst)   //创建二叉排序树
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
void inorder(bstree bst)   //中序遍历
{
	if(bst==NULL)return;
	else
	{
		inorder(bst->lchild );
		printf("%d ",bst->key );
		inorder(bst->rchild);
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
/*bstree searchbst(bstree bst,int key)   //查找递归算法
{
	if(bst==NULL) return NULL;
	else if(bst->key ==key) return bst;
	else if(bst->key >key) return searchbst(bst->lchild ,key);
	else if(bst->key <key) return searchbst(bst->rchild ,key);
}*/
bstree searchbst(bstree bst,int key)          //查找非递归算法
{
	bstree q;
	q=bst;
	while(q!=NULL)
	{
		if(q->key ==key) return q;
		if(q->key >key) q=q->lchild ;
		else q=q->rchild ;
	}
	return NULL;
}
void main()
{
	bstree bst,result;
	int key;
	printf("请输入结点,以0结束\n");
	creat(&bst);
	printf("中序遍历输出为\n");
	inorder(bst);
	printf("按树状打印为:\n");
	print(bst,0);
	printf("请输入要查找树的关键字\n");
	scanf("%d",&key);
	result=searchbst(bst,key);
	if(result==NULL)
		printf("查找不到这个数\n");
	else printf("查找的数为%d\n",result->key );
}