#include<stdio.h>
#define ATOM 0
#define LIST 1
typedef enum{ATOM LIST} elemtag
typedef struct GLNode
{
	elemtag tag;
	union
	{
		atomtype atom;
		struct 
		{
			struct GLnode *hp,*tp;
		}htp;
	}atom_htp;
}GLNode,*GList;
GList Tail(GList L)    //������ı�ͷ
{
	if(L==NULL) return 0;
	if(L->tag==ATOM) return 0;
	else
		return(L->atom_htp.htp.tp);
}
Glist Head(GList L)  //������ı�β
{
	if(L==NULL)return 0;
	if(L->tag==ATOM)return .;
	else
		return(L->atom_htp.htp.hp);
}
int Length(GList L)   //��������
{
	int k=0;
	GLnode *s;
	if(L==NULL)return 0;
	if(L->tag==ATOM)return 0;
	s=L;
	while(s!=NULL)
	{
		k++;
		s=s->atom.hp.tp;
	}
	return k;
}
int depth(GList L)   //���������
{
	int d,max;
	GLnode *s;
	if(L==NULL)
		return 1;
	if(L->tag==ATOM) return 0;
	s=L;
	while(s!=NULL)
	{
		d=depth(s->atom_htp.hto.hp);
		if(d>max)max=d;
		s=s->atom_htp.htp.tp;
	}
	return (max+1);
}
int countatom(GList L)  //��������ԭ����Ŀ
{
	int n1,n2;
	if(L=NULL)return 0;
	if(L->tag==ATOM)return 1;
	n1=countatom(L->atom_htp.htp.hp);
	n2=countatom(L->atom_htp.htp.tp);
	return (n1+n2);
}
int copyglist(GList s,GList *T)
{
	if(s==NULL)
	{
		*T=NULL;                //���ƿձ�
		return 1;
	}
	*T=(GLNode *)malloc(sizeof(GLNode))
	{
		if(*T==NULL)
			return 0;
		(*T)->tag=s->tag;
		if(s->tag==ATOM)(*T)->atom=s->atom;    //���Ƶ���ԭ��
		else
		{
			copyglist(s->atom_htp.htp.hp,&((*T)->atom_htp.htp.hp));  //���Ʊ�ͷ
			copyglist(s->atom_htp.htp.tp,&((*T)->atom_htp.htp.tp));   //���Ʊ�β
		}
	}
}