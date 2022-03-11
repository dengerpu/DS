#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int row,col;
	int e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];
	int m,n,len;
}TSMatrix;
/* 列序递增转置法 */
void TransposeTSMatrix(TSMatrix A,TSMatrix * B)
{
	int i,j,k;
	B->m=A.n; B->n=A.m; B->len=A.len;
	if(B->len>0)
	{
		j=1;
		for(k=1;k<=A.n;k++)
			for(i=1;i<=A.len;i++)
				if(A.data[i].col==k)
				{
					B->data[i].col=A.data[i].row;
					B->data[i].row=A.data[i].col;
					B->data[i].e=A.data[i].e;
					j++;
				}
	}
}
/* 一次定位快速转置法 */
void FastTransposeTSMatrix(TSMatrix A,TSMatrix * B)
{
	int col,t,p,q;
	int num[MAXSIZE],position[MAXSIZE];
	B->len=A.len; B->m=A.n; B->n=A.m;
	if(B->len>0)
	{
		for(col=1;col<=A.n;col++)
			num[col]=0;
		for(t=1;t<=A.len;t++)
			num[A.data[t].col]++;
		position[1]=1;
		for(col=2;)
	}
}
