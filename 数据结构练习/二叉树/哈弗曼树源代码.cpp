#include<stdio.h>
#define maxsize 100
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}htnode;
typedef htnode hfmt[maxsize];
int n;
void inithfmt(hfmt t)   //初始化
{
	int i,n;
	printf("请输入有多少个权值");
	scanf("%d",&n);getchar();
	for(i=0;i<2*n-1;i++)
	{
		t[i].weight=0;
		t[i].lchild=-1;
		t[i].rchild=-1;
		t[i].parent=-1;
	}
	
}
void inputweight(hfmt t)  //输入权值
{
	int w,i;
	for(i=0;i<n;i++)
	{
		printf("输入第%d个权值\n",i+1);
		scanf("%d",&w);getchar();
		t[i].weight=w;
	}
}
void select(hfmt t,int i,int *p1,int *p2)
{
	long min1=999999;
	long min2=999999;
	int j;
	for(j=0;j<=i;j++)
	{
		if(t[j].parent==-1)
		{
			if(min1>t[j].weight)
			{
				min1=t[j].weight;
				*p1=j;
			}
		}
	}
	for(j=0;j<=i;j++)
	{
		if(t[j].parent==-1)
		{
			if(min2>t[j].weight&&j!=(*p1))
			{
				min2=t[j].weight;
				*p2=j;
			}
		}
	}
}
void creathfmt(hfmt t)
{
	int i,p1,p2;
	inithfmt(t);
	inputweight(t);
	for(i=n;i<2*n-1;i++)
	{
		select(t,i-1,&p1,&p2);
		t[p1].parent=t[p2].parent=i;
		t[i].lchild=t[p1].weight;
		t[i].rchild=t[p2].weight;
		t[i].weight=t[p1].weight+t[p2].weight;
	}
}
void printhfmt(hfmt t)
{
	printf("哈弗曼树的各边显示:");
	int i=0,k=0;
	for(i=0;i<2*n-1;i++)
	{
		while(t[i].lchild!=-1)
		{
			if(!(k%2))
				printf("\n");
			printf("\t\t(%d,%d),(%d,%d)",t[i].weight,t[i].lchild,t[i].rchild,t[i].parent);
			k++;break;
		}
		printf("\n\n");
	}
}
void hfnode(hfmt t,int i,int j)
{
	j=t[i].parent;
	if(t[i].rchild==t[i].weight)
		printf("1");
	else
		printf("0");
	if(t[j].parent!=-1)
		i=j;hfnode(t,i,j);
}
void huffmannode(hfmt t)
{
	printf("\t\t输入的权值对应的哈弗编码：");
	int i,j,a,k=0;
	for(i=0;i<n;i++)
	{
		j=0;
		a=i;
		if(!(k%2))
			printf("\n");
		printf("\t\t%i:",t[i].weight);
		k++;hfnode(t,i,j);
		i=a;
	}
}
void main()
{
	hfmt ht;
	creathfmt(ht);
	printhfmt(ht);
	huffmannode(ht);
	printf("\n");
}