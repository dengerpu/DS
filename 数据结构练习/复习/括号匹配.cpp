#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *next;
}linkstact;
void initstact(linkstact *l)
{
	l=(linkstact*)malloc(sizeof(struct node));	
	l->next=NULL;
}
void push(linkstact *l,char c)
{
	linkstact *p;
	p=(linkstact*)malloc(sizeof(struct node));	
	p->data=c;
	p->next=l->next;
	l->next=p;
}
void pop(linkstact *l,char *c)
{
	linkstact *p;
	p=l->next;
	*c=p->data;
	l->next=p->next;
	free(p);
}
void gettop(linkstact *l,char *a)
{
	linkstact *p;
	p=l->next;
	*a=p->data;
}
int isempty(linkstact *l)
{
	linkstact *p;
	p=l->next;
	if(p==NULL)
		return 1;
	else
		return 0;
}
int match(char a,char b)
{
	if((a=='{'&&b=='}')||(a=='('&&b==')')||(a=='['&&b==']'))
		return 1;
	else
		return 0;
}
void main()
{
	char a[100],b,c;
	gets(a);
	int i;
	linkstact l;
	initstact(&l);
	for(i=0;a[i]!='\0';i++)
	{
		switch(a[i])
		{
		case'{':
		case'[':
		case'(':push(&l,a[i]);break;
		case'}':
		case']':
		case')':
			if(isempty(&l))
			{	printf("�����Ŷ���\n");return;}
			else
			{
				gettop(&l,&b);
				if(match(b,a[i]))
					pop(&l,&c);
				else
				{printf("\n��Ӧ�������Ų�ͬ��\n");return;}
			}
		}
	}
	if(isempty(&l))
		printf("ƥ��ɹ�\n");
		else
		printf("ƥ�䲻�ɹ�\n");
	
}