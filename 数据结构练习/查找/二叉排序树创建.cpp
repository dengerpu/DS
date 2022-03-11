//17 6 43 12 123 26 34 40 8 90 45 0
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int  key;
	struct node *lchild,*rchild;
}bstnode,*bstree;
void insertbst(bstree *bst,int key)  //����
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
void creatbst(bstree *bst)    //��������������
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
void inorder(bstree bst)   //�������������
{
	if(bst!=NULL)
	{
		inorder(bst->lchild );
		printf("%d ",bst->key );
		inorder(bst->rchild );
	}
}
void print(bstree bst,int n)      //����״��ӡ������
{
	if(bst==NULL) return;
	print(bst->rchild ,n+1);
	for(int i=0;i<n;i++)
		printf("    ");
	printf("%d\n",bst->key );
	print(bst->lchild ,n+1);
}
/*bstree searchbst(bstree bst,int key)   //�������������ҵĵݹ��㷨
{
	if(!bst) return NULL;
	else if(bst->key ==key) return bst;
	else if(bst->key >key) return searchbst(bst->lchild ,key);
	else if(bst->key <key) return searchbst(bst->rchild ,key);
}*/
bstree searchbst(bstree bst,int key)   //�������������ҵķǵݹ��㷨
{
	bstree q;
	q=bst;
	while(q)
	{
		if(q->key ==key) return q;
		if(q->key >key) q=q->lchild ;
		else q=q->rchild ;
	}
	return NULL;   //����ʧ��
}
void main()
{
	bstree bst,result;
	int key;
	printf("�������������������������У�����0��ʾ������\n");
	creatbst(&bst);
	printf("��������������������Ϊ:\n");
	inorder(bst);
	printf("����״��ӡΪ:\n");
	print(bst,0);
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&key);
	result=searchbst(bst,key);
	if(result!=NULL)
	{
		printf("Ҫ���ҵ������� Ϊ��%d\n",result->key );
	}
	else
		printf("Ҫ���ҵ���������\n");
}