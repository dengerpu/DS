#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
#define max 1000			//最多顶点个数
#define INFINITY 32768		//表示极大值
int visited[max],select;
int father[max],min,num;	//用来存放父亲节点
int path[max];				//用来保存选边的顺序
int n,m,low=0,cunt=1;		//代表顶点数，m代表弧数
int elect[max],back[max],go[max],end[max],value[max],cost[max][max];
typedef struct
{
	char vertex[max];		//用来存放顶点向量
	int arcx[max][max];		//邻接矩阵，用来存放顶点之间的关系
	int vexnum,arcnum;		//用来存放顶点数和弧数
}Mgraph;
Mgraph G;
typedef struct node
{
	int from;    
	int end;
	int dis;   //记录权值
}edged[100];
edged e;
edged p;
void InitMgraph()
{
	int i,j,x,y,z;
	srand(time(NULL));
	for(i=1;i<=G.vexnum;i++)
		father[i]=i;      //初始化，每个顶点的父亲节点是自己本身
	for(i=1;i<=G.vexnum;i++)
		G.vertex[i]=i+64;
	for(i=1;i<=G.vexnum;i++)
		for(j=1;j<=G.vexnum;j++)
			G.arcx[i][j]=INFINITY;
		if(select==1)
		{
			printf("(顶点对形式)**********************\n");
			for(i=1;i<=G.arcnum;i++)
			{
				x=rand()%G.vexnum+1;
				y=rand()%G.vexnum+1;
				while(x==y||(G.arcx[x][y]<INFINITY&&G.arcx[y][x]<INFINITY))
				{
					x=rand()%G.vexnum+1;
					y=rand()%G.vexnum+1;
				}
				z=rand()%30+1;  //权值范围在1,30;
				p[i].from=x;e[i].from=x;
				p[i].end=y;e[i].end=y;
				p[i].dis=z;e[i].dis=z;
				G.arcx[x][y]=G.arcx[y][x]=z;
				printf("%d %d %d\n",x,y,z);
			}
		}
		if(select==2)
		{
			printf("(顶点对形式)**********************\n");
			for(i=1;i<=G.arcnum;i++)
			{	
				scanf("%d%d%d",&x,&y,&z);
				p[i].from=x;e[i].from=x;
				p[i].end=y;e[i].end=y;
				p[i].dis=z;e[i].dis=z;
				G.arcx[x][y]=G.arcx[y][x]=z;
			}
		}
		
}
void printMgarph()
{
	
	printf("(矩阵形式)**********************\n");
	int i,j;
	for(i=1;i<=G.vexnum;i++)
		printf("%c	",G.vertex[i]);
	printf("\n");
	for(i=1;i<=G.vexnum;i++)
	{
		for(j=1;j<=G.vexnum;j++)
			printf("%d	",G.arcx[i][j]);
		printf("\n");
	}
}
void DFS(int v)    //深度优先搜索遍历
{
	int i;
	printf("%c ",G.vertex[v]);
	visited[v]=1;  
	for(i=1;i<=G.vexnum;i++)
	{
		if(!visited[i]&&G.arcx[v][i]<INFINITY)
			DFS(i);
	}
}
void BFS(int v)   //广度优先搜索遍历
{
	int queue[max],front=0,rear=1,i,a[max],k=0,j;
	queue[rear]=v;
	visited[v]=0;
	printf("%c ",G.vertex[v]);
	while(front!=rear)
	{
		front++;
		v=queue[front];
		k=0;
		for(i=1;i<=G.vexnum;i++)
			if(G.arcx[v][i]<INFINITY)
				a[k++]=i;
			j=0;
			while(j<k)
			{
				if(visited[a[j]]==1)
				{
					visited[a[j]]=0;
					printf("%c ",G.vertex[a[j]]);
					rear++;
					queue[rear]=a[j];
				}
				j++;
			}			
	}	
}
void foreach()
{
	int i,v=1;
	visited[max]=0;   //用来标记是否被访问过
	printf("(深度优先搜索)********************\n");
	DFS(v);
	printf("\n");
	for(i=1;i<=G.vexnum;i++)
		if(visited[i]==0)  
		{
			DFS(i);
			printf("\n");
		}
		printf("(广度优先搜索)********************\n");
		BFS(v);
		printf("\n");
		for(i=1;i<=G.vexnum;i++)
			if(visited[i]==1)
			{
				BFS(i);
				printf("\n");
			}
}
void firstprime()   //先通过一次prime算法求出最小生成树的权值
{
	int lowcost[max],closevert[max],i,j,k,min;
	for(i=1;i<=n;i++)
	{
		lowcost[i]=G.arcx[1][i];    //v1到各顶点的权值
		closevert[i]=1;				
	}
	closevert[1]=-1;
	for(i=2;i<=n;i++)   //找n-1条边
	{
		min=INFINITY;k=0;    
		for(j=1;j<=n;j++)
			if(closevert[j]!=-1&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
			}
			low+=min;
			if(k)
			{
				closevert[k]=-1;
				for(j=2;j<=n;j++)
					if(closevert[j]!=-1&&G.arcx[k][j]<lowcost[j])
					{
						lowcost[j]=G.arcx[k][j];
						closevert[j]=k;   //存储下一条边
					}
			}
	}
	
}
int prime()    //少一条边的普里姆算法
{
	int lowcost[max],closevert[max],i,j,k,min,sum=0,number=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cost[i][j]=INFINITY;
		for(i=1;i<=m;i++)
			if(elect[i])
				cost[p[i].from][p[i].end ]=cost[p[i].end ][p[i].from ]=p[i].dis ;
			for(i=1;i<=n;i++)
			{
				lowcost[i]=cost[1][i];
				closevert[i]=1;
				back[i]=1;     //存储上一个点
			}
			closevert[1]=-1;
			for(i=2;i<=n;i++)
			{
				min=INFINITY;k=0;
				for(j=1;j<=n;j++)
					if(closevert[j]!=-1 && lowcost[j]<min )	
					{										
						min=lowcost[j];							
						k=j;									
					}
					sum+=min;
					if(min==INFINITY)
						return -1;
					if(k)
					{
						closevert[k]=-1;
						go[number]=back[k];    //储存边的起点
						end[number]=k;			//储存边的终点
						value[number++]=min;	//储存边的权值
						for(j=2;j<=n;j++)
							if(closevert[j]!=-1&&cost[k][j]<lowcost[j])
							{
								lowcost[j]=cost[k][j];
								closevert[j]=k;
								back[j]=k;
							}
					}
			}
			return sum;
}
void printprime(int n)//打印prime算法生成的树
{
	int i,j;
	printf("第 %d 棵最小生成树，权值为%d:\n",cunt++,low);
	for(i=1;i<=n;i++)
	{
		
		for(j=1;j<=i;j++)
			printf("%c-%c:%d  ",go[j]-1+'A',end[j]-1+'A',value[j]);
		printf("\n");
		
	}
}
void choice(int side,int num,int sum)//side表示第几条边，num-1表示已有边数，sum表示权值之和
{
	if(num>n||sum>low)
		return ;
	if(side==m+1)
	{
		if(num==n&&sum==low)
		{
			int c=prime();
			if(c==low)//与第一次普里姆算法生成的权值相比，相等的话就输出
				printprime(n-1);
		}
		return ;
	}
	elect[side]=1;        //选择这条边
	choice(side+1,num+1,sum+p[side].dis);
	elect[side]=0;		//不选择这条边
	choice(side+1,num,sum);
}
int cmp(node x,node y)			//sort函数中的排序函数
{
	if(x.dis!=y.dis)
		return x.dis<y.dis;		//按照权值由小到大排列
	return x.from<y.from;		//当权值相当，按照起点由小到大排列
}
int find_root(int x)			//查找根节点
{
	if(x!=father[x])
		father[x]=find_root(father[x]);
	return father[x];
}
int merge(int x,int y)			//判断是否可以合并
{
	int t1=find_root(x);
	int t2=find_root(y);
	if(t1!=t2)					//如果不在同一个集合中，就可以合并
	{
		father[t2]=t1;
		return 1;
	}
	return 0;
}
void print(int sum)
{
	if(min<sum) 
		return;
	if(sum<min)  
		min=sum;
	printf("第 %d 棵最小生成树，权值为%d:\n",num++,sum);
	for(int i=1;i<=n-1;i++)   //n个顶点，有n-1条边
	{
		for(int j=1;j<=i;j++)
		{
			int k=path[j];
			printf("%c-%c:%d  ",'A'+e[k].from-1,'A'+e[k].end-1,e[k].dis);
		}
		printf("\n");
	}
	return;
}
void kruskal(int cur,int num,int sum)			//第cur条边，生成树中已有num-1条边，生成树的权值现在是sum
{
	if (cur>m+1)
		return ;
	if(num==n)
	{
		print(sum);
		return ;
	}
	int k=cur;
	while(k<=m&&e[k].dis==e[k+1].dis)				//边的权值相等，相等的边中只取一个边
		k++;
	if(k==cur)										 //没有权值相等的边，即这个权值的边只有一条，即这个权值的边只有一条
	{
		if(merge(e[cur].from,e[cur].end))				//不在一个集合里，就加入最小生成树
		{
			path[num]=cur;								//存入路径中
			kruskal(cur+1,num+1,sum+e[cur].dis);	//判断下一条边，生成树中的边的条数加1
		}
		else
			kruskal(cur+1,num,sum);						//在同一集合里，就判断下一条边
		return;
	}
	//如果有相等权值的边有多条，执行下面代码
	int temp[100];
	int i;
	for(i=1;i<=n;i++)								//父亲节点存一遍，记录原值
		temp[i]=father[i];
	if(k!=m)
		k++;
	for(i=cur;i<=k;i++)
	{
		if(merge(e[i].from,e[i].end))
		{
			path[num]=i;
			if(k!=m&&i==k)
				kruskal(i+1,num+1,sum+e[i].dis);
			else
				kruskal(i,num+1,sum+e[i].dis);
			for(int i=1;i<=n;i++)					
				father[i]=temp[i];				//恢复原值
		}
	}
	return ;
}
void kruskalinit()
{
	int i;
	min=INFINITY;
	num=1;
	for(i=1;i<=n;i++)
	{
		father[i]=i;				 //初始化自己的父亲节点为自己
		
	}
	if(n<m)
	{
		for(i=1;i<=m;i++)
		e[i].from=e[i].end=e[i].dis=INFINITY;
	}
	else
	{
		for(i=1;i<=n;i++)
		e[i].from=e[i].end=e[i].dis=INFINITY;
	}
}
int main()
{
	printf("请输入顶点个数和边数\n");
	scanf("%d%d",&n,&m);
	while(n<=0||m>(n*(n-1)/2)||m<n-1)
	{
	printf("输入有误，请重新输入\n");
	scanf("%d%d",&n,&m);
	}
	printf("请选择：\n1.随机生成 2.自己输入\n");
	scanf("%d",&select);
	while(select!=1&&select!=2)
	{
		printf("选择错误，请重新选择\n");
		scanf("%d",&select);
	}
	G.vexnum=n;G.arcnum=m;
	kruskalinit();
	InitMgraph();
	printMgarph();
	foreach();                //深度和广度优先遍历
	printf("(普里姆算法)**********************\n");
	firstprime();
	choice(1,1,0);
	printf("(克鲁斯卡尔算法)******************\n");
	sort(e+1,e+m+1,cmp);
	kruskal(1,1,0);
	return 0;
}
/*
3 3
1 2 1
2 3 2
3 1 3
一条
4 4
1 2 2
2 3 2
3 4 2
4 1 2
四条
6 9
1 2 1
1 4 1
4 3 1
2 3 1
4 5 1
2 6 1
3 5 1
3 6 1
5 6 1
六十六条
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
一条
*/