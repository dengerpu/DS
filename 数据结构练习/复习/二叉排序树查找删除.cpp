#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}bstnode,*bstree;
void inserbst(bstree *bst,int key)   //����
{
	bstree s;
	if(*bst==NULL)
	{
		s=(bstree)malloc(sizeof(bstnode));
		s->key=key;
		s->lchild=NULL;s->rchild=NULL;
		*bst=s;
	}
	if((*bst)->key>key)
		inserbst(&((*bst)->lchild),key);
	if((*bst)->key<key)
		inserbst(&((*bst)->rchild),key);
}
void creat(bstree *bst)   //��������������
{
	int key;
	*bst=NULL;
	scanf("%d",&key);
	while(key!=0)
	{
		inserbst(bst,key);
		scanf("%d",&key);
	}
}
void inorder(bstree bst)   //�������
{
	if(bst==NULL)return;
	else
	{
		inorder(bst->lchild );
		printf("%d ",bst->key );
		inorder(bst->rchild );
	}
}
void print(bstree bst,int n)  //����״��ӡ
{
	if(bst==NULL)return;
	print(bst->rchild ,n+1);
	for(int i=0;i<n;i++)
		printf("   ");
	printf("%d\n",bst->key );
	print(bst->lchild ,n+1);
}
bstree search(bstree bst,int key)  //���ҵĵݹ��㷨
{
	if(bst==NULL)return NULL;
	if(bst->key ==key) return bst;
	if(bst->key <key)return search(bst->rchild ,key);
	else return search(bst->lchild ,key);
}
/*bstree search(bstree bst,int key)  //���ҷǵݹ��㷨
{
bstree q;
q=bst;
while(q!=NULL)
{
if(q->key ==key) return q;
if(q->key >key) q=q->lchild ;
else
q=q->rchild ;
}
return NULL;
}*/
bstree delbst(bstree t,int k)  //ɾ�����
{
	bstree p,f,s,q;
	p=t;f==NULL;
	while(p)
	{
		if(p->key==k)break;
		f=p;                              //fָ��p��˫�׽ڵ�
		if(p->key>k)p=p->lchild;
		else p=p->rchild;
	}
	if(p==NULL)return t;  //���Ҳ���������ԭ���Ķ�����
	if(p->lchild==NULL)   //p��������
	{
		if(f==NULL) t=p->lchild;  //p��ԭ�������ĸ�
		else if(f->lchild==p)  //p��f������
			f->lchild=p->rchild;   //��p������������f��������
		else          //p��f���Һ���
			f->rchild=p->rchild  //��p������������f��������
			free(p);
	}
	else  //p��������
	{
		q=p;s=p->lchild;
		while(s->rchild)   //��p���������в��������½��
		{
			q=s;
			s=s->rchild;
		}
		if(q==p)q->lchild=s->lchild;  //��s������������q��
		else q->rchild=s->lchild;
		p->key=s->key;
		free(s);
	}
	return t;
}
void main()
{
	bstree bst,result;
	int key;
	printf("�������㣬��0Ϊ����\n");
	creat(&bst);
	printf("����������Ϊ:\n");
	inorder(bst);
	printf("����״��ӡΪ\n");
	print(bst,0);
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&key);
	result=search(bst,key);
	if(result==NULL)
		printf("���Ҳ��������\n");
	else
		printf("���ҵ�����Ϊ%d\n",result->key );
}