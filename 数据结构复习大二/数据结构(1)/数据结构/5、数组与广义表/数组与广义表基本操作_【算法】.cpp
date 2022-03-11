#include<stdlib.h>
#define MAXSIZE 1000	/* 设非零元素的个数最多为1000 */
/* 稀疏矩阵三元组表的类型定义 */
typedef int ElementType;
typedef struct
{
	int row,col;	/* 设非零元素的行下标和列下标 */
	ElementType e;	/* 设非零元素的值 */
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];	/* 非零元素的三元组表。data[0]未用 */
	int m,n,len;	/* 矩阵的行数、列数和非零元素的个数 */
}TSMatrix;
/* 【算法5.1】 稀疏矩阵转置经典算法 */
void TransMatrix(ElementType source[m][n],ElementType dest[n][m])
{	/* source和dest分别为被转置的矩阵和转置以后的矩阵（用二维数组表示） */
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			dest[j][i]=source[i][j];
}
/* 【算法5.2】 稀疏矩阵列序递增转置算法 */
void TransposeTSMatrix(TSMatrix A,TSMatrix * B)
{	/* 把矩阵A转置到B所指向的矩阵中去。矩阵用三元组表表示 */
	int i,j,k;
	B->m=A.n; B->n=A.m; B->len=A.len;
	if(B->len>0)
	{
		j=1;	/* j为辅助计数器，记录转置后的三元组在三元组表B中的下标值 */
		for(k=1;k<=A.n;k++)
			for(i=1;i<=A.len;i++)
				if(A.data[i].col==k)	/* 从头至尾扫描三元组表A，寻找col值为k的三元组进行转置 */
				{
					B->data[j].row=A.data[i].col;
					B->data[j].col=A.data[i].row;
					B->data[j].e=A.data[i].e;
					j++;	/* 计数器j加1，指向本行下一个转置后元素的位置下标 */
				}	/* 内循环中if的结束 */
	}	/* if(B->len>0)的结束 */
}	/* end of TransposeTSMatrix */
/* 【算法5.3】 稀疏矩阵一次定位快速转置算法 */
void FastTransposeTSMatrix(TSMatrix A,TSMatrix * B)
{	/* 基于矩阵的三元组表示，采用一次定位快速转置算法，将矩阵A转置为矩阵B */
	int col,t,p,q;
	int num[MAXSIZE],position[MAXSIZE];
	B->len=A.len; B->n=A.m; B->m=A.n;
	if(B->len)
	{
		for(col=1;col<=A.n;col++)
			num[col]=0;
		for(t=1;t<=A.len;t++)
			num[A.data[t].col]++;	/* 采用数组下标计数法计算每一列的非零元素的个数 */
		position[1]=1;
		for(col=2;col<=A.n;col++)	/* 求col列中第一个非零元素在B.data[]中的正确位置 */
			position[col]=position[col-1]+num[col-1];
		for(p=1;p<=A.len;p++)	/* 将被转置矩阵的三元组表A从头至尾扫描一次，实现矩阵转置 */
		{
			col=A.data[p].col; q=position[col];	/* 行列互换，元素赋值 */
			B->data[q].row=A.data[p].col;
			B->data[q].col=A.data[p].row;
			B->data[q].e=A.data[p].e;
			position[col]++;	/* position[col]加1，指向下一个列号为col的非零元素在三元组表B中的存放位置 */
		}	/* end of for   */
	}
}
/***************************************************************/
/* 十字链表结构类型定义 */
typedef int ElementType;
typedef struct OLNode
{
	int row,col;	/* 非零元素的行和列下标 */
	ElementType value;
	struct OLNode * right,* down;	/* 非零元素所在行表、列表的后继链域 */
}OLNode,* OLink;
typedef struct
{
	OLink * row_head,* col_head;	/* 非零元素所在行表、列表的后继链域 */
	int m,n,len;	/* 稀疏矩阵的行数、列数、非零元素的个数 */
}CrossList;
/* 【算法5.4】 建立稀疏矩阵的十字链表 */
void CreateCrossList(CrossList * M)
{	/* 采用十字链表存储结构，创建稀疏矩阵M */
	scanf(&m,&n,&t);	/* 输入M的行数、列数和非零元素的个数 */
	M->m=m; M->n=n; M->len=t;
	if(!(M->row_head=(OLink *)malloc((m+1)sizeof(OLink))))
		exit(OVERFLOW);
	if(!(M->col_head=(OLink *)malloc((m+1)sizeof(OLink))))
		exit(OVERFLOW);
	M->row_head[]=M->col_head[]=NULL;	/* 初始化行、列头指针向量，各行、列链表为空的链表 */
	for(scanf(&i,&j,&e);i!=0;scanf(&i,&j,&e))
	{
		if(!(p=(OLNode *)malloc(sizeof(OLNode))))
			exit(OVERFLOW);
		p->row=i; p->col=j; p->value=e;	/* 生成结点 */
		if(M->row_head[i]==NULL)
			M->row_head[i]=p;
		else
		{	/* 寻找行表中的插入位置 */
			q=M->row_head[i];
			while(q->right!=NULL&&q->right->col<j)
				q=q->right;
			p->right=q->right; q->right=p;	/* 完成插入 */
		}
		if(M->col_head[j]==NULL)
			M->col_head[j]=p;
		else
		{	/* 寻找列表中的插入位置 */
			q=M->col_head[j];
			while(q->down!=NULL&&q->down->col<i)
				q=q->down;
			p->down=q->down; q->down=p;	/* 完成插入 */
		}
	}
}
/***************************************************************/
/* 广义表的头尾链表存储结构类型定义 */
#define OK 1
#define ERROR 0
typedef enum {ATOM,LIST} ElemTag;	/* ATOM=0,表示原子；LIST=1，表示子表 */
typedef struct GLNode
{
	ElemTag tag;	/* 标志位tag用来区别原子结点和表结点 */
	union
	{
		AtomType atom;	/* 原子结点的值域atom */
		struct {struct GLNode * hp,* tp;} htp;	/* 表结点的指针域htp，包括表头指针域hp和表尾指针域tp */
	}atom_htp;	/* atom_htp是原子结点的值域atom和表结点的指针域htp的联合体域 */
}GLNode,* GList;
/* 广义表的扩展线性链表（同层结点链）存储结构类型定义 */
typedef enum {ATOM,LIST} ElemTag;	/* ATOM=0，表示原子；LIST=1，表示子表 */
typedef struct GLNode
{
	ElemTag tag;
	union
	{
		AtomType atom;
		struct GLNode * hp;	/* 表头指针域 */
	}atom_hp;	/* atom_hp是原子结点的值域atom和表结点的表头指针域hp的联合体域 */
	struct GLNode * tp;	/* 同层下一个结点的指针域 */
}GLNode,* GList;
/* 以下算法以广义表的头尾链表存储结构为例 */
typedef enum {ATOM,LIST} ElemTag;	/* ATOM=0,表示原子；LIST=1，表示子表 */
typedef struct GLNode
{
	ElemTag tag;	/* 标志位tag用来区别原子结点和表结点 */
	union
	{
		AtomType atom;	/* 原子结点的值域atom */
		struct {struct GLNode * hp,* tp;} htp;	/* 表结点的指针域htp，包括表头指针域hp和表尾指针域tp */
	}atom_htp;	/* atom_htp是原子结点的值域atom和表结点的指针域htp的联合体域 */
}GLNode,* GList;
/* 【算法5.5】 求广义表L的表头 */
GList Head(GList L)
{	/* 求广义表L的表头，并返回表头指针 */
	if(L==NULL)
		return NULL;	/* 空表无表头 */
	if(L->tag==ATOM)
		exit(0);	/* 原子不是表 */
	else
		return (L->atom_htp.htp.hp);
}
/* 【算法5.6】 求广义表L的表尾 */
GList Tail(GList L)
{	/* 求广义表L的表尾，并返回表尾指针 */
	if(L==NULL)
		return NULL;	/* 空表无表尾 */
	if(L->tag==ATOM)
		exit(0);	/* 原子不是表 */
	else
		return (L->atom_htp.htp.tp);
}
/* 【算法5.7】 求广义表的长度 */
int Length(GList L)
{	/* 求广义表L的长度，并返回长度值 */
	int k=0;
	GLNode * s;
	if(L==NULL)
		return 0;	/* 空表长度为0 */
	if(L->tag==ATOM)
		exit(0);	/* 原子不是表 */
	s=L;
	while(s!=NULL)	/* 统计最上层表的长度 */
	{
		k++;
		s=s->atom_htp.htp.tp;
	}
	return (k);
}
/* 【算法5.8】 求广义表的深度 */
int Depth(GList L)
{
	int d,max;
	GLNode * s;
	if(L==NULL)	/* 空表深度为1 */
		return 1;	
	if(L->tag==ATOM)	/* 原子深度为0 */
		return 0;
	s=L;
	while(s!=NULL)	/* 求每个子表的深度的最大值 */
	{
		d=Depth(s->atom_htp.htp.hp);
		if(d>max)
			max=d;
		s=s->atom_htp.htp.tp;
	}
	return (max+1);	/* 表的深度等于最深子表的深度加1 */
}
/* 【算法5.9】 统计广义表中原子数目 */
int CountAtom(GList L)
{	/* 求广义表L中原子结点数目，并返回原子结点数目值 */
	int n1,n2;
	if(L==NULL)	/* 空表中没有原子 */
		return 0;
	if(L->tag==ATOM)	/* L指向单个原子 */
		return 1;
	n1=CountAtom(L->atom_htp.htp.hp);	/* 求表头中的原子数目 */
	n2=CountAtom(L->atom_htp.htp.tp);	/* 求表尾中的原子数目 */
	return (n1+n2);
}
/* 【算法5.10】 复制广义表 */
int CopyGList(GList S,GList * T)
{
	if(S==NULL)	/* 复制空表 */
	{
		* T=NULL;
		return OK;
	}
	* T=(GLNode *)malloc(sizeof(GLNode));
	if(* T==NULL)
		return (ERROR);
	(* T)->tag=S->tag;
	if(S->tag==ATOM)	/* 复制单个原子 */
		(* T)->atom=S->atom;
	else
	{
		CopyGList(S->atom_htp.htp.hp,&((&T)->atom_htp.htp.hp));	/* 复制表头 */
		CopyGList(S->atom_htp.htp.tp,&((&T)->atom_htp.htp.tp));	/* 复制表尾 */
	}
	return (OK);
}