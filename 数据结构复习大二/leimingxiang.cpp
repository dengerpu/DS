#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
Node *buildlist()
{
	Node *h,*r,*s;
	int n;
	scanf("%d",&n);
	r=(Node*)malloc(sizeof(Node));
	h=r;
	while(n!=-1)
	{
		s=(Node*)malloc(sizeof(Node));
		s->data=n;
		r->next=s;
		r=s;
		scanf("%d",&n);
	}
	r->next=NULL;
	return h;
}
void del(Node *h,int n)
{
	Node *p,*s,*r;
	int i=0;
	r=h->next;
	s=h->next;
	p=h->next;
	while(p!=NULL)
	{
		i++;
		if(p->data==n)
		{
			break;
		}
		p=p->next;
	}
	for(int k=0;k<i-1;k++)
	{
		s=s->next;
	}
	printf("现在s指的数是%d\n",s->data);
	s->next=p->next;
	free(p);
	while(r!=NULL)
	{
		printf("%d ",r->data);
		r=r->next;
	}
	printf("\n");
}
int main()
{
	Node *h1;
	int n;
	h1=buildlist();
	printf("请输入要删除的元素:\n");
		scanf("%d",&n);
	del(h1,n);
	return 0;
}