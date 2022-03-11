/* 二叉树的二叉链表结点结构定义 */
typedef struct Node
{
	DataType data;
	int Ltag;
	int Rtag;
	struct Node * LChild;
	struct Node * RChild;
}BiTNode,* BiTree;
/* 【算法6.1】 先序遍历二叉树 */
void PreOrder(BiTree root)
/* 先序遍历二叉树，root为指向二叉树（或某一子树）根结点的指针 */
{
	if(root!=NULL)
	{
		Visit(root->data);	//访问根节点
		PreOrder(root->LChild);	//先序遍历左子树
		PreOrder(root->RChild);	//先序遍历右子树
	}
}
/* 【算法6.2】 中序遍历二叉树 */
void InOrder(BiTree root)
/* 中序遍历二叉树，root为指向二叉树（或某一子树）根结点的指针 */
{
	if(root!=NULL)
	{
		InOrder(root->LChild);	//中序遍历左子树
		Visit(root->data);	//访问根结点
		InOrder(root->RChild);	//中序遍历右子树
	}
}
/* 【算法6.3】  后序遍历二叉树 */
void PostOrder(BiTree root)
/* 后序遍历二叉树，root为指向二叉树（或某一子树）根结点的指针 */
{
	if(root!=NULL)
	{
		PostOrder(root->LChild);	//后序遍历左子树
		PostOrder(root->RChild);	//后序遍历右子树
		Visit(root->data);	//访问根结点
	}
}
/* 【算法6.4】  先序遍历输出二叉树中的结点 */
void PreOrder(BiTree root)
/* 先序遍历输出二叉树结点，root为指向二叉树根结点的指针 */
{ 
	if(root!=NULL)
	{
		printf(root->data);	//输出根结点
		PreOrder(root->LChild);	//先序遍历左子树
		PreOrder(root->RChild);	//先序遍历右子树
	}
}
/* 【算法6.5】  先序遍历输出二叉树中叶子结点 */
void PreOrder(BiTree root)
/* 先序遍历输出二叉树中的叶子结点，root为指向二叉树根结点的指针 */
{
	if(root!=NULL)
	{
		if(root->LChild==NULL && root->RChild==NULL)
			printf(root->data);	//输出叶子结点
		PreOrder(root->LChild);	//先序遍历左子树
		PreOrder(root->RChild);	//先序遍历右子树
	}
}
/* 【算法6.6(a)】  后序遍历统计叶子结点数目 */
/* LeafCount 为保存叶子结点数目的全局变量，调用之前初始化值为0 */
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
/* 【算法6.6(b)】  后序遍历统计叶子结点数目 */
int leaf(BiTree root)
{
	int LeafCount;
	if(root==NULL)
		LeafCount=0;
	else if(root->LChild==NULL && root->RChild==NULL)
		LeafCount=1;
	else /* 叶子树为左右子树的叶子数目之和 */
		LeafCount=leaf(root->LChild)+leaf(root->RChild);
	return LeafCount;
}
/* 【算法6.7】  用扩展先序遍历序列创建二叉链表 */
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
/* 【算法6.8】 后序遍历求二叉树高度的递归算法 */
int PostTreeDepth(BiTree bt)	//后序遍历求二叉树bt高度的递归算法
{
	int hl.hr,max;
	if(bt!=NULL)
	{
		hl=PostTreeDepth(bt->LChild);	//求左子树深度
		hr=PostTreeDepth(bt->RChild);	//求右子树深度
		max=hl>hr?hl:hr;	//得到左、右子树深度最大者
		return (max+1);	//返回树的深度
	}
	else
		return 0;	//如果是空树，则返回0
}
/* 【算法6.9】  先序遍历求二叉树高度的递归算法 */
void PreTreeDepth(BiTree bt,int h)
/* 先序遍历求二叉树bt高度的递归算法，h为bt指向结点所在层次，初值为1 */
/* depth为当前求得的最大层次，为全局变量，调用前初值为0 */
{
	if(bt!=NULL)
	{
		if(h>depth)
			depth=h;	/* 如果该结点层次值大于depth，更新depth的值 */
		PreTreeDepth(bt->LChild,h+1);	//遍历左子树
		PreTreeDepth(bt->RChild,h+1);	//遍历右子树
	}
}
/* 【算法6.10】  按树状打印二叉树 */
void PrintTree(BiTree bt,int nLayer)	//按竖向树状打印的二叉树
{
	if(bt==NULL)
		return ;
	PrintTree(bt->RChild,nLayer+1);
	for(int i=0;i<nLayer;i++)
		printf("   ");
	printf("%c\n",bt->data);	//按逆中序输出结点，用层深决定左右位置
	PrintTree(bt->LChild,nLayer+1);
}
/* 【算法6.11(a)】  中序遍历二叉树非递归算法初步 */
void inorder(BiTree root)
{
	int top=0;p=root;
	L1: if(p!=NULL)	//遍历左子树
		{
			top=top+2;
			if(top>m)
				return ;	//栈满溢出
			s[top-1]=p;	//本层参数进栈
			s[top]=L2;	//返回地址进栈
			p=p->LChild;	//给下层参数赋值
			goto L1;	//转向开始
	L2:     Visit(p->data);	//访问根
			top=top+2;
			if(top>m)
				return ;	//栈满溢出处理
			s[top-1]=p;	//遍历右子树
			s[top]=L3;
			p=p->RChild;
			goto L1;
		}
	L3: if(top!=0)
		{
			addr=s[top];
			p=s[top-1];	//取出返回地址
			top=top-2;	//退出本层参数
			goto addr;
		}
}
/* 【算法6.11(b)】 中序遍历二叉树的非递归算法（直接实现栈操作） */
/* s[m]表示栈，top表示栈顶指针 */
void inorder(BiTree root)	//中序遍历二叉树，root为二叉树的根结点
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
		}	//遍历左子树
		if(top!=0)
		{
			p=s[top];
			top=top-1;
			Visit(p->data);	//访问根结点
			p=p->RChild;
		}	//遍历右子树
	}while(p!=NULL||top!=0);
}
/* 【算法6.11(c)】  中序遍历二叉树的非递归算法（调用栈操作的函数） */
void InOrder(BiTree root)	//中序遍历二叉树的非递归算法
{
	InitStack(&S);
	p=root;
	while(p!=NULL||!IsEmpty(S))
	{
		if(p!=NULL)	//根指针进栈，遍历左子树
		{
			Push(&S,p);
			p=p->LChild;
		}
		else
		{	//根指针退栈，访问根结点，遍历右子树
			Pop(&S,&p); Visit(p->data);
			p=p->RChild;
		}
	}
}
/* 【算法6.12】 后序遍历二叉树的非递归算法（调用栈操作的函数） */
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
			p=p->LChild;	//遍历左子树
		}
		else
		{
			GetTop(&S,&p);
			if(p->RChild==NULL || p->RChild==q)	//无右孩子，或左孩子已遍历过
			{
				Visit(p->data);	//访问根结点
				q=p;	//保存到q，为下一次已处理结点前驱
				Pop(&S,&p);
				p=NULL;
			}
			else
				p=p->RChild;
		}
	}
}
BiTree pre;	//线索二叉树中使用
/* 【算法6.13】 建立中序线索树 */
void Inthread(BiTree root)
/* 对root所指的二叉树进行中序线索化，其中pre始终指向刚访问过的结点，其初值为NULL */
{
	if(root!=NULL)
	{
		Inthread(root->LChild);	//线索化左子树
		if(root->LChild==NULL)
		{ root->Ltag=1; root->LChild=pre; }	//置前驱线索
		if(pre!=NULL && pre->RChild==NULL)
		{ pre->RChild=root; pre->Rtag=1; }	//置后继线索
		pre=root;	//当前访问结点为下一个访问结点的前驱
		Inthread(root->RChild);	//线索化右子树
	}
}
/* 【算法6.14】 在中序线索树中找结点前驱 */
BiTree InPre(BiTree p)
/* 在中序线索二叉树中查找p的中序前驱，并用pre指针返回结果 */
{
	BiTree Pre,q;
	if(p->Ltag==1) Pre=p->LChild;
	else
	{	//在p的左子树中查找“最右下端”结点
		for(q=p->LChild;q->Rtag==0;q=q->RChild);
		pre=q;
	}
	return pre;
}
/* 【算法6.15】 在中序线索树中找结点后继 */
BiTree InNext(BiTree p)
/* 在中序线索二叉树中查找p的中序后继结点，并用Next指针返回结果 */
{
	BiTree Next,q;
	if(p->Rtag==1) Next=p->RChild;
	else
	{	//在p的右子树中查找“最左下端”结点
		for(q=p->RChild;q->Ltag==0;q=q->LChild);
		Next=q;
	}
	return Next;
}
/* 【算法6.16】 在中序线索树上求中序遍历的第一个结点 */
BiTree InFirst(BiTree Bt)
{
	BiTree p=Bt;
	if(!p)
		return NULL;
	while(p->Ltag==0) 
		p=p->LChild;
	return p;
}
/* 【算法6.17】 遍历中序二叉线索树 */
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
/* 【算法补充】 中序线索树的插入运算（删除类同）（以插入右子树为例） */
void InsNode(BiTree p,BiTree r)
{
	BiTree s;
	if(p->Rtag==1)	//p无右孩子
	{
		r->RChild=p->RChild;	//p的后继变为r的后继
		r->Rtag=1;
		p->RChild=r;	//r成为p的右孩子
		r->LChild=p;	//p变为r的前驱
		r->Ltag=1;
		p->Rtag=0;
	}
	else	//p有右孩子
	{
		s=p->RChild;
		while(s->Ltag==0)
			s=s->LChild;	//查找p结点的右子树的“最左下端”结点
		r->RChild=p->RChild;	//p的右孩子变为r的右孩子
		r->Rtag=0;
		r->LChild=p;	//p变为r的前驱	
		r->Ltag=1;
		p->RChild=r;	//r变为p的右孩子
		s->LChild=r;	//r变为p原来右子树的“最下左端”结点的前驱
	}
}
/* 双亲表示法结构定义(6.4 树、森林和二叉树) */
#define MAX 100
typedef struct TNode
{
	DataType data;
	int parent;
}TNode;
/* 树可以定义为 */
typedef struct
{
	TNode tree[MAX];
	int nodenum;	//结点数
}ParentTree;
/* 孩子表示法的存储结构定义 */
typedef struct ChildNode	//孩子链表结点的定义
{
	int Child;	//该孩子结点在线性表中的位置
	struct ChildNode * next;	//指向下一个孩子结点的指针
}ChildNode;
typedef struct	//顺序表结点的结构定义
{
	DataType data;	//结点的信息
	ChildNode * FirstChild;	//指向孩子链表的头指针
}DataNode;
typedef struct	//树的定义
{
	DataNode nodes[MAX];	//顺序表
	int root;	//该树的根结点在线性表中的位置
	int num;	//该树的结点个数
}ChildTree;
/* 孩子兄弟表示法的类型定义 */
typedef struct CSNode
{
	DataType data;	//结点信息
	struct CSNode * FirstChild;	//第一个孩子
	struct CSNode * Nextsibling;	//下一个兄弟
}CSNode,* CSTree;
/* 用孩子兄弟链表实现树的先根遍历 */
//方法一
void RootFirst(CSTree root)
{
	CSTree p;
	if(root!=NULL)
	{
		Visit(root->data);	//访问根结点
		p=root->FirstChild;
		while(p!=NULL)
		{
			RootFirst(p);	//访问以p为根的子树
			p=p->Nextsibling;
		}
	}
}
//方法二
void RootFirst(CSTree root)
{
	if(root!=NULL)
	{
		Visit(root->data);	//访问根结点
		RootFirst(root->FirstChild);	//先根遍历首子树
		RootFirst(root->Nextsibling);	//先根遍历兄弟树
	}
}
/* 静态三叉链表实现的哈夫曼树的类型定义 */
#define N 20	//叶子结点的最大值
#define M 2*N-1	//所有结点的最大值
typedef struct
{
	int weight;	//结点的权值
	int parent;	//双亲的下标
	int LChild;	//左孩子结点的下标
	int RChild;	//右孩子结点的下标
}HTNode,* HuffmanTree[M+1];	//HuffmanTree是一个结构数组类型，0号单元不用
/* 【算法6.18】 创建哈夫曼树算法 */
void CrtHuffmanTree(HuffmanTree ht,int w[],int n)
{	/* 构造哈夫曼树ht[M+1],w[]存放n个权值。 */
	for(i=1;i<=n;i++)
		ht[i]={w[i],0,0,0};	//1~n号单元存放叶子结点，初始化
	m=2*n-1;
	for(i=n+1;i<=m;i++)
		ht[i]={0,0,0,0};	//n+1~m号单元存放非叶结点，初始化
	/*---------------初始化完毕！对应算法步骤1-----------------*/
	for(i=n+1;i<=m;i++)	//创建非叶结点，建哈夫曼树
	{
		select(ht,i-1,&s1,&s2);	//在ht[1]~ht[i-1]的范围内选择两个parent为0且weight最小的结点，其序号分别赋值给s1,s2
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i; ht[s2].parent=i;
		ht[i].LChild=s1; ht[i].RChild=s2;
	}	//哈夫曼树建立完毕
}
/* 【算法6.19】 求哈夫曼树的哈夫曼编码的算法 */
void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
/* 从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码 */
{
	char * cd;
	cd=(char *)malloc(n*sizeof(char));	//分配求当前编码的工作空间
	cd[n-1]='\0';	//从右向左逐位存放编码，首先存放编码结束符
	for(i=1;i<=n;i++)	//求n个叶子结点对应的哈夫曼编码
	{
		start=n-1;	//初始化编码起始指针
		c=i; p=ht[i].parent;	//从叶子结点开始向上倒推
		while(p!=0)
		{
			--start;
			if(ht[p].LChild==e)	//左分支标0
				cd[start]='0';
			else
				cd[start]='1';	//右分支标1
			c=p; p=ht[p].parent;	//向上倒推
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));	//为第i个编码分配空间
		strcpy(hc[i],&cd[start]);	//把编码复制到hc[i]中
	}
	free(cd);
}
/* 以树（森林）的双亲表示法为基础，并查集类型可定义如下 */
typedef ParentTree ParentForest;
typedef ParentForest MFSat;
/* 【算法6.20】 初始化并查集 */
void Initialization(MFSat * SS,SeqList * S)
/* 用S中的n个元素构造n个单根树，代表n个单元素集合S0,S1,...,S(n-1),这n个单根树构成一个森林，代表并查集SS */
{
	int i;
	SS->nodenum=S->last+1;
	for(i=0;i<SS->nodenum;i++)
	{
		SS->tree[i].data=S->elem[i];
		SS->tree[i].parent=-1;
	}
}
/* 【算法6.21(a)】 在并查集中查找某个元素 */
int Find_1(MFSat * SS,DataType x)
/* 确定x属于并查集SS中哪个子集合。如果不属于SS中任一子集，则返回-1，否则返回所在子集树的根结点下标 */
{
	pos=Locate(SS,x);	//确定x在SS->tree[]中的下标
	if(pos<0)	//如果x不属于SS中任一子集，则返回-1
		return -1;
	i=pos;	//从pos开始，沿着双亲指针查找根结点
	while(SS->tree[i].parent>0)
		i=SS->tree[i].parent;
	return i;
}
/* 【算法6.21(b)】 在并查集中查找某个元素（改进算法） */
int Find_2(MFSat * SS,DataType x)
/* 确定x属于并查集SS中哪个子集合，同时调整子集树，降低其高度。如果x不属于SS中任一子集，则返回-1，
否则首先找到x所在子集树的根root，然后将x及x的所有祖先（除了root）均改为root的子结点，最后返回root */
{
	pos=Locate(SS,x);	//确定x在SS->tree[]中的下标
	if(pos<0) return -1;	//如果x不属于SS中任一子集，则返回-1
	i=pos;	//从pos开始，沿着双亲指针查找根结点
	while(SS->tree[i].parent>0)
		i=SS->tree[i].parent;
	root=i;	//记录x所在子树集的根结点下标
	i=pos;	//从pos开始，将x及x的所有祖先（除了root）均改为root的子结点
	while(i!=root)
	{
		temp=SS->tree[i].parent;
		SS->tree[i].parent=root;
		i=temp;
	}
	return root;	//返回x所在子集树的根结点下标
}
/* 【算法6.22(a)】 合并并查集中的子树集 */
int Merge_1(MFSat * SS,int root1,int root2)
/* root1和root2是并查集SS中两个互不相交的非空子集树的根，将子集树root2并入子集树root1 */
{
	if(root1<0 || root1> SS->nodenum-1) return ERROR;
	if(root2<0 || root2> SS->nodenum-1) return ERROR;
	SS->tree[root2].parent=root1;
	return OK;
}
/* 【算法6.22(b)】 合并并查集中的子集树 */
int Merge_2(MFSat * SS,int root1,int root2)
/* root1和root2是并查集SS中两个互不相交的非空子集树的根，根结点的parent域存放树中结点数目的负值。
本算法将结点数目较少的子集树并入结点数目较多的子集树 */
{
	if(root1<0 ||root1> SS->nodenum-1) return ERROR;
	if(root2<0 ||root2> SS->nodenum-1) return ERROR;
	if(SS->tree[root1].parent<SS->tree[root2].parent)	//第一棵子集树中结点数目较多
	{
		SS->tree[root2].parent=root1;
		SS->tree[root1].parent+=SS->tree[root2].parent;
	}
	else	//第二棵子集树中结点数目较多
	{
		SS->tree[root1].parent=root2;
		SS->tree[root2].parent+=SS->tree[root1].parent;
	}
	return OK;
}
/* 【算法6.21(b)】 在并查集中查找某个元素 */
int Find_2(MFSat * SS,DataType x)
/* 确定x属于并查集SS中哪个子集合，同时调整子集树，降低其高度。如果x不属于SS中任一子集，
则返回-1，否则首先找到x所在子集树的根root，然后将x及x的所有祖先（除了root）均改为root
的子结点，最后返回root */
{
	pos=Locate(SS,x);	//确定x在SS->tree[]中的下标
	if(pos<0) return -1;	//如果x不属于SS中任一子集，则返回-1
	i=pos;	//从pos开始，沿着双亲指针查找根结点
	while(SS->tree[i].parent>0)
		i=SS->tree[i].parent;
	root=i;	//记录x所在子集树的根结点下标
	i=pos;	//从pos开始，将x及x的所有祖先（除了root）均改为root的子结点
	while(i!=root)
	{
		temp=SS->tree[i].parent;
		SS->tree[i].parent=root;
		i=temp;
	}
	return root;	//返回x所在子集树的根结点下标
}
/* 【算法6.23】 判断二叉树t1和t2是否相似算法 */
int like(BiTree t1,BiTree t2)
/* 判断二叉树t1和t2是否相似，若相似，返回1，否则返回0 */
{
	int like1,like2;
	if(t1==NULL && t2==NULL)
		return 1;	//t1和t2均为空，相似，返回1
	else if(t1==NULL || t2==NULL)
		return 0;	//t1和t2其中之一为空树，不相似，返回0
	else
	{
		like1=like(t1->LChild,t2->LChild);	//判断t1和t2的左子树是否相似
		like2=link(t1->RChild,t2->RChild);	//判断t1和t2的右子树是否相似
		return (like1 && like2);
	}
}
/* 【算法6.24】 求出从二叉树中根结点到r所指结点之间的路径并输出 */
void path(BiTree root,BiTNode * r)
/* 求出从二叉树根结点到r结点之间的路径并输出算法 */
{
	BiTNode * p,* q;
	int i,top=0;
	BiTree s[Stack_Size];
	q=NULL;	//用q保存刚遍历过的结点，初始为空
	p=root;
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++;
			if(top>=Stack_Size)
				OverFlow();	//栈溢出处理
			s[top]=p;
			p=p->LChild;
		}	//遍历左子树
		if(top>0)
		{
			p=s[top];	//根结点
			if(p->RChild==NULL || p->RChil==q)
			{
				if(p==r)	//找到r所指结点，则显示从根结点到r所指结点之间的路径
				{
					for(i=1;i<=top;i++)
						printf("%d",s[i]->data);
					return ;
				}
				else
				{
					q=p;	//用q保存刚遍历过的结点
					top--;
					p=NULL;	//跳过前面左遍历继续退栈
				}
			}
			else
				p=p->RChild;	//遍历右子树
		}
	}
}
/* 【算法6.25】 层次遍历二叉树算法 */
int LayerOrder(BiTree bt)
/* 层次遍历二叉树bt */
{
	SeqQueue Q;
	BiTree p;
	InitQueue(&Q);	//初始化空队列Q
	if(bt==NULL)
		return ERROR;	//若二叉树bt为空树，则结束遍历
	EnterQueue(&Q,bt);	//若二叉树bt非空，则根结点bt入队，开始层次遍历
	while(!IsEmpty(Q))	//若队列非空，则遍历未结束，继续进行
	{
		DeleteQueue(&Q,&p);	//队头元素出队并访问
		visit(p->data);
		if(p->LChild) EnterQueue(&Q,p->LChild);	//若p的左孩子非空，则进队
		if(p->RChild) EnterQueue(&Q,p->RChild);	//若p的右孩子非空，则进队
	}	//while
	return OK;
}	//LayerOrder