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
void push(Linkstack *L,char c)         //��ջ����
{
	Linkstack *p,*s;
    p=L;
	s=(Linkstack *)malloc(sizeof(struct node));
	s->date=c;
	s->next=p->next;
	p->next=s;
}
void pop(Linkstack *L,char *ch)           //��ջ����
{
	Linkstack *p;
	p=L->next;
	L->next=p->next;
	*ch=p->date;
	free(p);
}
void gettop(Linkstack *L,char *ch)     //ȡջ��Ԫ��
{
	*ch=L->next->date;
}
int isempty(Linkstack *L)                //�ж�ջ�Ƿ�Ϊ��
{
	if(L->next==NULL)
		return 1;
	else
		return 0;
}
int match(char a,char b)               //�ж������Ƿ�ƥ��
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
			{printf("\n�����Ŷ���");return;}
			else
			{
				gettop(L,&ch);
				if(match(ch,str[i]))
					pop(L,&ch);
				else
				{printf("\n��Ӧ���������Ų�ͬ��");return;}
						
			}
			
		}
	}
	if(isempty(L))
		printf("����ƥ��\n");
	else
		printf("���Ų�ƥ��\n");
}
int main()
{
	char str[50];
	gets(str);
	pipei(str);
return 0;
}