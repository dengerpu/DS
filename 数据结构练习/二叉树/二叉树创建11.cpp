#include<stdio.h>
#include<malloc.h>
int hl,hr,max,leafcount,count=0;int h=1,depth=0;
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creatbitree()   //先序创建二叉树
{
	bitree root;
	char ch;
	ch=getchar();
	if(ch=='0')root=NULL;
	else
	{
		root=(bitree)malloc(sizeof(struct node));
		root->data=ch;
		root->lchild=creatbitree();
		root->rchild=creatbitree();
	}
	return root;
} 
void listbitree(bitree root)   //广义表形式输出
{
	if(root!=NULL)
	{
		printf("%c",root->data );
		if(root->lchild !=NULL||root->rchild !=NULL)
			printf("(");
		listbitree(root->lchild );
		if(root->rchild !=NULL)
			printf(",");
		listbitree(root->rchild );
		printf(")");
	}
}
void preorder(bitree root)   //先序遍历输出
{
	if(root!=NULL)
	{
		printf("%3c",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void inorder(bitree root)   //中序遍历输出
{
	if(root!=NULL)
	{
		inorder(root->lchild );
		printf("%3c",root->data );
		inorder(root->rchild );
	}
}
void postorder(bitree root)  //后序遍历输出
{
	if(root!=NULL)
	{
		postorder(root->lchild );
		postorder(root->rchild );
		printf("%3c",root->data );
	}
}
void yezijiedian(bitree root)  //输出叶子结点数目
{
	if(root!=NULL)
	{
		yezijiedian(root->lchild );
		yezijiedian(root->rchild );
		if(root->lchild ==NULL&&root->rchild ==NULL)
			printf("%3c",root->data );
	}
}
int yezijiedianshumu(bitree root)   //求叶子结点数目方法1
{
	if(root==NULL)
		leafcount=0;
	else if(root->lchild ==NULL&&root->rchild ==NULL)
		leafcount=1;
	else
		leafcount=yezijiedianshumu(root->lchild )+yezijiedianshumu(root->rchild );
	return leafcount;
}
void yezijiedianshumu1(bitree root)  //求叶子结点数目方法2
{
	if(root!=NULL)
	{
		yezijiedianshumu(root->lchild );
		yezijiedianshumu(root->rchild );
		if(root->lchild ==NULL&&root->rchild ==NULL)
			count++;
	}
	
}
int depth1(bitree root)  //求树深度方法一
{
	if(root!=NULL)
	{
		hl=yezijiedianshumu(root->lchild );
		hr=yezijiedianshumu(root->rchild );
		max=hl>hr?hl:hr;
		return (max+1);
	}
	else return (0);
}
void depth2(bitree root,int h)  //求树深度方法二
{
	if(root!=NULL)
	{
		if(h>depth)depth=h;
		depth2(root->lchild,h+1);
		depth2(root->rchild,h+1);
	}
}
void print(bitree root,int n)   //打印树状二叉树
{
	if(root==NULL)return;
	print(root->rchild ,n+1);
	for(int i=1;i<=n;i++)
		printf("   ");
	printf("%c\n",root->data );
	print(root->lchild ,n+1);
	
}
void main()
{
	bitree root=NULL;
	printf("请用先序遍历输入，虚节点用0表示\n");
	root=creatbitree();
	printf("\n以广义表形式输出为\n");
	listbitree(root);
	printf("先序遍历输出为:\n");
	preorder(root);
	printf("\n中序遍历输出为：\n");
	inorder(root);
	printf("\n后序遍历输出为：\n");
	postorder(root);
	printf("\n叶子结点为:\n");
	yezijiedian(root);
	yezijiedianshumu(root);
	printf("\n叶子结点数目为：%d\n",leafcount);
	yezijiedianshumu1(root);
	printf("\n叶子结点数目为:%d\n",count);
	depth1(root);
	printf("\n树的深度为%d\n",max+1);
	depth2(root,h);
	printf("树的深度为%d\n",depth);
	print(root,0);
}