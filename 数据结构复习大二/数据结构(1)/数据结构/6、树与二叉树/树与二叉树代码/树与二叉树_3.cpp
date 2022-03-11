//��������������
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	char data;
	int Ltag,Rtag;
	Node * LChild,* RChild;
}BiTNode,* BiTree;
int t=0,LeafCount=0,depth=1;
void Judge()
{
	int n;
	char ch;
	printf("�����������������ô��һ�����������Ĳ�������������Ƿ��������Y/N��:");
	getchar();ch=getchar();
	if(ch=='Y' || ch=='y')
		t=1;
	else
	{
		scanf("%d",&n);
		getchar();
		while(n<0 || n>10)
		{
			printf("�����������󣡣���\n");
			printf("���������룺");
			scanf("%d",&n);
		}
	}
}
int menu()
{
	int n;
	printf("|-----------------------------------|\n");
	printf("|1������������                      |\n");
	printf("|2���������������                  |\n");
	printf("|3���������������                  |\n");
	printf("|4���������������                  |\n");
	printf("|5������������Ҷ�ӽ��              |\n");
	printf("|6���������ͳ�ƶ�����Ҷ�ӽ����Ŀ  |\n");
	printf("|7���������ͳ�ƶ�����Ҷ�ӽ����Ŀ  |\n");
	printf("|8�������������������߶�          |\n");
	printf("|9�������������������߶�          |\n");
	printf("|10������״��ӡ������               |\n");
	printf("|0����������                        |\n");
	printf("|-----------------------------------|\n");
	printf("������ִ��������ţ�");
	scanf("%d",&n);
	while(n<0 || n>10)
	{
		printf("�����������󣡣���\n");
		printf("���������룺");
		scanf("%d",&n);
	}
	if(n==1)
	{
		t++;
		if(t==2)
			Judge();
	}
	getchar();
	return n;
}
void CreateTree(BiTree * bt)
{
	char ch;
	ch=getchar();
	if(ch=='.')
		* bt=NULL;
	else
	{
		(* bt)=(BiTree)malloc(sizeof(BiTNode));
		(* bt)->data=ch;
		CreateTree(&((* bt)->LChild));
		CreateTree(&((* bt)->RChild));
	}
}
void PreOrder(BiTree root)
{
	if(root!=NULL)
	{
		printf("%c ",root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
}
void InOrder(BiTree root)
{
	if(root!=NULL)
	{
		InOrder(root->LChild);
		printf("%c ",root->data);
		InOrder(root->RChild);
	}
}
void PostOrder(BiTree root)
{
	if(root!=NULL)
	{
		PostOrder(root->LChild);
		PostOrder(root->RChild);
		printf("%c ",root->data);
	}
}
void PreOrderLeaf(BiTree root)
{
	if(root!=NULL)
	{
		if(root->LChild==NULL && root->RChild==NULL)
			printf("%c ",root->data);
		PreOrderLeaf(root->LChild);
		PreOrderLeaf(root->RChild);
	}
}
void PreLeafCount(BiTree root)	//�д���
{
	if(root!=NULL)
	{
		if(root->LChild==NULL && root->RChild==NULL)
			LeafCount++;
		PreLeafCount(root->LChild);
		PreLeafCount(root->RChild);
	}
}
int PostLeafCount(BiTree root)
{
	int leafcount;
	if(root==NULL)
		return 0;
	else if(root->LChild==NULL && root->RChild==NULL)
		leafcount=1;
	else
		leafcount=PostLeafCount(root->LChild)+PostLeafCount(root->RChild);
		return leafcount;
}
void PreDepthTree(BiTree root,int h)
{
	if(root!=NULL)
	{
		if(h>depth)
			depth=h;
		PreDepthTree(root->LChild,h+1);
		PreDepthTree(root->RChild,h+1);
	}
}
int PostDepthTree(BiTree root)
{
	int hl,hr,max;
	if(root!=NULL)
	{
		hl=PostDepthTree(root->LChild);
		hr=PostDepthTree(root->RChild);
		max=hl>hr?hl:hr;
		return max+1;
	}
	return 0;
}
void PrintTree(BiTree root,int nLayer)
{
	if(root==NULL)
		return ;
	PrintTree(root->RChild,nLayer+1);
	for(int i=0;i<6*nLayer;i++)
		printf(" ");
	printf("%c\n",root->data);
	PrintTree(root->LChild,nLayer+1);
}
void main()
{
	system("color F");
	BiTree root;
	int n;
	n=menu();
	while(n!=0)
	{
		switch(n)
		{
			case 1:CreateTree(&root);break;
			case 2:PreOrder(root);break;
			case 3:InOrder(root);break;
			case 4:PostOrder(root);break;
			case 5:PreOrderLeaf(root);break;
			case 6:PreLeafCount(root);printf("%d\n",LeafCount);LeafCount=0;break;
			case 7:printf("%d\n",PostLeafCount(root));break;
			case 8:PreDepthTree(root,1);printf("%d\n",depth);break;
			case 9:printf("%d\n",PostDepthTree(root));break;
			case 10:PrintTree(root,0);break;
			case 0:;break;
		}
		n=menu();
	}
}