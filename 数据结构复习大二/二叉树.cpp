//ABDG00H000CE0I00F00
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creatbitree()   //����������
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
void preorder(bitree root)    //�������������
{
	if(root!=NULL)
	{
		printf("%3c",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void inorder(bitree root)   //�������������
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%3c",root->data);
		inorder(root->rchild);
	}
}
void postorder(bitree root)  //�������������
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
	printf("����������Ϊ\n");
	preorder(root);
	printf("\n����������Ϊ\n");
	inorder(root);
	printf("\n����������Ϊ\n");
	postorder(root);
	printf("Ҷ�ӽ�����Ϊ��\n");
	yezijiedian(root);
	
}