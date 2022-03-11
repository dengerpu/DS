/* 邻接矩阵结构定义 */
#define MAX_VERTEX_NUM 20	//最多顶点个数
#define INFINITY 32768	//表示极大值，即无穷大
/* 图的种类：DG表示有向图，DN表示有向网，UDG表示无向图，UDN表示无向网 */
typedef enum {DG,DN,UDG,UDN} Graphkind;
typedef char VertexData;	//假设顶点数据为字符型
typedef struct ArcNode
{
	AdjType adj;	//对于无权图，用1或0表示是否相邻；对带权图，则为权值类型
	OtherInfo info;
}ArcNode;
typedef struct
{
	VertexData vertex[MAX_VERTEX_NUM];	//顶点向量
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//邻接矩阵
	int vexnum,arcnum;	//图的顶点数和弧数
	GraphKind kind;	//图的种类标志
}AdjMatrix;	//* (Adjacency Matrix Graph)

/* 【算法7.1】 采用邻接矩阵表示法创建有向图 */
int LocateVertex(AdjMatrix * G,VertexData v)	//求顶点位置函数
{
	int j=Error,k;
	for(k=0;k<G->vexnum;k++)
		if(G->vertex[k]==v)
		{ j=k; break; }
	return j;
}
int CreateDN(AdjMatrix * G)	//创建一个有向网
{
	int i,j,k,weight;
	VertexData v1,v2;
	scanf("%d%d",&G->arcnum,&G->vexnum);	//输入图的顶点数和弧数
	for(i=0;i<G->vexnum;i++)	//初始化邻接矩阵
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j].adj=INFINITY;
	for(i=0;i<G->vexnum;i++)
		scanf("%c",&G->vertex[i]);	//输入图的顶点
	for(k=0;k<G->arcnum;k++)
	{
		scanf("%c %c %d",&v1,&v2,&weight);
		i=LocateVex_M(G,v1);
		j=LocateVex_M(G,v2);
		G->arcs[i][j].adj=weight;	//建立弧
	}
	return OK;
}

/* 邻接表存储结构定义 */
#define MAX_VERTEX_NUM 20	//最多顶点个数
typedef enum {DG,DN,UDG,UDN} GraphKind;	//图的种类
typedef struct ArcNode
{
	int adjvex;	//该弧指向顶点的位置
	struct ArcNode * nextarc;	//指向下一条弧的指针
	OtherInfo;	//与该弧相关的信息
}ArcNode;
typedef struct VertexNode
{
	VertexNode data;	//顶点数据
	ArcNode * firstarc;	//指向该顶点第一条弧的指针
}VertexNode;
typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];
	int vexnum,arcnum;	//图的顶点数和弧数
	GraphKind kind;	//图的种类标志
}AdjList;	//基于邻接表的图(Adjacency List Graph)

/* 图的十字链表结构定义 */
#define MAX_VERTEX_NUM 20	//最多顶点个数
#define enum {DG,DN,UDG,UDN} GraphKind;	//图的种类
typedef struct ArcNode
{
	int tailvex,headvex;
	struct ArcNode * hlink,* tlink;
}ArcNode;
typedef struct VertexNode
{
	VertexData data;	//顶点信息
	ArcNode * firstin,* firstout;
}VertexNode;
typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];
	int vexnum,arcnum;	//图的顶点数和弧数
	GraphKind kind;	//图的种类
}OrthList;	//图的十字链表表示法（Orthogonal List）

/* 【算法7.2】 创建图的十字链表 */
void CrtOrthList(OrthList * g)
/* 从终端输入n个顶点的信息和e条弧的信息，以建立一个有向图的十字链表 */
{
	scanf("%d%d",&n,&e);	//从键盘输入图的顶点个数和弧的个数
	g->vernum=n;
	g->arcnum=e;
	for(i=0;i<n;i++)
	{
		scanf("%c",&(g->vertex[i].data));
		g->vertex[i].firstin=NULL;
		g->vertex[i].firstout=NULL;
	}
	for(k=0;k<e;k++)
	{
		scanf("%c %c".&vt,&vh);
		i=LocateVertex(g,vt);
		j=LocateVertex(g,vh);
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->tailvex=i; p->headvex=j;
		p->tlink=g->vertex[i].firstout;
		g->vertex[i].firstout=p;
		p->hlink=g->vertex[j].firstin;
		g->vertex[j].firstin=p;
	}
}	//CrtOrthList

