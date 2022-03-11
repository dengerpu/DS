//17 6 43 12 123 26 34 40 8 90 45 0
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}bstnode,*bstree;
void insert(bstree *bst,int key)
{
	bstree s;
	if(*bst==NULL)
	{
		s=(bstree)malloc(sizeof(struct node));
		s->key=key;
		s->lchild=NULL;
		s->rchild=NULL;
		*bst=s;
	}
	if((*bst)->key>key)
		insert(&((*bst)->lchild),key);
	if((*bst)->key<key)
		insert(&((*bst)->rchild),key);
}
void creat(bstree *bst)
{
	int key;
	*bst=NULL;
	scanf("%d",&key);
	while(key!=0)
	{
		insert(bst,key);
		scanf("%d",&key);
	}
}
void inorder(bstree bst)
{
	if(bst==NULL)
		return;
	else
	{
		inorder(bst->lchild);
		printf("%d ",bst->key);
		inorder(bst->rchild);
	}
}
void print(bstree bst,int n)
{
	int i;
	if(bst==NULL)return;
	print(bst->rchild,n+1);
	for(i=0;i<n;i++)
		printf("   ");
	printf("%d\n",bst->key);
	print(bst->lchild,n+1);
}
bstree searchbst(bstree bst,int key)
{
	if(bst==NULL)return NULL;
	else if(bst->key==key)return bst;
	else if(bst->key>key)searchbst(bst->lchild,key);
	else if(bst->key<key)searchbst(bst->rchild,key);
}
bstree searchbst1(bstree bst,int key)
{
	bstree q;
	q=bst;
	while(q!=NULL)
	{
		if(q->key==key)return q;
		if(q->key>key)q=q->lchild;
		else q=q->rchild; 
	}
	return NULL;
}
void main()
{
	bstree bst,result,a;
	int e;
	creat(&bst);
	printf("�������������Ϊ\n");
	inorder(bst);
	printf("��״��ӡ���Ϊ\n");
	print(bst,0);
	printf("������Ҫ���ҵ���\n");
    scanf("%d",&e);
	result=searchbst(bst,e);
	if(result==NULL)
		printf("û�������\n");
	else
		printf("�����Ϊ%d\n",result->key);
	printf("������Ҫ���ҵ���\n");
    scanf("%d",&e);
	a=searchbst1(bst,e);
	if(result==NULL)
		printf("û�������\n");
	else
		printf("�����Ϊ%d\n",a->key);
}