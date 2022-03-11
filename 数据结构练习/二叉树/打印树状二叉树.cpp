//ABDG00H000CE0I00F00
#include<stdio.h>
#include<malloc.h>
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
		root->lchild=creatbitree();
		root->rchild=creatbitree();
	}
	return root;
}
void print(bitree root,int n)
{
	if(root==NULL)return;
	else
	{
		print(root->rchild,n+1);
		for(int i=0;i<n;i++)
			printf("  ");
		printf("%c\n",root->data);
		print(root->lchild,n+1);
	}
}
void main()
{
bitree root=NULL;
root=creatbitree();
print(root,0);
}