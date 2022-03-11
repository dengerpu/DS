#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int a;
	int b;
	struct node *next;
}*linklist;
void creat(linklist l)
{
	linklist p;
	int a,b;
	scanf("%d%d",&a,&b);
	while(a!=0&&b!=0)
	{
		p=(linklist)malloc(sizeof(struct node));
		p->a=a;
		p->b=b;
		l->next=p;
		l=p;
		scanf("%d%d",&a,&b);
	}
	l->next=NULL;	
}
void jisuan(linklist l)
{
	int x,i,y=0,s;
	linklist p;
	printf("ÇëÊäÈëxµÄÖµ\n");
	scanf("%d",&x);
	p=l->next;
	while(p!=NULL)
	{
		s=1;
		for(i=0;i<p->b;i++)
			s*=x;
		y+=(p->a)*s;
		p=p->next;
	}
	printf("%d\n",y);
}
void main()
{
	linklist l;
	l=(linklist)malloc(sizeof(struct node));
	creat(l);
	jisuan(l);
}