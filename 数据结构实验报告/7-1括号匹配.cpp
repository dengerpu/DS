#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char date;
	struct node *next;
}Linkstack;
void Initstack(Linkstack *L)
{
	L=(Linkstack *)malloc(sizeof(struct node));
    L->next=NULL;
}
void push(Linkstack *L,char c)         //ÈëÕ»²Ù×÷
{
	Linkstack *p,*s;
    p=L;
	s=(Linkstack *)malloc(sizeof(struct node));
	s->date=c;
	s->next=p->next;
	p->next=s;
}
void pop(Linkstack *L,char *ch)           //³öÕ»²Ù×÷
{
	Linkstack *p;
	p=L->next;
	L->next=p->next;
	*ch=p->date;
	free(p);
}
void gettop(Linkstack *L,char *ch)     //È¡Õ»¶¥ÔªËØ
{
	*ch=L->next->date;
}
int isempty(Linkstack *L)                //ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	if(L->next==NULL)
		return 1;
	else
		return 0;
}
int match(char a,char b)               //ÅÐ¶ÏÀ¨ºÅÊÇ·ñÆ¥Åä
{
	if((a=='('&&b==')')||(a=='{'&&b=='}')||(a=='['&&b==']'))
		return 1;
	else
		return 0;
}
void pipei(char *str)
{
	Linkstack *L;
	int i;char ch;
	L=(Linkstack *)malloc(sizeof(struct node));
    L->next=NULL;
	for(i=0;str[i]!='\0';i++)
	{
		switch(str[i])
		{
		case'(':
		case'{':
		case'[':
			push(L,str[i]);
			break;
		case')':
		case']':
		case'}':
			if(isempty(L))
			{printf("NO\n");	return;}
			else
			{
				gettop(L,&ch);
				if(match(ch,str[i]))
					pop(L,&ch);
				else
				{printf("NO\n"); return;}			
			}
			
		}
	}
	if(isempty(L))
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	char str[1000],a[1000];
	int i=0,j=0,k=0,b=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
		{
			j++;
			a[b++]=str[i];
		}
		else if(str[i]==')'||str[i]=='}'||str[i]==']')
		{
			k++;
			a[b++]=str[i];
		}
	}
	a[b]='\0';
	printf("%d %d\n",j,k);
	pipei(a);
	return 0;
}