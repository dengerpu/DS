/* ¿®∫≈∆•≈‰ */

/* ¡¥’ª µœ÷ */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char ch;
	struct node * next;
}LinkStackNode,* LinkStack;
void InitStack(LinkStack S)
{
	S->next=NULL;
}
void Push(LinkStack S,char ch)
{
	LinkStack Newbase;
	Newbase=(LinkStack)malloc(sizeof(LinkStackNode));
	if(!Newbase)
		return ;
	Newbase->ch=ch;
	Newbase->next=S->next;
	S->next=Newbase;
}
void Pop(LinkStack S,char * ch)
{
	LinkStack p;
	p=S->next;
	if(p==NULL)
		return ;
	* ch=p->ch;
	S->next=p->next;
	free(p);
}
void GetTop(LinkStack S,char * ch)
{
	if(S->next==NULL)
		return ;
	* ch=S->next->ch;
}
int IsEmpty(LinkStack S)
{
	if(S->next==NULL)
		return 1;
	return 0;
}
int Match(char ch,char str)
{
	if((ch=='('&&str==')')||(ch=='['&&str==']')||(ch=='{'&&str=='}'))
		return 1;
	return 0;
}
void BracketMatch(LinkStackNode S,char * str)
{
	int i;
	char ch;
	for(i=0;str[i]!='\0';i++)
	{
		switch(str[i])
		{
			case '(':
			case '[':
			case '{':
				Push(&S,str[i]);
				break;
			case ')':
			case ']':
			case '}':
				if(IsEmpty(&S))
				{
					printf("”“¿®∫≈∂‡”‡£°\n");
					return ;
				}
				else
				{
					GetTop(&S,&ch);
					if(Match(ch,str[i]))
						Pop(&S,&ch);
					else
					{
						printf("◊Û”“¿®∫≈≤ª∆•≈‰£°\n");
						return ;
					}
				}
		}
	}
	if(IsEmpty(&S))
		printf("¿®∫≈∆•≈‰£°\n");
	else
		printf("◊Û¿®∫≈∂‡”‡£°\n");
}
int main()
{
	char str[100];
	LinkStackNode S;
	InitStack(&S);
	gets(str);
	BracketMatch(S,str);
	return 0;
}
/* À≥–Ú’ª µœ÷ */
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct
{
	char ch[MAXSIZE];
	int top;
}SeqStack;
void InitStack(SeqStack * S)
{
	S->top=-1;
}
void Push(SeqStack * S,char ch)
{
	if(S->top==MAXSIZE-1)
		return ;
	S->ch[++S->top]=ch;
}
void Pop(SeqStack * S,char * ch)
{
	if(S->top==-1)
		return ;
	* ch=S->ch[S->top--];
}
void GetTop(SeqStack S,char * ch)
{
	if(S.top==-1)
		return ;
	* ch=S.ch[S.top];
}
int IsEmpty(SeqStack S)
{
	if(S.top==-1)
		return 1;
	return 0;
}
int Match(char ch,char str)
{
	if((ch=='('&&str==')')||(ch=='['&&str==']')||(ch=='{'&&str=='}'))
		return 1;
	return 0;
}
void BracketMatch(SeqStack S,char * str)
{
	int i;
	char ch;
	for(i=0;str[i]!='\0';i++)
	{
		switch(str[i])
		{
			case '(':
			case '[':
			case '{':
				Push(&S,str[i]);
				break;
			case ')':
			case ']':
			case '}':
				if(IsEmpty(S))
				{
					printf("”“¿®∫≈∂‡”‡£°\n");
					return ;
				}
				else
				{
					GetTop(S,&ch);
					if(Match(ch,str[i]))
						Pop(&S,&ch);
					else
					{
						printf("◊Û”“¿®∫≈≤ª∆•≈‰£°\n");
						return ;
					}
				}
		}
	}
	if(!IsEmpty(S))
		printf("◊Û¿®∫≈∂‡”‡£°\n");
	else
		printf("¿®∫≈∆•≈‰£°\n");
}
int main()
{
	char str[100];
	SeqStack S;
	InitStack(&S);
	gets(str);
	BracketMatch(S,str);
	return 0;
}
*/
