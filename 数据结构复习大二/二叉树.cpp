//ABDG00H000CE0I00F00
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creatbitree()   //创建二叉树
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
void preorder(bitree root)    //先序遍历二叉树
{
	if(root!=NULL)
	{
		printf("%3c",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void inorder(bitree root)   //中序遍历二叉树
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%3c",root->data);
		inorder(root->rchild);
	}
}
void postorder(bitree root)  //后序遍历二叉树
{
	if(root!=NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%3c",root->data);
	}
}
void yezijiedian(bitree root)
{
	if(root!=NULL)
	{
		yezijiedian(root->lchild );
		yezijiedian(root->rchild );
		if(root->lchild ==NULL&&root->rchild ==NULL)
			printf("%3c",root->data );
	}
}
void yezijiedianshumu(bitree root)
{

}
void main()
{
	bitree root;
	root=NULL;
	root=creatbitree();
	printf("先序遍历结果为\n");
	preorder(root);
	printf("\n中序遍历结果为\n");
	inorder(root);
	printf("\n后序遍历结果为\n");
	postorder(root);
	printf("叶子结点输出为：\n");
	yezijiedian(root);
	
}