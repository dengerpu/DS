//ABDG00H000CE0I00F00
#include<stdio.h>
#include<malloc.h>
int count=0,hl,hr,max,h=1,depth=0,leafcount=0;
typedef struct node 
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creatbitree()              //创建二叉树
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
		{
			printf("(");
			listbitree(root->lchild );
			if(root->rchild !=NULL)
				printf(",");
			listbitree(root->rchild );
			printf(")");
		}
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
void inorder(bitree root)  //中序遍历输出
{
	if(root!=NULL)
	{
		inorder(root->lchild );
		printf("%3c",root->data );
		inorder(root->rchild );
	}
}
void postorder(bitree root)   //后序遍历输出
{
	if(root!=NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild );
		printf("%3c",root->data );
	}
}
void yezijiedian(bitree root)  //输出结点数
{
	if(root!=NULL)
	{
		yezijiedian(root->lchild );
		yezijiedian(root->rchild );
		if(root->lchild==NULL &&root->rchild ==NULL)
			printf("%3c",root->data );
	}
}
int f1(bitree root)   //求叶子结点数目方法一
{
	if(root==NULL)
		count=0;
	else if(root->lchild ==NULL&&root->rchild ==NULL)
		count=1;
	else
		count=f1(root->lchild )+f1(root->rchild );
	return count;
}
void f2(bitree root)
{
	if(root!=NULL)
	{
		f2(root->lchild );
		f2(root->rchild );
		if(root->lchild ==NULL&&root->rchild ==NULL)
			leafcount++;
	}
}
int s1(bitree root)  //求树高度方法一
{
	if(root!=NULL)
	{
		hl=s1(root->lchild );
		hr=s1(root->rchild );
		max=hl>hr?hl:hr;
		return (max+1);
	}
	else return (0);
}
void s2(bitree root,int h)  //求树高度方法二
{
	if(root!=NULL)
	{
		if(h>depth)depth=h;
		s2(root->lchild ,h+1);
		s2(root->rchild ,h+1);
	}
}
void print(bitree root,int n)   //按树形状打印
{
	if(root==NULL) return;
	print(root->rchild ,n+1);
	for(int i=0;i<n;i++)
		printf("   ");
	printf("%c\n",root->data );
	print(root->lchild,n+1);
}
void main()
{
	bitree root;
	root=creatbitree();
	printf("\n广义表输出形式为:\n");
	listbitree(root);
	printf("\n先序遍历输出为:\n");
	preorder(root);
	printf("\n中序遍历输出为:\n");
	inorder(root);
	printf("\n后序遍历输出为:\n");
	postorder(root);
	printf("\n叶子结点为：\n");
	yezijiedian(root);
	f1(root);
	printf("叶子节点数目为：%d\n",count);
	f2(root);
	printf("叶子节点数目为：%d\n",leafcount);
	s1(root);
	printf("树的深度为%d\n",max+1);
	s2(root,1);
	printf("树的深度为%d\n",depth);
	print(root,0);
}