/* 邻接多重表的结构类型 */
#define MAX_VERTEX_NUM 20	//最多顶点个数
typedef struct EdgeNode
{
	int mark,ivex,jvex;
	struct EdgeNode * ilink,* jlink;
}EdgeNode;
typedef struct
{
	VertexData data;
	EdgeNode * firstedge;
}VertexNode;
typedef struct
{
	VertexNode vertex[MAX)_VERTEX_NUM];
	int vexnum,arcnum;	//图的顶点数和弧数
	GraphKind kind;	//图的种类
}AdjMultiList;	//基于图的邻接多重表表示法

/* 【算法7.3】 深度优先遍历图g */
#define True 1
#define False 0
#define Error -1	//出错
#define OK 1
int visited[MAX_VERTEX_NUM];	//访问标志数组
void TraverseGraph(Graph g)
/* 在图g中寻找未被访问的顶点作为起始点，并调用深度优先搜索过程进行遍历。Graph表示图的一种存储结构，
如邻接矩阵或邻接表等 */
{
	for(vi=0;vi<g.vexnum;vi++)
		visited[vi]=False;	//访问标志数组初始
	for(vi=0;vi<g.vexnum;vi++)
		if(!visited[vi])
			DepthFirstSearch(g,vi);
}	//TraverseGraph
/* 【算法7.4】 深度优先遍历v0所在的连通子图 */
void DepthFirstSearch(Graph g,int v0)
/* 深度遍历v0所在的连通子图 */
{
	visit(v0); visited[v0]=True;	//访问顶点v0，并置访问标志数组相应分量值
	w=FirstAdjVertex(g,v0);
	while(w!=-1)	//邻接点存在
	{
		if(!visited[w])
			DepthFirstSearch(g,w);	//递归调用DepthFirstSearch
		w=NextAdjVertex(g,v0,w);	//找下一个邻接点
	}
}	//DepthFirstSearch

