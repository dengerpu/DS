#include<stdlib.h>
#define MAXSIZE 1000	/* �����Ԫ�صĸ������Ϊ1000 */
/* ϡ�������Ԫ�������Ͷ��� */
typedef int ElementType;
typedef struct
{
	int row,col;	/* �����Ԫ�ص����±�����±� */
	ElementType e;	/* �����Ԫ�ص�ֵ */
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];	/* ����Ԫ�ص���Ԫ���data[0]δ�� */
	int m,n,len;	/* ����������������ͷ���Ԫ�صĸ��� */
}TSMatrix;
/* ���㷨5.1�� ϡ�����ת�þ����㷨 */
void TransMatrix(ElementType source[m][n],ElementType dest[n][m])
{	/* source��dest�ֱ�Ϊ��ת�õľ����ת���Ժ�ľ����ö�ά�����ʾ�� */
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			dest[j][i]=source[i][j];
}
/* ���㷨5.2�� ϡ������������ת���㷨 */
void TransposeTSMatrix(TSMatrix A,TSMatrix * B)
{	/* �Ѿ���Aת�õ�B��ָ��ľ�����ȥ����������Ԫ����ʾ */
	int i,j,k;
	B->m=A.n; B->n=A.m; B->len=A.len;
	if(B->len>0)
	{
		j=1;	/* jΪ��������������¼ת�ú����Ԫ������Ԫ���B�е��±�ֵ */
		for(k=1;k<=A.n;k++)
			for(i=1;i<=A.len;i++)
				if(A.data[i].col==k)	/* ��ͷ��βɨ����Ԫ���A��Ѱ��colֵΪk����Ԫ�����ת�� */
				{
					B->data[j].row=A.data[i].col;
					B->data[j].col=A.data[i].row;
					B->data[j].e=A.data[i].e;
					j++;	/* ������j��1��ָ������һ��ת�ú�Ԫ�ص�λ���±� */
				}	/* ��ѭ����if�Ľ��� */
	}	/* if(B->len>0)�Ľ��� */
}	/* end of TransposeTSMatrix */
/* ���㷨5.3�� ϡ�����һ�ζ�λ����ת���㷨 */
void FastTransposeTSMatrix(TSMatrix A,TSMatrix * B)
{	/* ���ھ������Ԫ���ʾ������һ�ζ�λ����ת���㷨��������Aת��Ϊ����B */
	int col,t,p,q;
	int num[MAXSIZE],position[MAXSIZE];
	B->len=A.len; B->n=A.m; B->m=A.n;
	if(B->len)
	{
		for(col=1;col<=A.n;col++)
			num[col]=0;
		for(t=1;t<=A.len;t++)
			num[A.data[t].col]++;	/* ���������±����������ÿһ�еķ���Ԫ�صĸ��� */
		position[1]=1;
		for(col=2;col<=A.n;col++)	/* ��col���е�һ������Ԫ����B.data[]�е���ȷλ�� */
			position[col]=position[col-1]+num[col-1];
		for(p=1;p<=A.len;p++)	/* ����ת�þ������Ԫ���A��ͷ��βɨ��һ�Σ�ʵ�־���ת�� */
		{
			col=A.data[p].col; q=position[col];	/* ���л�����Ԫ�ظ�ֵ */
			B->data[q].row=A.data[p].col;
			B->data[q].col=A.data[p].row;
			B->data[q].e=A.data[p].e;
			position[col]++;	/* position[col]��1��ָ����һ���к�Ϊcol�ķ���Ԫ������Ԫ���B�еĴ��λ�� */
		}	/* end of for   */
	}
}
/***************************************************************/
/* ʮ������ṹ���Ͷ��� */
typedef int ElementType;
typedef struct OLNode
{
	int row,col;	/* ����Ԫ�ص��к����±� */
	ElementType value;
	struct OLNode * right,* down;	/* ����Ԫ�������б��б�ĺ������ */
}OLNode,* OLink;
typedef struct
{
	OLink * row_head,* col_head;	/* ����Ԫ�������б��б�ĺ������ */
	int m,n,len;	/* ϡ����������������������Ԫ�صĸ��� */
}CrossList;
/* ���㷨5.4�� ����ϡ������ʮ������ */
void CreateCrossList(CrossList * M)
{	/* ����ʮ������洢�ṹ������ϡ�����M */
	scanf(&m,&n,&t);	/* ����M�������������ͷ���Ԫ�صĸ��� */
	M->m=m; M->n=n; M->len=t;
	if(!(M->row_head=(OLink *)malloc((m+1)sizeof(OLink))))
		exit(OVERFLOW);
	if(!(M->col_head=(OLink *)malloc((m+1)sizeof(OLink))))
		exit(OVERFLOW);
	M->row_head[]=M->col_head[]=NULL;	/* ��ʼ���С���ͷָ�����������С�������Ϊ�յ����� */
	for(scanf(&i,&j,&e);i!=0;scanf(&i,&j,&e))
	{
		if(!(p=(OLNode *)malloc(sizeof(OLNode))))
			exit(OVERFLOW);
		p->row=i; p->col=j; p->value=e;	/* ���ɽ�� */
		if(M->row_head[i]==NULL)
			M->row_head[i]=p;
		else
		{	/* Ѱ���б��еĲ���λ�� */
			q=M->row_head[i];
			while(q->right!=NULL&&q->right->col<j)
				q=q->right;
			p->right=q->right; q->right=p;	/* ��ɲ��� */
		}
		if(M->col_head[j]==NULL)
			M->col_head[j]=p;
		else
		{	/* Ѱ���б��еĲ���λ�� */
			q=M->col_head[j];
			while(q->down!=NULL&&q->down->col<i)
				q=q->down;
			p->down=q->down; q->down=p;	/* ��ɲ��� */
		}
	}
}
/***************************************************************/
/* ������ͷβ����洢�ṹ���Ͷ��� */
#define OK 1
#define ERROR 0
typedef enum {ATOM,LIST} ElemTag;	/* ATOM=0,��ʾԭ�ӣ�LIST=1����ʾ�ӱ� */
typedef struct GLNode
{
	ElemTag tag;	/* ��־λtag��������ԭ�ӽ��ͱ��� */
	union
	{
		AtomType atom;	/* ԭ�ӽ���ֵ��atom */
		struct {struct GLNode * hp,* tp;} htp;	/* �����ָ����htp��������ͷָ����hp�ͱ�βָ����tp */
	}atom_htp;	/* atom_htp��ԭ�ӽ���ֵ��atom�ͱ����ָ����htp���������� */
}GLNode,* GList;
/* ��������չ��������ͬ���������洢�ṹ���Ͷ��� */
typedef enum {ATOM,LIST} ElemTag;	/* ATOM=0����ʾԭ�ӣ�LIST=1����ʾ�ӱ� */
typedef struct GLNode
{
	ElemTag tag;
	union
	{
		AtomType atom;
		struct GLNode * hp;	/* ��ͷָ���� */
	}atom_hp;	/* atom_hp��ԭ�ӽ���ֵ��atom�ͱ���ı�ͷָ����hp���������� */
	struct GLNode * tp;	/* ͬ����һ������ָ���� */
}GLNode,* GList;
/* �����㷨�Թ�����ͷβ����洢�ṹΪ�� */
typedef enum {ATOM,LIST} ElemTag;	/* ATOM=0,��ʾԭ�ӣ�LIST=1����ʾ�ӱ� */
typedef struct GLNode
{
	ElemTag tag;	/* ��־λtag��������ԭ�ӽ��ͱ��� */
	union
	{
		AtomType atom;	/* ԭ�ӽ���ֵ��atom */
		struct {struct GLNode * hp,* tp;} htp;	/* �����ָ����htp��������ͷָ����hp�ͱ�βָ����tp */
	}atom_htp;	/* atom_htp��ԭ�ӽ���ֵ��atom�ͱ����ָ����htp���������� */
}GLNode,* GList;
/* ���㷨5.5�� ������L�ı�ͷ */
GList Head(GList L)
{	/* ������L�ı�ͷ�������ر�ͷָ�� */
	if(L==NULL)
		return NULL;	/* �ձ��ޱ�ͷ */
	if(L->tag==ATOM)
		exit(0);	/* ԭ�Ӳ��Ǳ� */
	else
		return (L->atom_htp.htp.hp);
}
/* ���㷨5.6�� ������L�ı�β */
GList Tail(GList L)
{	/* ������L�ı�β�������ر�βָ�� */
	if(L==NULL)
		return NULL;	/* �ձ��ޱ�β */
	if(L->tag==ATOM)
		exit(0);	/* ԭ�Ӳ��Ǳ� */
	else
		return (L->atom_htp.htp.tp);
}
/* ���㷨5.7�� ������ĳ��� */
int Length(GList L)
{	/* ������L�ĳ��ȣ������س���ֵ */
	int k=0;
	GLNode * s;
	if(L==NULL)
		return 0;	/* �ձ���Ϊ0 */
	if(L->tag==ATOM)
		exit(0);	/* ԭ�Ӳ��Ǳ� */
	s=L;
	while(s!=NULL)	/* ͳ�����ϲ��ĳ��� */
	{
		k++;
		s=s->atom_htp.htp.tp;
	}
	return (k);
}
/* ���㷨5.8�� ���������� */
int Depth(GList L)
{
	int d,max;
	GLNode * s;
	if(L==NULL)	/* �ձ����Ϊ1 */
		return 1;	
	if(L->tag==ATOM)	/* ԭ�����Ϊ0 */
		return 0;
	s=L;
	while(s!=NULL)	/* ��ÿ���ӱ����ȵ����ֵ */
	{
		d=Depth(s->atom_htp.htp.hp);
		if(d>max)
			max=d;
		s=s->atom_htp.htp.tp;
	}
	return (max+1);	/* �����ȵ��������ӱ����ȼ�1 */
}
/* ���㷨5.9�� ͳ�ƹ������ԭ����Ŀ */
int CountAtom(GList L)
{	/* ������L��ԭ�ӽ����Ŀ��������ԭ�ӽ����Ŀֵ */
	int n1,n2;
	if(L==NULL)	/* �ձ���û��ԭ�� */
		return 0;
	if(L->tag==ATOM)	/* Lָ�򵥸�ԭ�� */
		return 1;
	n1=CountAtom(L->atom_htp.htp.hp);	/* ���ͷ�е�ԭ����Ŀ */
	n2=CountAtom(L->atom_htp.htp.tp);	/* ���β�е�ԭ����Ŀ */
	return (n1+n2);
}
/* ���㷨5.10�� ���ƹ���� */
int CopyGList(GList S,GList * T)
{
	if(S==NULL)	/* ���ƿձ� */
	{
		* T=NULL;
		return OK;
	}
	* T=(GLNode *)malloc(sizeof(GLNode));
	if(* T==NULL)
		return (ERROR);
	(* T)->tag=S->tag;
	if(S->tag==ATOM)	/* ���Ƶ���ԭ�� */
		(* T)->atom=S->atom;
	else
	{
		CopyGList(S->atom_htp.htp.hp,&((&T)->atom_htp.htp.hp));	/* ���Ʊ�ͷ */
		CopyGList(S->atom_htp.htp.tp,&((&T)->atom_htp.htp.tp));	/* ���Ʊ�β */
	}
	return (OK);
}