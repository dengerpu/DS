#define N 20
#define M 2*N-1
typedef struct
{
int weight;
int parent;
int lchild;
int rchild;
}hitnode,huffmantree[M+1];
void creathuffmantree(huffmantree ht,int w[],int n)
{
	for(int i=1;i<=n;i++)ht[i]={w[i],0,0,0};  //1~n号单元存放叶子结点，初始化
	int m=2*n-1;
	for(i=n+1;u=i<=m;i++) ht[i]={0,0,0,0};
	for(i=n+1;i<=m;i++)
	{
	select(ht,i-1,&s1,&s2);
	ht[i].weight=ht[s1].weight+ht[s2].weight;
	ht[s1].parent=i;ht[s2].parent=i;
	ht[i].lchild=s1;ht[i].rchild=s2;
	}
}