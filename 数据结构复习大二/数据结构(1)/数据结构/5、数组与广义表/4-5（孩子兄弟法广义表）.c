/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
typedef struct GLNode
{
	int tag;
	int bt;
	union
	{
		char date;
		struct GLNode *hp;
	}htp;
	struct GLNode *tp;
}GLNode,*GList;
GLNode *Create()
{
	GList l;
	int t;//t=1为表，t=0为原子，t=-1为空
	char e;
	l=(GList)malloc(sizeof(GLNode));
	scanf("%d",&t);
	l->tag=t;
	if(t==1)
	{
		l->htp.hp=Create();
		l->tp=Create();
	}
	else if(t==0)
	{
		scanf(" %c",&e);
		l->htp.date=e;
		l->tp=Create();	
	}
	else//即t=-1
	{
		l=NULL;
	}
	return l;
}
void Show(GLNode *l)
{
	GList p=l;
	static int i=0,j=0;
	if(p==NULL)
	{
		
		if(i>j)
		{
			printf(")");
			j++;
		}
		return;
	}
	if(p->tag==1)
	{
		i++;
		printf("(");
		Show(p->htp.hp);
		Show(p->tp);	
	}
	else//即p->tag==0
	{
		printf("%c",p->htp.date);
		if(p->tp!=NULL)
			printf(",");
		Show(p->tp);
	}
}
main()
{
    GList l;
    l=Create();
    Show(l);
}