/* 【算法7.5】 采用邻接矩阵的DepthFirstSearch */
void DepthFirstSearch(AdjMatrix g,int xo)
/* 图g为邻接矩阵类型AdjMatrix */
{
	visit(v0); visited[v0]=True;
	for(vj=0;vj<g.vexnum;vj++)
		if(!visit[vj] && arcs[v0][vj].adj==1)
			DepthFirstSearch(g,vj);
}	/* DepthFirstSearch */
/* 【算法7.6】  采用邻接表的DepthFirstSearch */
void DepthFirstSearch(AdjList g,int v0)
//图g为邻接表类型AdjList
{
	visit(v0); visited[v0]=True;
	p=g.vertex[v0].firstarc;
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DepthFirstSearch(g,p->adjvex);
		p=p->nextarc;
	}
}	//DepthFirstSearch
/* 【算法7.7】  非递归形式的DepthFirstSearch */
void DepthFirstSearch(Graph g,int v0)
/* 从v0出发深度优先搜索图g */
{
	InitStack(&S);	//初始化空栈
	Push(&S,v0);
	while(!IsEmpty(S))
	{
		Pop(&S,&v);
		if(!visited[v])	//栈中可能有重复顶点
		{
			visit(v);
			visited[v]=True;
			w=FirstAdjVertex(g,v);	//求v的第一个邻接点
			while(w!=-1)
			{
				if(!visited[w])
					Push(&S,w);
				w=NextAdjVertex(g,v,w);	//求v相对于w的下一个邻接点
			}
		}
	}
}
/* 【算法7.8】 广度优先搜索图g中v0所在的连通子图 */
void BreadthFirstSearch(Graph g,int v0)
/* 广度优先搜索图g中v0所在的连通子图 */
{
	visit(v0); visited[v0]=True;
	InitQueue(&Q);	//初始化空队
	EnterQueue(&Q,v0);	//v0进队
	while(!IsEmpty(Q))
	{
		DeleteQueue(&Q,&v);	//队头元素出队
		w=FirstAdjVertex(g,v);	//求v的第一个邻接点
		while(w!=-1)
		{
			if(!visited[w])
			{
				visit(w); visited[w]=True;
				EnterQueue(&Q,w);
			}
			w=NextAdjVertex(g,v,w);	//求v相对于w的下一个邻接点
		}
	}
}
/* 【算法7.9】	深度优先找出从顶点u到v的简单路径 */
int * pre;
void one_path(Graph * G,int u,int v)
/* 在连通图G中找一条从第u个顶点到v个顶点的简单路径 */
{
	int i;
	pre=(int *)malloc(G->vexnum*sizeof(int));
	for(i=0;i<G->vexnum;i++)
		pre[i]=-1;
	pre[u]=-2;	//将pre[u]置为-2，表示初始顶点u已被访问，并且u没有前驱
	DFS_path(G,u,v);	//用深度优先搜索找一条从u到v的简单路径
	free(pre);
}
int DFS_path(Graph * G,int u,int v)
/* 在连通图G中用深度优先搜索策略找一条从u到v的简单路径 */
{
	int j;
	for(j=firstadj(G,u);j>=0;j=nextadj(G,u,j))
	{
		if(pre[j]==-1)
		{
			pre[j]=u;
			if(j==v)
			{
				print_path(pre,v);	//从v开始，沿着pre[]中保留的前驱指针输出路径（直到-2）
				return 1;
			}
			else if(DFS_path(G,j,v))
				return 1;
		}
	}
	return 0;
}
/* 【算法7.10】 普里姆算法 */
struct
{
	int adjvex;
	int lowcost;
}closedge[MAX_VERTEX_NUM];	//求最小生成树时的辅助数组
MiniSpanTree_Prim(AdjMatrix gn,int u)
/* 从顶点u出发，按普里姆算法构造连通网gn的最小生成树，并输出生成树的每条边 */
{
	closedge[u].lowcost=0;	//初始化，U={u}
	for(i=0;i<gn.vexnum;i++)
	{
		if(i!=u)	//对V-U中的顶点i，初始化closedge[i]
		{
			closedge[i].adjvex=u;
			closedge[i].lowcost=gn.arcs[u][i].adj;
		}
	}
	for(e=1;e<=gn.vexnum-1;e++)	//找n-1条边（n=gn.vexnum）
	{
		v=Minium(closedge);	//closedge[v]中存有当前最小边（u，v）的信息
		u=closedge[v].adjvex;	//u属于U
		printf(u,v);	//输出生成树的当前最小边（u，v）
		closedge[v].lowcost=0;	//将顶点v纳入U集合
		for(i=0;i<vexnum;i++)	//在顶点v并入U之后，更新closedge[i]
		{
			if(gn.arcs[v][i].adj<closedge[i].lowcost)
			{
				closedge[i].lowcost=gn.arcs[v][i].adj;
				closedge[i].adjvex=v;
			}
		}
	}
}
/* 【算法7.11】 拓扑排序算法 */
int TopoSort(AdjList G)
{
	Stack S;
	int indegree[MAX_VERTEX_NUM];
	int i,count,k;
	ArcNode * p;
	FindID(G,indegree);	//求各顶点入度
	InitStack(&S);	//初始化辅助栈
	for(i=0;i<G.vexnum;i++)
		if(indegree[i]==0)
			Push(&S);	//将入度为0的顶点入栈
	count=0;
	while(!IsEmpty(S))
	{
		Pop(&S,&i);
		printf("%c",G.vertex[i].data);
		count++;	//输出i号顶点并计数
		p=G.vertex[i].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex;
			indegree[k]--;	//i号顶点的每个邻接点的入度减1
			if(indegree[k]==0)
				Push(&S,k);	//若入度减为0，则入栈
			p=p->nextarc;
		}
	}	//while
	if(count<G.vexnum)
		return (Error);	//该有向图含有回路
	else
		return (OK);
}
/* 【算法7.12】 求入度算法 */
void FindID(AdjList G,int indegree[MAX_VERTEX_NUM])
/* 求各顶点的入度 */
{
	int i; ArcNode * p;
	for(i=0;i<G.vexnum;i++)
		indegree[i]=0;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertex[i].firstarc;
		while(p!=NULL)
		{
			indegree[p->adjvex]++;
			p=p->nextarc;
		}
	}	//for
}	//FindID
/* 【算法7.13】 修改后的拓扑排序算法 */
int ve[MAX_VERTEX_NUM];	//每个顶点的最早发生时间
int TopoOrder(AdjList G,Stack * T)
/* G为有向图，T为返回逆拓扑序列的栈，并计算出ve数组（全程量带出） */
{
	int count,i,j,k; ArcNode * p;
	int indegree[MAX_VERTEX_NUM];	//各顶点入度数组
	Stack S;	//S为存放入度为0的顶点的栈
	InitStack(T); InitStack(&S);	//初始化栈T，S
	FindID(G,indegree);	//求各个顶点的入度
	for(i=0;i<G.vexnum;i++)
		if(indegree[i]==0)
			Push(&S,i);
	count=0;
	for(i=0;i<G.vexnum;i++)
		ve[i]=0;	//初始化最早发生时间
	while(!IsEmpty(&S))
	{
		Pop(&S,&j);
		Push(T,j);	//按拓扑排序进栈
		count++;
		p=G.vertex[j].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex;
			if(--indegree[k]==0)
				Push(&S,k);	//若顶点入度减为0则入栈
			if(ve[j]+p->Info.weight>ve[k])
				ve[k]=ve[j]+p->Info.weight;
			//按拓扑顺序计算事件最早发生时间
			p=p->nextarc;
		}	//while
	}	//while
	if(count<G.vexnum)
		return (Error);
	else
		return (OK);
}	//TopoOrder
/* 【算法7.14】 关键路径算法 */
int CriticalPath(AdjList G)
{
	ArcNode * p;
	int i,j,k,dut,ei,li; char tag;
	int vl[MAX_VERTEX_NUM];	//每个顶点的最迟发生时间
	Stack T;
	if(!TopoOrder(G,&T))	//(1): 求事件最早发生时间和逆拓扑排序栈T
		return (Error);
	for(i=0;i<G.vexnum;i++)
		vl[i]=ve[G.vexnum-1];	//将各顶点事件的最迟发生时间初始化为汇点的最早发生时间
	while(!IsEmpty(&T))	//(2): 按逆拓扑排序求各顶点的vl值
	{
		Pop(&T,&j);
		p=G.vertex[j].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex; dut=p->weight;
			if(vl[k]-dut<vl[j])
				vl[j]=vl[k]-dut;
			p=p->nextarc;
		}	//while
	}	//while
	for(j=0;j<G.vexnum;j++)	//(3): 求ei,li和关键活动
	{
		p=G.vertex[j].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex; dut=p->Info.weight;
			ei=ve[j]; li=vl[k]-dut;
			tag=(ei==li) ? '*': ' ' ;	//(4): 标记并输出关键活动
			printf("%c,%c,%d,%d,%d,%c\n",G.vertex[j].data,G.vertex[k].data,dut,ei,li,tag);
			p=p->nextarc;
		}	//while
	}	//for
	return (OK);
}	//CriticalPath
/* 【算法7.15】 图的最短路径算法 */
#define INFINITY 32768	//表示极大值，即无穷大
typedef unsigned int WeightType;
typedef WeightType AdjType;
typedef SeqList VertexSet;
ShortestPath_DJS(AdjMatrix g,int v0,WeightType dist[MAX_VERTEX_NUM],VertexSet path[MAX_VERTEX_NUM])
/* path[i]中存放顶点i的当前最短路径。dist[i]中存放顶点i的当前最短路径长度 */
{
	VertexSet s;	//s为已找到最短路径的终点集合
	for(i=0;i<g.vexnum;i++)	//初始化dist[i]和path[i]
	{
		InitList(&path[i]);
		dist[i]=g.arcs[v0][i].adj;
		if(dist[i]<INFINITY)
		{
			AddTail(&path[i],g.vertex[v0]);	//AddTail是表尾添加操作
			AddTail(&path[i],g.vertex[i]);
		}
	}
	InitList(&s);
	AddTail(&s,g.vertex[v0]);	//将v0看成第一个已找到最短路径的终点
	for(t=1;t<g.vernum-1;t++)	//求v0到其余n-1个顶点的最短路径（n=g.vexnum）
	{
		min=INFINITY;
		for(i=0;i<g.vexnum;i++)
			if(!Member(g.vertex[i],s) && dist[i]<min)
			{ k=i; min=dist[i]; }
		if(min==INFINITY)
			return ;
		AddTail(&s,g.vertex[k]);
		for(i=0;i<g.vernum;i++)	//修正dist[i],i属于V-S
			if(Member(g.vertex[i],s) && g.arcs[k][i].adj!=INFINITY && (dist[k]+g.arccs[k][i].adj<dist[i]))
			{
				dist[i]=dist[k]+g.arcs[k][i].adj;
				path[i]=path[k];
				AddTail(&path[i],g.vertex[i]);	//path[i]=path[k]与{vi}的交集
			}
	}
}
/* 【算法7.16】 弗洛伊德算法 */
typedef SeqList VertexSet;
ShortestPath_Floyd(AdjMatrix g,WeightType dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM],VertexSet path[MAX_VERTEX_NUM][MAX_VERTEX_NUM])
/* g为带权有向图的邻接矩阵表示法，path[i][j]为vi到vj的当前最短路径，dist[i][j]为vi到vj的当前最短路径长度 */
{
	for(i=0;i<g.vernum;i++)	//初始化dist[i][j]和path[i][j];
		for(j=0;j<g.vernum;j++)
		{
			InitList(&path[i][j]);
			dist[i][j]=g.arcs[i][j].adj;
			if(dist[i][j]<INFINITY)
			{
				AddTail(&path[i][j],g.vertex[i]);
				AddTail(&path[i][j],g.vertex[i]);
			}
		}
	for(k=0;k<g.vexnum;k++)
		for(i=0;i<g.vexnum;i++)
			for(j=0;j<g.vexnum;j++)
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=JoinList(path[i][k],path[k][j]);
				}	//JoinList是合并线性表操作
}
/* 【算法7.17】 求距离顶点v0的最短路径长度为k的所有顶点 */
void bfsKlevel(Graph g,int v0,int K)
{
	InitQueue(Q1);	//Q1是存放已访问的顶点的队列
	initQueue(Q2);	//Q2是存放已访问顶点层号的队列
	for(i=0;i<g.vexnum;i++)
		visited[i]=FALSE;	//初始化访问标志数组
	visited[v0]=TRUE; Level=1;
	EnterQueue(Q1,v0);
	EnterQueue(Q2,Level);
	while(!IsEmpty(Q1)&&Level<K+1)
	{
		v=DeleteQueue(Q1);	//取出已访问的顶点号
		Level=DeleteQueue(Q2);	//取出已访问顶点的层号
		w=FirstAdjVertex(g,v);	//找第一个邻接点
		while(w!=-1)
		{
			if(!visited[w])
			{
				visited[w]=TRUE;
				/* v的Level为K，表示w的Level为K+1，符合要求，输出。该结点无须进队列 */
				if(Level==K)
					printf("%d",w);
				else	//w的Level不符合要求，进队列
				{
					EnterQueue(Q1,w);
					EnterQueue(Q2,Level+1);
				}
				w=NextAdjVertex(g,v,w);	//找下一个邻接点
			}
		}
	}
}
/**************************************************不会**************************************************/
/* 【算法7.18】 设计算法在图g中找出一条包含所有顶点的简单路径 */
int visited[MAX_VERTEX_NUM];
int path[MAX_VERTEX_NUM];	//记录路径上的顶点序列
int n=0;	//记录路径上的顶点数
int DepthFirstSearch(Graph g,int v0)
/* 用递归的深度优先搜索法在图g中寻找一条包含所有顶点的简单路径。从当前结点v0成功找到时返回1，否则返回0 */
{
	visited[v0]=TRUE;	//设置访问标志
	n=n+1;	//递归进层时，路径上顶点数加1
	path[n]=v0;	//保存路径上的顶点
	if(n==g.vexnum)
	{
		Display(path);	//找到一条包含所有顶点的简单路径
		return 1;	//成功返回
	}
	w=FirstAdjVertex(g,v0);	//找第一个邻接点
	while(w!=-1)
	{
		if(!visited[w] && DepthFirstSearch(g,w)==1)
			return 1;	//从邻接点w往下搜索，且成功返回
		w=NextAdjVertex(g,v0,w);	//找下一个邻接点
	}
	visited[v0]=FALSE;	//递归退层时，取消访问标志，以便重新遍历该顶点
	n=n-1;	//递归退层时，路径上顶点数减1
	return 0;
}
void Hamilton(Graph g)
{
	for(i=0;i<g.vexnum;i++)
		visited[i]=FALSE;	//初始化访问标志数组
	n=0;
	for(i=0;i<g.vexnum;i++)
		if(DepthFirstSearch(g,i)==1)
			return ;	//一旦找到一条简单路径则返回
}
/* 【算法7.19】 求图的中心顶点 */
#define MAXLEN 3E38	//定义最大浮点数
#define MAX 20	//定义最大顶点数目
int CenterVex(AdjMatrix G)
{	//在带权图G中求一个中心顶点，返回该顶点编号
	int i,j,k;
	float min,len;
	float A[MAX][MAX];	//A[i][j]存放i和j之间的最短路径长度
	for(i=0;i<G.vexnum;i++)	//初始化A[i][j]
	{
		for(j=0;j<G.vexnum;j++)
			A[i][j]=G.arcs[i][j].adj;
		A[i][j]=0;	//i到j的路径长度为0
	}
	for(k=0;k<G.vexnum;k++)
		for(i=0;i<G.vexnum;i++)
			for(j=0;j<G.vexnum;j++)
				if(A[i][k]+A[k][j]<A[i][j])
					A[i][j]=A[i][k]+A[k][j];
	min=MAXLEN; k=0;
	for(i=0;i<G.vexnum;i++)	//选择最短路径长度之和最小的顶点vk
	{
		len=0;
		for(j=0;j<G.vexnum;j++)	//求vi到其余顶点最短路径长度之和
			len=len+A[i][j];
		if(len<min)
		{
			k=i;
			min=len;
		}
	}
	return k;
}