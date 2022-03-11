/* �������Ķ���������ṹ���� */
typedef struct Node
{
	DataType data;
	int Ltag;
	int Rtag;
	struct Node * LChild;
	struct Node * RChild;
}BiTNode,* BiTree;
/* ���㷨6.1�� ������������� */
void PreOrder(BiTree root)
/* ���������������rootΪָ�����������ĳһ������������ָ�� */
{
	if(root!=NULL)
	{
		Visit(root->data);	//���ʸ��ڵ�
		PreOrder(root->LChild);	//�������������
		PreOrder(root->RChild);	//�������������
	}
}
/* ���㷨6.2�� ������������� */
void InOrder(BiTree root)
/* ���������������rootΪָ�����������ĳһ������������ָ�� */
{
	if(root!=NULL)
	{
		InOrder(root->LChild);	//�������������
		Visit(root->data);	//���ʸ����
		InOrder(root->RChild);	//�������������
	}
}
/* ���㷨6.3��  ������������� */
void PostOrder(BiTree root)
/* ���������������rootΪָ�����������ĳһ������������ָ�� */
{
	if(root!=NULL)
	{
		PostOrder(root->LChild);	//�������������
		PostOrder(root->RChild);	//�������������
		Visit(root->data);	//���ʸ����
	}
}
/* ���㷨6.4��  �����������������еĽ�� */
void PreOrder(BiTree root)
/* ������������������㣬rootΪָ�������������ָ�� */
{ 
	if(root!=NULL)
	{
		printf(root->data);	//��������
		PreOrder(root->LChild);	//�������������
		PreOrder(root->RChild);	//�������������
	}
}
/* ���㷨6.5��  ������������������Ҷ�ӽ�� */
void PreOrder(BiTree root)
/* �����������������е�Ҷ�ӽ�㣬rootΪָ�������������ָ�� */
{
	if(root!=NULL)
	{
		if(root->LChild==NULL && root->RChild==NULL)
			printf(root->data);	//���Ҷ�ӽ��
		PreOrder(root->LChild);	//�������������
		PreOrder(root->RChild);	//�������������
	}
}
/* ���㷨6.6(a)��  �������ͳ��Ҷ�ӽ����Ŀ */
/* LeafCount Ϊ����Ҷ�ӽ����Ŀ��ȫ�ֱ���������֮ǰ��ʼ��ֵΪ0 */
void leaf(BiTree root)
{
	if(root!=NULL)
	{
		leaf(root->LChild);
		leaf(root->RChild);
		if(root->LChild==NULL && root->RChild==NULL)
			LeafCount++;
	}
}
/* ���㷨6.6(b)��  �������ͳ��Ҷ�ӽ����Ŀ */
int leaf(BiTree root)
{
	int LeafCount;
	if(root==NULL)
		LeafCount=0;
	else if(root->LChild==NULL && root->RChild==NULL)
		LeafCount=1;
	else /* Ҷ����Ϊ����������Ҷ����Ŀ֮�� */
		LeafCount=leaf(root->LChild)+leaf(root->RChild);
	return LeafCount;
}
/* ���㷨6.7��  ����չ����������д����������� */
void CreateBiTree(BiTree * bt)
{
	char ch;
	ch=getchar();
	if(ch=='.')
		* bt=NULL;
	else
	{
		* bt=(BiTree)malloc(sizeof(BiTNode));
		(* bt)->data=ch;
		CreateBiTree(&((* bt)->LChild));
		CreateBiTree(&((* bt)->RChild));
	}
}
/* ���㷨6.8�� ���������������߶ȵĵݹ��㷨 */
int PostTreeDepth(BiTree bt)	//��������������bt�߶ȵĵݹ��㷨
{
	int hl.hr,max;
	if(bt!=NULL)
	{
		hl=PostTreeDepth(bt->LChild);	//�����������
		hr=PostTreeDepth(bt->RChild);	//�����������
		max=hl>hr?hl:hr;	//�õ�����������������
		return (max+1);	//�����������
	}
	else
		return 0;	//����ǿ������򷵻�0
}
/* ���㷨6.9��  ���������������߶ȵĵݹ��㷨 */
void PreTreeDepth(BiTree bt,int h)
/* ��������������bt�߶ȵĵݹ��㷨��hΪbtָ�������ڲ�Σ���ֵΪ1 */
/* depthΪ��ǰ��õ�����Σ�Ϊȫ�ֱ���������ǰ��ֵΪ0 */
{
	if(bt!=NULL)
	{
		if(h>depth)
			depth=h;	/* ����ý����ֵ����depth������depth��ֵ */
		PreTreeDepth(bt->LChild,h+1);	//����������
		PreTreeDepth(bt->RChild,h+1);	//����������
	}
}
/* ���㷨6.10��  ����״��ӡ������ */
void PrintTree(BiTree bt,int nLayer)	//��������״��ӡ�Ķ�����
{
	if(bt==NULL)
		return ;
	PrintTree(bt->RChild,nLayer+1);
	for(int i=0;i<nLayer;i++)
		printf("   ");
	printf("%c\n",bt->data);	//�������������㣬�ò����������λ��
	PrintTree(bt->LChild,nLayer+1);
}
/* ���㷨6.11(a)��  ��������������ǵݹ��㷨���� */
void inorder(BiTree root)
{
	int top=0;p=root;
	L1: if(p!=NULL)	//����������
		{
			top=top+2;
			if(top>m)
				return ;	//ջ�����
			s[top-1]=p;	//���������ջ
			s[top]=L2;	//���ص�ַ��ջ
			p=p->LChild;	//���²������ֵ
			goto L1;	//ת��ʼ
	L2:     Visit(p->data);	//���ʸ�
			top=top+2;
			if(top>m)
				return ;	//ջ���������
			s[top-1]=p;	//����������
			s[top]=L3;
			p=p->RChild;
			goto L1;
		}
	L3: if(top!=0)
		{
			addr=s[top];
			p=s[top-1];	//ȡ�����ص�ַ
			top=top-2;	//�˳��������
			goto addr;
		}
}
/* ���㷨6.11(b)�� ��������������ķǵݹ��㷨��ֱ��ʵ��ջ������ */
/* s[m]��ʾջ��top��ʾջ��ָ�� */
void inorder(BiTree root)	//���������������rootΪ�������ĸ����
{
	top=0;p=root;
	do
	{
		while(p!=NULL)
		{
			if(top>m)
				return ;
			top=top+1;
			s[top]=p;
			p=p->LChild;
		}	//����������
		if(top!=0)
		{
			p=s[top];
			top=top-1;
			Visit(p->data);	//���ʸ����
			p=p->RChild;
		}	//����������
	}while(p!=NULL||top!=0);
}
/* ���㷨6.11(c)��  ��������������ķǵݹ��㷨������ջ�����ĺ����� */
void InOrder(BiTree root)	//��������������ķǵݹ��㷨
{
	InitStack(&S);
	p=root;
	while(p!=NULL||!IsEmpty(S))
	{
		if(p!=NULL)	//��ָ���ջ������������
		{
			Push(&S,p);
			p=p->LChild;
		}
		else
		{	//��ָ����ջ�����ʸ���㣬����������
			Pop(&S,&p); Visit(p->data);
			p=p->RChild;
		}
	}
}
/* ���㷨6.12�� ��������������ķǵݹ��㷨������ջ�����ĺ����� */
void PostOrder(BiTree root)
{
	BiTree * p,* q;
	Stack S;
	q=NULL;
	p=root;
	InitStack(&S);
	while(p!=NULL||!IsEmpty(S))
	{
		if(p!=NULL)
		{
			Push(&S,p);
			p=p->LChild;	//����������
		}
		else
		{
			GetTop(&S,&p);
			if(p->RChild==NULL || p->RChild==q)	//���Һ��ӣ��������ѱ�����
			{
				Visit(p->data);	//���ʸ����
				q=p;	//���浽q��Ϊ��һ���Ѵ�����ǰ��
				Pop(&S,&p);
				p=NULL;
			}
			else
				p=p->RChild;
		}
	}
}
BiTree pre;	//������������ʹ��
/* ���㷨6.13�� �������������� */
void Inthread(BiTree root)
/* ��root��ָ�Ķ�������������������������preʼ��ָ��շ��ʹ��Ľ�㣬���ֵΪNULL */
{
	if(root!=NULL)
	{
		Inthread(root->LChild);	//������������
		if(root->LChild==NULL)
		{ root->Ltag=1; root->LChild=pre; }	//��ǰ������
		if(pre!=NULL && pre->RChild==NULL)
		{ pre->RChild=root; pre->Rtag=1; }	//�ú������
		pre=root;	//��ǰ���ʽ��Ϊ��һ�����ʽ���ǰ��
		Inthread(root->RChild);	//������������
	}
}
/* ���㷨6.14�� ���������������ҽ��ǰ�� */
BiTree InPre(BiTree p)
/* �����������������в���p������ǰ��������preָ�뷵�ؽ�� */
{
	BiTree Pre,q;
	if(p->Ltag==1) Pre=p->LChild;
	else
	{	//��p���������в��ҡ������¶ˡ����
		for(q=p->LChild;q->Rtag==0;q=q->RChild);
		pre=q;
	}
	return pre;
}
/* ���㷨6.15�� ���������������ҽ���� */
BiTree InNext(BiTree p)
/* �����������������в���p�������̽�㣬����Nextָ�뷵�ؽ�� */
{
	BiTree Next,q;
	if(p->Rtag==1) Next=p->RChild;
	else
	{	//��p���������в��ҡ������¶ˡ����
		for(q=p->RChild;q->Ltag==0;q=q->LChild);
		Next=q;
	}
	return Next;
}
/* ���㷨6.16�� ������������������������ĵ�һ����� */
BiTree InFirst(BiTree Bt)
{
	BiTree p=Bt;
	if(!p)
		return NULL;
	while(p->Ltag==0) 
		p=p->LChild;
	return p;
}
/* ���㷨6.17�� ����������������� */
void TInOrder(BiTree Bt)
{
	BiTree p;
	p=InFirst(Bt);
	while(p)
	{
		Visit(p);
		p=InNext(p);
	}
}
/* ���㷨���䡿 �����������Ĳ������㣨ɾ����ͬ�����Բ���������Ϊ���� */
void InsNode(BiTree p,BiTree r)
{
	BiTree s;
	if(p->Rtag==1)	//p���Һ���
	{
		r->RChild=p->RChild;	//p�ĺ�̱�Ϊr�ĺ��
		r->Rtag=1;
		p->RChild=r;	//r��Ϊp���Һ���
		r->LChild=p;	//p��Ϊr��ǰ��
		r->Ltag=1;
		p->Rtag=0;
	}
	else	//p���Һ���
	{
		s=p->RChild;
		while(s->Ltag==0)
			s=s->LChild;	//����p�����������ġ������¶ˡ����
		r->RChild=p->RChild;	//p���Һ��ӱ�Ϊr���Һ���
		r->Rtag=0;
		r->LChild=p;	//p��Ϊr��ǰ��	
		r->Ltag=1;
		p->RChild=r;	//r��Ϊp���Һ���
		s->LChild=r;	//r��Ϊpԭ���������ġ�������ˡ�����ǰ��
	}
}
/* ˫�ױ�ʾ���ṹ����(6.4 ����ɭ�ֺͶ�����) */
#define MAX 100
typedef struct TNode
{
	DataType data;
	int parent;
}TNode;
/* �����Զ���Ϊ */
typedef struct
{
	TNode tree[MAX];
	int nodenum;	//�����
}ParentTree;
/* ���ӱ�ʾ���Ĵ洢�ṹ���� */
typedef struct ChildNode	//����������Ķ���
{
	int Child;	//�ú��ӽ�������Ա��е�λ��
	struct ChildNode * next;	//ָ����һ�����ӽ���ָ��
}ChildNode;
typedef struct	//˳�����Ľṹ����
{
	DataType data;	//������Ϣ
	ChildNode * FirstChild;	//ָ���������ͷָ��
}DataNode;
typedef struct	//���Ķ���
{
	DataNode nodes[MAX];	//˳���
	int root;	//�����ĸ���������Ա��е�λ��
	int num;	//�����Ľ�����
}ChildTree;
/* �����ֵܱ�ʾ�������Ͷ��� */
typedef struct CSNode
{
	DataType data;	//�����Ϣ
	struct CSNode * FirstChild;	//��һ������
	struct CSNode * Nextsibling;	//��һ���ֵ�
}CSNode,* CSTree;
/* �ú����ֵ�����ʵ�������ȸ����� */
//����һ
void RootFirst(CSTree root)
{
	CSTree p;
	if(root!=NULL)
	{
		Visit(root->data);	//���ʸ����
		p=root->FirstChild;
		while(p!=NULL)
		{
			RootFirst(p);	//������pΪ��������
			p=p->Nextsibling;
		}
	}
}
//������
void RootFirst(CSTree root)
{
	if(root!=NULL)
	{
		Visit(root->data);	//���ʸ����
		RootFirst(root->FirstChild);	//�ȸ�����������
		RootFirst(root->Nextsibling);	//�ȸ������ֵ���
	}
}
/* ��̬��������ʵ�ֵĹ������������Ͷ��� */
#define N 20	//Ҷ�ӽ������ֵ
#define M 2*N-1	//���н������ֵ
typedef struct
{
	int weight;	//����Ȩֵ
	int parent;	//˫�׵��±�
	int LChild;	//���ӽ����±�
	int RChild;	//�Һ��ӽ����±�
}HTNode,* HuffmanTree[M+1];	//HuffmanTree��һ���ṹ�������ͣ�0�ŵ�Ԫ����
/* ���㷨6.18�� �������������㷨 */
void CrtHuffmanTree(HuffmanTree ht,int w[],int n)
{	/* �����������ht[M+1],w[]���n��Ȩֵ�� */
	for(i=1;i<=n;i++)
		ht[i]={w[i],0,0,0};	//1~n�ŵ�Ԫ���Ҷ�ӽ�㣬��ʼ��
	m=2*n-1;
	for(i=n+1;i<=m;i++)
		ht[i]={0,0,0,0};	//n+1~m�ŵ�Ԫ��ŷ�Ҷ��㣬��ʼ��
	/*---------------��ʼ����ϣ���Ӧ�㷨����1-----------------*/
	for(i=n+1;i<=m;i++)	//������Ҷ��㣬����������
	{
		select(ht,i-1,&s1,&s2);	//��ht[1]~ht[i-1]�ķ�Χ��ѡ������parentΪ0��weight��С�Ľ�㣬����ŷֱ�ֵ��s1,s2
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i; ht[s2].parent=i;
		ht[i].LChild=s1; ht[i].RChild=s2;
	}	//���������������
}
/* ���㷨6.19�� ����������Ĺ�����������㷨 */
void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
/* ��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ��������� */
{
	char * cd;
	cd=(char *)malloc(n*sizeof(char));	//������ǰ����Ĺ����ռ�
	cd[n-1]='\0';	//����������λ��ű��룬���ȴ�ű��������
	for(i=1;i<=n;i++)	//��n��Ҷ�ӽ���Ӧ�Ĺ���������
	{
		start=n-1;	//��ʼ��������ʼָ��
		c=i; p=ht[i].parent;	//��Ҷ�ӽ�㿪ʼ���ϵ���
		while(p!=0)
		{
			--start;
			if(ht[p].LChild==e)	//���֧��0
				cd[start]='0';
			else
				cd[start]='1';	//�ҷ�֧��1
			c=p; p=ht[p].parent;	//���ϵ���
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));	//Ϊ��i���������ռ�
		strcpy(hc[i],&cd[start]);	//�ѱ��븴�Ƶ�hc[i]��
	}
	free(cd);
}
/* ������ɭ�֣���˫�ױ�ʾ��Ϊ���������鼯���Ϳɶ������� */
typedef ParentTree ParentForest;
typedef ParentForest MFSat;
/* ���㷨6.20�� ��ʼ�����鼯 */
void Initialization(MFSat * SS,SeqList * S)
/* ��S�е�n��Ԫ�ع���n��������������n����Ԫ�ؼ���S0,S1,...,S(n-1),��n������������һ��ɭ�֣������鼯SS */
{
	int i;
	SS->nodenum=S->last+1;
	for(i=0;i<SS->nodenum;i++)
	{
		SS->tree[i].data=S->elem[i];
		SS->tree[i].parent=-1;
	}
}
/* ���㷨6.21(a)�� �ڲ��鼯�в���ĳ��Ԫ�� */
int Find_1(MFSat * SS,DataType x)
/* ȷ��x���ڲ��鼯SS���ĸ��Ӽ��ϡ����������SS����һ�Ӽ����򷵻�-1�����򷵻������Ӽ����ĸ�����±� */
{
	pos=Locate(SS,x);	//ȷ��x��SS->tree[]�е��±�
	if(pos<0)	//���x������SS����һ�Ӽ����򷵻�-1
		return -1;
	i=pos;	//��pos��ʼ������˫��ָ����Ҹ����
	while(SS->tree[i].parent>0)
		i=SS->tree[i].parent;
	return i;
}
/* ���㷨6.21(b)�� �ڲ��鼯�в���ĳ��Ԫ�أ��Ľ��㷨�� */
int Find_2(MFSat * SS,DataType x)
/* ȷ��x���ڲ��鼯SS���ĸ��Ӽ��ϣ�ͬʱ�����Ӽ�����������߶ȡ����x������SS����һ�Ӽ����򷵻�-1��
���������ҵ�x�����Ӽ����ĸ�root��Ȼ��x��x���������ȣ�����root������Ϊroot���ӽ�㣬��󷵻�root */
{
	pos=Locate(SS,x);	//ȷ��x��SS->tree[]�е��±�
	if(pos<0) return -1;	//���x������SS����һ�Ӽ����򷵻�-1
	i=pos;	//��pos��ʼ������˫��ָ����Ҹ����
	while(SS->tree[i].parent>0)
		i=SS->tree[i].parent;
	root=i;	//��¼x�����������ĸ�����±�
	i=pos;	//��pos��ʼ����x��x���������ȣ�����root������Ϊroot���ӽ��
	while(i!=root)
	{
		temp=SS->tree[i].parent;
		SS->tree[i].parent=root;
		i=temp;
	}
	return root;	//����x�����Ӽ����ĸ�����±�
}
/* ���㷨6.22(a)�� �ϲ����鼯�е������� */
int Merge_1(MFSat * SS,int root1,int root2)
/* root1��root2�ǲ��鼯SS�����������ཻ�ķǿ��Ӽ����ĸ������Ӽ���root2�����Ӽ���root1 */
{
	if(root1<0 || root1> SS->nodenum-1) return ERROR;
	if(root2<0 || root2> SS->nodenum-1) return ERROR;
	SS->tree[root2].parent=root1;
	return OK;
}
/* ���㷨6.22(b)�� �ϲ����鼯�е��Ӽ��� */
int Merge_2(MFSat * SS,int root1,int root2)
/* root1��root2�ǲ��鼯SS�����������ཻ�ķǿ��Ӽ����ĸ���������parent�������н����Ŀ�ĸ�ֵ��
���㷨�������Ŀ���ٵ��Ӽ�����������Ŀ�϶���Ӽ��� */
{
	if(root1<0 ||root1> SS->nodenum-1) return ERROR;
	if(root2<0 ||root2> SS->nodenum-1) return ERROR;
	if(SS->tree[root1].parent<SS->tree[root2].parent)	//��һ���Ӽ����н����Ŀ�϶�
	{
		SS->tree[root2].parent=root1;
		SS->tree[root1].parent+=SS->tree[root2].parent;
	}
	else	//�ڶ����Ӽ����н����Ŀ�϶�
	{
		SS->tree[root1].parent=root2;
		SS->tree[root2].parent+=SS->tree[root1].parent;
	}
	return OK;
}
/* ���㷨6.21(b)�� �ڲ��鼯�в���ĳ��Ԫ�� */
int Find_2(MFSat * SS,DataType x)
/* ȷ��x���ڲ��鼯SS���ĸ��Ӽ��ϣ�ͬʱ�����Ӽ�����������߶ȡ����x������SS����һ�Ӽ���
�򷵻�-1�����������ҵ�x�����Ӽ����ĸ�root��Ȼ��x��x���������ȣ�����root������Ϊroot
���ӽ�㣬��󷵻�root */
{
	pos=Locate(SS,x);	//ȷ��x��SS->tree[]�е��±�
	if(pos<0) return -1;	//���x������SS����һ�Ӽ����򷵻�-1
	i=pos;	//��pos��ʼ������˫��ָ����Ҹ����
	while(SS->tree[i].parent>0)
		i=SS->tree[i].parent;
	root=i;	//��¼x�����Ӽ����ĸ�����±�
	i=pos;	//��pos��ʼ����x��x���������ȣ�����root������Ϊroot���ӽ��
	while(i!=root)
	{
		temp=SS->tree[i].parent;
		SS->tree[i].parent=root;
		i=temp;
	}
	return root;	//����x�����Ӽ����ĸ�����±�
}
/* ���㷨6.23�� �ж϶�����t1��t2�Ƿ������㷨 */
int like(BiTree t1,BiTree t2)
/* �ж϶�����t1��t2�Ƿ����ƣ������ƣ�����1�����򷵻�0 */
{
	int like1,like2;
	if(t1==NULL && t2==NULL)
		return 1;	//t1��t2��Ϊ�գ����ƣ�����1
	else if(t1==NULL || t2==NULL)
		return 0;	//t1��t2����֮һΪ�����������ƣ�����0
	else
	{
		like1=like(t1->LChild,t2->LChild);	//�ж�t1��t2���������Ƿ�����
		like2=link(t1->RChild,t2->RChild);	//�ж�t1��t2���������Ƿ�����
		return (like1 && like2);
	}
}
/* ���㷨6.24�� ����Ӷ������и���㵽r��ָ���֮���·������� */
void path(BiTree root,BiTNode * r)
/* ����Ӷ���������㵽r���֮���·��������㷨 */
{
	BiTNode * p,* q;
	int i,top=0;
	BiTree s[Stack_Size];
	q=NULL;	//��q����ձ������Ľ�㣬��ʼΪ��
	p=root;
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++;
			if(top>=Stack_Size)
				OverFlow();	//ջ�������
			s[top]=p;
			p=p->LChild;
		}	//����������
		if(top>0)
		{
			p=s[top];	//�����
			if(p->RChild==NULL || p->RChil==q)
			{
				if(p==r)	//�ҵ�r��ָ��㣬����ʾ�Ӹ���㵽r��ָ���֮���·��
				{
					for(i=1;i<=top;i++)
						printf("%d",s[i]->data);
					return ;
				}
				else
				{
					q=p;	//��q����ձ������Ľ��
					top--;
					p=NULL;	//����ǰ�������������ջ
				}
			}
			else
				p=p->RChild;	//����������
		}
	}
}
/* ���㷨6.25�� ��α����������㷨 */
int LayerOrder(BiTree bt)
/* ��α���������bt */
{
	SeqQueue Q;
	BiTree p;
	InitQueue(&Q);	//��ʼ���ն���Q
	if(bt==NULL)
		return ERROR;	//��������btΪ���������������
	EnterQueue(&Q,bt);	//��������bt�ǿգ�������bt��ӣ���ʼ��α���
	while(!IsEmpty(Q))	//�����зǿգ������δ��������������
	{
		DeleteQueue(&Q,&p);	//��ͷԪ�س��Ӳ�����
		visit(p->data);
		if(p->LChild) EnterQueue(&Q,p->LChild);	//��p�����ӷǿգ������
		if(p->RChild) EnterQueue(&Q,p->RChild);	//��p���Һ��ӷǿգ������
	}	//while
	return OK;
}	//LayerOrder