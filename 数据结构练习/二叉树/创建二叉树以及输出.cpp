//ABDG00H000CE0I00F00
#include<stdio.h>
#include<malloc.h>
int count=0,hl=0,hr=0,max=0;
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creatbitree()
{
	bitree root;
	char ch;
	ch=getchar();
	if(ch=='0')root=NULL;
	else
	{
		root=(bitree)malloc(sizeof(struct node));
		root->data=ch;
		root->lchild =creatbitree();
		root->rchild =creatbitree();
	}
	return root;
}
void listbitree(bitree root)
{
	if(root!=NULL)
	{
		printf("%c",root->data );
		if(root->lchild!=NULL||root->rchild!=NULL)
		{
			printf("(");
			listbitree(root->lchild );
			if(root->rchild!=NULL)
				printf(",");
			listbitree(root->rchild );
			printf(")");
		}
	}
}
void preorder(bitree root)
{
	if(root!=NULL)
	{
		printf("%3c",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void inorder(bitree root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%3c",root->data);
		inorder(root->rchild);
	}
}
void postorder(bitree root)
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
		if(root->lchild ==NULL&&root->rchild ==NULL)
			printf("%3c",root->data );
		yezijiedian(root->lchild );
		yezijiedian(root->rchild );
	}
}
int yezishumu(bitree root)
{
	yezishumu(root->lchild );
	yezishumu(root->rchild );
	if(root->lchild ==NULL&&root->rchild ==NULL)
		count++;
	return count;
}
int yezishumu2(bitree root)
{
	if(root==NULL)
		count=0;
	else if((root->lchild ==NULL)&&(root->rchild==NULL ))
		count=1;
	else
		count=yezishumu2(root->lchild)+yezishumu2(root->rchild );
	return count;
}
int depth(bitree root)
{
	if(root!=NULL)
	{
		hl=depth(root->lchild );
		hr=depth(root->rchild );
		max=hl>hr?hl:hr;
		return(max+1);
	}
	else
		return 0;
}
void depth2(bitree root,int h)
{
	if(root!=NULL)
	{
		if (h>max)max=h;
		depth2(root->lchild ,h+1);
		depth2(root->rchild ,h+1);
	}
}
void print(bitree root,int n)
{
	if(root==NULL)return;
	print(root->rchild ,n+1);
	for(int i=0;i<n;i++)
		printf("   ");
	printf("%c\n",root->data );
	print(root->lchild ,n+1);
}
void main()
{
	
	bitree root=NULL;
	printf("请输入先序序列，虚节点用0表示\n");
	root=creatbitree();
	printf("广义表输出：\n");
	listbitree(root);
	printf("\n先序遍历输出:\n");
	preorder(root);
	printf("\n中序遍历输出:\n");
	inorder(root);
	printf("\n后序遍历输出:\n");
	postorder(root);
	printf("\n输出叶子结点:\n");
	yezijiedian(root);
	printf("\n");
	//yezishumu(root);
	yezishumu2(root);
	printf("%d\n",count);
	depth(root);
	printf("%d\n",max);
	//depth2(root,1);
	//printf("%d",max);
	print(root,0);
	
}