/* ����ʽ������� */
#include<stdio.h>
#include<stdlib.h>
typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode * next;
}Polynode,* Polylist;
