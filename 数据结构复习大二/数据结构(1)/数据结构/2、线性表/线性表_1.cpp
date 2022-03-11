/* 多项式相加问题 */
#include<stdio.h>
#include<stdlib.h>
typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode * next;
}Polynode,* Polylist;
