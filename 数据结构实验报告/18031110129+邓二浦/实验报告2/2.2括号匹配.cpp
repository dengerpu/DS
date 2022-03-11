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
void push(Linkstack *L,char c)         //»Î’ª≤Ÿ◊˜
{
	Linkstack *p,*s;
    p=L;
	s=(Linkstack *)malloc(sizeof(struct node));
	s->date=c;
	s->next=p->next;
	p->next=s;
}
void pop(Linkstack *L,char *ch)           //≥ˆ’ª≤Ÿ◊˜
{
	Linkstack *p;
	p=L->next;
	L->next=p->next;
	*ch=p->date;
	free(p);
}
void gettop(Linkstack *L,char *ch)     //»°’ª∂•‘™Àÿ
{
	*ch=L->next->date;
}
int isempty(Linkstack *L)                //≈–∂œ’ª «∑ÒŒ™ø’
{
	if(L->next==NULL)
		return 1;
	else
		return 0;
}
int match(char a,char b)               //≈–∂œ¿®∫≈ «∑Ò∆•≈‰
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
			{printf("\n”“¿®∫≈∂‡”‡");return;}
			else
			{
				gettop(L,&ch);
				if(match(ch,str[i]))
					pop(L,&ch);
				else
				{printf("\n∂‘”¶µƒ◊Û”“¿®∫≈≤ªÕ¨¿‡");return;}
						
			}
			
		}
	}
	if(isempty(L))
		printf("¿®∫≈∆•≈‰\n");
	else
		printf("¿®∫≈≤ª∆•≈‰\n");
}
int main()
{
	char str[50];
	gets(str);
	pipei(str);
return 0;
}