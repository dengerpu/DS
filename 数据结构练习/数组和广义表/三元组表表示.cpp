#define maxsize 100
typedef struct
{
	int row,col;
	int e;
}Triple;    //triple ：三倍的
typedef struct
{
	Triple data[maxsize];
	int m,n,len;
}TSMatrix;   //matrix :矩阵
void transMatrix(int a[m][n],int b[n][m])   //数组转置
{
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			b[i][j]=a[j][i];
}
void (TSMatrix *B,TSMatrix A)    //列序递增转置法
{
	B->m=A.n;B->n=A.m;B->len=A.len;
	int i,j,k;
	if(B->len>0)
	{
		j=1;
		for(k=1;k<=B->m;k++)
			for(i=1;i<=A.len;i++)
				if(A.data[i].col==k)
				{
					B->data[j].row=A.data[i].col;
					B->data[j].col=A.data[i].row;
					B->data[j].e=A.data[i].e;
					j++;
				}
	}
}
void fasttransposeTSMatrix(TSMatrix A,TSMatrix *B)
{
	int col,t,p,q;
	int num[maxsize],position[maxsize];
	B->len=A.len ;B->n =A.m ;B->m =A.n ;
	if(B->len >0)
	{
		for(col=1;col<=A.n ;col++)
			num[col]=0;
		for(t=1;t<=A.len ;t++)
			num[A.data [t].col]++;
		position[1]=1;
		for(col=2;col<=A.n ;col++)
			position[col]=position[col-1]+num[col-1];
		for(p=1;p<A.len ;p++)
		{
			col=A.data[p].col;q=position[col];
			B->data [q].row =A.data [p].col ;
			B->data [q].col =A.data [p].row ;
			B->data [q].e =A.data [p].e ;
			position[col]++;
		}
	}
}
/*void TSmatrix(TSMatrix *B,TSMatrix A)
{
	int col,t,p,q;
	int num[maxsize],position[maxsize];
	for(col=1;col<=A.n ;col++)
		num[col]=0;
	for(t=1;t<=A.len ;t++)
		num[A.data [t].col ]++;
	position[1]=1;
	for(col=2;col<=A.n ;col++)
		position[col]=position[col-1]+num[col-1];
	for(p=1;p<=A.len ;p++)
	{
		col=A.data [p].col;q=position[col];
		B->data [q].col =A.data [p].row ;
		B->data [q].row =A.data [p].col ;
		B->data [q].e =A.data [p].e ;
		position[col]++;
	}
}
*/