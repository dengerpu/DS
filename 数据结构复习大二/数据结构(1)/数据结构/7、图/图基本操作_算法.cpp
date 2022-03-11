/* �ڽӾ���ṹ���� */
#define MAX_VERTEX_NUM 20	//��ඥ�����
#define INFINITY 32768	//��ʾ����ֵ���������
/* ͼ�����ࣺDG��ʾ����ͼ��DN��ʾ��������UDG��ʾ����ͼ��UDN��ʾ������ */
typedef enum {DG,DN,UDG,UDN} Graphkind;
typedef char VertexData;	//���趥������Ϊ�ַ���
typedef struct ArcNode
{
	AdjType adj;	//������Ȩͼ����1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����
	OtherInfo info;
}ArcNode;
typedef struct
{
	VertexData vertex[MAX_VERTEX_NUM];	//��������
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//�ڽӾ���
	int vexnum,arcnum;	//ͼ�Ķ������ͻ���
	GraphKind kind;	//ͼ�������־
}AdjMatrix;	//* (Adjacency Matrix Graph)

/* ���㷨7.1�� �����ڽӾ����ʾ����������ͼ */
int LocateVertex(AdjMatrix * G,VertexData v)	//�󶥵�λ�ú���
{
	int j=Error,k;
	for(k=0;k<G->vexnum;k++)
		if(G->vertex[k]==v)
		{ j=k; break; }
	return j;
}
int CreateDN(AdjMatrix * G)	//����һ��������
{
	int i,j,k,weight;
	VertexData v1,v2;
	scanf("%d%d",&G->arcnum,&G->vexnum);	//����ͼ�Ķ������ͻ���
	for(i=0;i<G->vexnum;i++)	//��ʼ���ڽӾ���
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j].adj=INFINITY;
	for(i=0;i<G->vexnum;i++)
		scanf("%c",&G->vertex[i]);	//����ͼ�Ķ���
	for(k=0;k<G->arcnum;k++)
	{
		scanf("%c %c %d",&v1,&v2,&weight);
		i=LocateVex_M(G,v1);
		j=LocateVex_M(G,v2);
		G->arcs[i][j].adj=weight;	//������
	}
	return OK;
}

/* �ڽӱ�洢�ṹ���� */
#define MAX_VERTEX_NUM 20	//��ඥ�����
typedef enum {DG,DN,UDG,UDN} GraphKind;	//ͼ������
typedef struct ArcNode
{
	int adjvex;	//�û�ָ�򶥵��λ��
	struct ArcNode * nextarc;	//ָ����һ������ָ��
	OtherInfo;	//��û���ص���Ϣ
}ArcNode;
typedef struct VertexNode
{
	VertexNode data;	//��������
	ArcNode * firstarc;	//ָ��ö����һ������ָ��
}VertexNode;
typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];
	int vexnum,arcnum;	//ͼ�Ķ������ͻ���
	GraphKind kind;	//ͼ�������־
}AdjList;	//�����ڽӱ��ͼ(Adjacency List Graph)

/* ͼ��ʮ������ṹ���� */
#define MAX_VERTEX_NUM 20	//��ඥ�����
#define enum {DG,DN,UDG,UDN} GraphKind;	//ͼ������
typedef struct ArcNode
{
	int tailvex,headvex;
	struct ArcNode * hlink,* tlink;
}ArcNode;
typedef struct VertexNode
{
	VertexData data;	//������Ϣ
	ArcNode * firstin,* firstout;
}VertexNode;
typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];
	int vexnum,arcnum;	//ͼ�Ķ������ͻ���
	GraphKind kind;	//ͼ������
}OrthList;	//ͼ��ʮ�������ʾ����Orthogonal List��

/* ���㷨7.2�� ����ͼ��ʮ������ */
void CrtOrthList(OrthList * g)
/* ���ն�����n���������Ϣ��e��������Ϣ���Խ���һ������ͼ��ʮ������ */
{
	scanf("%d%d",&n,&e);	//�Ӽ�������ͼ�Ķ�������ͻ��ĸ���
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

/* �ڽӶ��ر�Ľṹ���� */
#define MAX_VERTEX_NUM 20	//��ඥ�����
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
	int vexnum,arcnum;	//ͼ�Ķ������ͻ���
	GraphKind kind;	//ͼ������
}AdjMultiList;	//����ͼ���ڽӶ��ر��ʾ��

/* ���㷨7.3�� ������ȱ���ͼg */
#define True 1
#define False 0
#define Error -1	//����
#define OK 1
int visited[MAX_VERTEX_NUM];	//���ʱ�־����
void TraverseGraph(Graph g)
/* ��ͼg��Ѱ��δ�����ʵĶ�����Ϊ��ʼ�㣬��������������������̽��б�����Graph��ʾͼ��һ�ִ洢�ṹ��
���ڽӾ�����ڽӱ�� */
{
	for(vi=0;vi<g.vexnum;vi++)
		visited[vi]=False;	//���ʱ�־�����ʼ
	for(vi=0;vi<g.vexnum;vi++)
		if(!visited[vi])
			DepthFirstSearch(g,vi);
}	//TraverseGraph
/* ���㷨7.4�� ������ȱ���v0���ڵ���ͨ��ͼ */
void DepthFirstSearch(Graph g,int v0)
/* ��ȱ���v0���ڵ���ͨ��ͼ */
{
	visit(v0); visited[v0]=True;	//���ʶ���v0�����÷��ʱ�־������Ӧ����ֵ
	w=FirstAdjVertex(g,v0);
	while(w!=-1)	//�ڽӵ����
	{
		if(!visited[w])
			DepthFirstSearch(g,w);	//�ݹ����DepthFirstSearch
		w=NextAdjVertex(g,v0,w);	//����һ���ڽӵ�
	}
}	//DepthFirstSearch

/* ���㷨7.5�� �����ڽӾ����DepthFirstSearch */
void DepthFirstSearch(AdjMatrix g,int xo)
/* ͼgΪ�ڽӾ�������AdjMatrix */
{
	visit(v0); visited[v0]=True;
	for(vj=0;vj<g.vexnum;vj++)
		if(!visit[vj] && arcs[v0][vj].adj==1)
			DepthFirstSearch(g,vj);
}	/* DepthFirstSearch */
/* ���㷨7.6��  �����ڽӱ��DepthFirstSearch */
void DepthFirstSearch(AdjList g,int v0)
//ͼgΪ�ڽӱ�����AdjList
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
/* ���㷨7.7��  �ǵݹ���ʽ��DepthFirstSearch */
void DepthFirstSearch(Graph g,int v0)
/* ��v0���������������ͼg */
{
	InitStack(&S);	//��ʼ����ջ
	Push(&S,v0);
	while(!IsEmpty(S))
	{
		Pop(&S,&v);
		if(!visited[v])	//ջ�п������ظ�����
		{
			visit(v);
			visited[v]=True;
			w=FirstAdjVertex(g,v);	//��v�ĵ�һ���ڽӵ�
			while(w!=-1)
			{
				if(!visited[w])
					Push(&S,w);
				w=NextAdjVertex(g,v,w);	//��v�����w����һ���ڽӵ�
			}
		}
	}
}
/* ���㷨7.8�� �����������ͼg��v0���ڵ���ͨ��ͼ */
void BreadthFirstSearch(Graph g,int v0)
/* �����������ͼg��v0���ڵ���ͨ��ͼ */
{
	visit(v0); visited[v0]=True;
	InitQueue(&Q);	//��ʼ���ն�
	EnterQueue(&Q,v0);	//v0����
	while(!IsEmpty(Q))
	{
		DeleteQueue(&Q,&v);	//��ͷԪ�س���
		w=FirstAdjVertex(g,v);	//��v�ĵ�һ���ڽӵ�
		while(w!=-1)
		{
			if(!visited[w])
			{
				visit(w); visited[w]=True;
				EnterQueue(&Q,w);
			}
			w=NextAdjVertex(g,v,w);	//��v�����w����һ���ڽӵ�
		}
	}
}
/* ���㷨7.9��	��������ҳ��Ӷ���u��v�ļ�·�� */
int * pre;
void one_path(Graph * G,int u,int v)
/* ����ͨͼG����һ���ӵ�u�����㵽v������ļ�·�� */
{
	int i;
	pre=(int *)malloc(G->vexnum*sizeof(int));
	for(i=0;i<G->vexnum;i++)
		pre[i]=-1;
	pre[u]=-2;	//��pre[u]��Ϊ-2����ʾ��ʼ����u�ѱ����ʣ�����uû��ǰ��
	DFS_path(G,u,v);	//���������������һ����u��v�ļ�·��
	free(pre);
}
int DFS_path(Graph * G,int u,int v)
/* ����ͨͼG���������������������һ����u��v�ļ�·�� */
{
	int j;
	for(j=firstadj(G,u);j>=0;j=nextadj(G,u,j))
	{
		if(pre[j]==-1)
		{
			pre[j]=u;
			if(j==v)
			{
				print_path(pre,v);	//��v��ʼ������pre[]�б�����ǰ��ָ�����·����ֱ��-2��
				return 1;
			}
			else if(DFS_path(G,j,v))
				return 1;
		}
	}
	return 0;
}
/* ���㷨7.10�� ����ķ�㷨 */
struct
{
	int adjvex;
	int lowcost;
}closedge[MAX_VERTEX_NUM];	//����С������ʱ�ĸ�������
MiniSpanTree_Prim(AdjMatrix gn,int u)
/* �Ӷ���u������������ķ�㷨������ͨ��gn����С���������������������ÿ���� */
{
	closedge[u].lowcost=0;	//��ʼ����U={u}
	for(i=0;i<gn.vexnum;i++)
	{
		if(i!=u)	//��V-U�еĶ���i����ʼ��closedge[i]
		{
			closedge[i].adjvex=u;
			closedge[i].lowcost=gn.arcs[u][i].adj;
		}
	}
	for(e=1;e<=gn.vexnum-1;e++)	//��n-1���ߣ�n=gn.vexnum��
	{
		v=Minium(closedge);	//closedge[v]�д��е�ǰ��С�ߣ�u��v������Ϣ
		u=closedge[v].adjvex;	//u����U
		printf(u,v);	//����������ĵ�ǰ��С�ߣ�u��v��
		closedge[v].lowcost=0;	//������v����U����
		for(i=0;i<vexnum;i++)	//�ڶ���v����U֮�󣬸���closedge[i]
		{
			if(gn.arcs[v][i].adj<closedge[i].lowcost)
			{
				closedge[i].lowcost=gn.arcs[v][i].adj;
				closedge[i].adjvex=v;
			}
		}
	}
}
/* ���㷨7.11�� ���������㷨 */
int TopoSort(AdjList G)
{
	Stack S;
	int indegree[MAX_VERTEX_NUM];
	int i,count,k;
	ArcNode * p;
	FindID(G,indegree);	//����������
	InitStack(&S);	//��ʼ������ջ
	for(i=0;i<G.vexnum;i++)
		if(indegree[i]==0)
			Push(&S);	//�����Ϊ0�Ķ�����ջ
	count=0;
	while(!IsEmpty(S))
	{
		Pop(&S,&i);
		printf("%c",G.vertex[i].data);
		count++;	//���i�Ŷ��㲢����
		p=G.vertex[i].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex;
			indegree[k]--;	//i�Ŷ����ÿ���ڽӵ����ȼ�1
			if(indegree[k]==0)
				Push(&S,k);	//����ȼ�Ϊ0������ջ
			p=p->nextarc;
		}
	}	//while
	if(count<G.vexnum)
		return (Error);	//������ͼ���л�·
	else
		return (OK);
}
/* ���㷨7.12�� ������㷨 */
void FindID(AdjList G,int indegree[MAX_VERTEX_NUM])
/* ����������� */
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
/* ���㷨7.13�� �޸ĺ�����������㷨 */
int ve[MAX_VERTEX_NUM];	//ÿ����������緢��ʱ��
int TopoOrder(AdjList G,Stack * T)
/* GΪ����ͼ��TΪ�������������е�ջ���������ve���飨ȫ���������� */
{
	int count,i,j,k; ArcNode * p;
	int indegree[MAX_VERTEX_NUM];	//�������������
	Stack S;	//SΪ������Ϊ0�Ķ����ջ
	InitStack(T); InitStack(&S);	//��ʼ��ջT��S
	FindID(G,indegree);	//�������������
	for(i=0;i<G.vexnum;i++)
		if(indegree[i]==0)
			Push(&S,i);
	count=0;
	for(i=0;i<G.vexnum;i++)
		ve[i]=0;	//��ʼ�����緢��ʱ��
	while(!IsEmpty(&S))
	{
		Pop(&S,&j);
		Push(T,j);	//�����������ջ
		count++;
		p=G.vertex[j].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex;
			if(--indegree[k]==0)
				Push(&S,k);	//��������ȼ�Ϊ0����ջ
			if(ve[j]+p->Info.weight>ve[k])
				ve[k]=ve[j]+p->Info.weight;
			//������˳������¼����緢��ʱ��
			p=p->nextarc;
		}	//while
	}	//while
	if(count<G.vexnum)
		return (Error);
	else
		return (OK);
}	//TopoOrder
/* ���㷨7.14�� �ؼ�·���㷨 */
int CriticalPath(AdjList G)
{
	ArcNode * p;
	int i,j,k,dut,ei,li; char tag;
	int vl[MAX_VERTEX_NUM];	//ÿ���������ٷ���ʱ��
	Stack T;
	if(!TopoOrder(G,&T))	//(1): ���¼����緢��ʱ�������������ջT
		return (Error);
	for(i=0;i<G.vexnum;i++)
		vl[i]=ve[G.vexnum-1];	//���������¼�����ٷ���ʱ���ʼ��Ϊ�������緢��ʱ��
	while(!IsEmpty(&T))	//(2): ��������������������vlֵ
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
	for(j=0;j<G.vexnum;j++)	//(3): ��ei,li�͹ؼ��
	{
		p=G.vertex[j].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex; dut=p->Info.weight;
			ei=ve[j]; li=vl[k]-dut;
			tag=(ei==li) ? '*': ' ' ;	//(4): ��ǲ�����ؼ��
			printf("%c,%c,%d,%d,%d,%c\n",G.vertex[j].data,G.vertex[k].data,dut,ei,li,tag);
			p=p->nextarc;
		}	//while
	}	//for
	return (OK);
}	//CriticalPath
/* ���㷨7.15�� ͼ�����·���㷨 */
#define INFINITY 32768	//��ʾ����ֵ���������
typedef unsigned int WeightType;
typedef WeightType AdjType;
typedef SeqList VertexSet;
ShortestPath_DJS(AdjMatrix g,int v0,WeightType dist[MAX_VERTEX_NUM],VertexSet path[MAX_VERTEX_NUM])
/* path[i]�д�Ŷ���i�ĵ�ǰ���·����dist[i]�д�Ŷ���i�ĵ�ǰ���·������ */
{
	VertexSet s;	//sΪ���ҵ����·�����յ㼯��
	for(i=0;i<g.vexnum;i++)	//��ʼ��dist[i]��path[i]
	{
		InitList(&path[i]);
		dist[i]=g.arcs[v0][i].adj;
		if(dist[i]<INFINITY)
		{
			AddTail(&path[i],g.vertex[v0]);	//AddTail�Ǳ�β��Ӳ���
			AddTail(&path[i],g.vertex[i]);
		}
	}
	InitList(&s);
	AddTail(&s,g.vertex[v0]);	//��v0���ɵ�һ�����ҵ����·�����յ�
	for(t=1;t<g.vernum-1;t++)	//��v0������n-1����������·����n=g.vexnum��
	{
		min=INFINITY;
		for(i=0;i<g.vexnum;i++)
			if(!Member(g.vertex[i],s) && dist[i]<min)
			{ k=i; min=dist[i]; }
		if(min==INFINITY)
			return ;
		AddTail(&s,g.vertex[k]);
		for(i=0;i<g.vernum;i++)	//����dist[i],i����V-S
			if(Member(g.vertex[i],s) && g.arcs[k][i].adj!=INFINITY && (dist[k]+g.arccs[k][i].adj<dist[i]))
			{
				dist[i]=dist[k]+g.arcs[k][i].adj;
				path[i]=path[k];
				AddTail(&path[i],g.vertex[i]);	//path[i]=path[k]��{vi}�Ľ���
			}
	}
}
/* ���㷨7.16�� ���������㷨 */
typedef SeqList VertexSet;
ShortestPath_Floyd(AdjMatrix g,WeightType dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM],VertexSet path[MAX_VERTEX_NUM][MAX_VERTEX_NUM])
/* gΪ��Ȩ����ͼ���ڽӾ����ʾ����path[i][j]Ϊvi��vj�ĵ�ǰ���·����dist[i][j]Ϊvi��vj�ĵ�ǰ���·������ */
{
	for(i=0;i<g.vernum;i++)	//��ʼ��dist[i][j]��path[i][j];
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
				}	//JoinList�Ǻϲ����Ա����
}
/* ���㷨7.17�� ����붥��v0�����·������Ϊk�����ж��� */
void bfsKlevel(Graph g,int v0,int K)
{
	InitQueue(Q1);	//Q1�Ǵ���ѷ��ʵĶ���Ķ���
	initQueue(Q2);	//Q2�Ǵ���ѷ��ʶ����ŵĶ���
	for(i=0;i<g.vexnum;i++)
		visited[i]=FALSE;	//��ʼ�����ʱ�־����
	visited[v0]=TRUE; Level=1;
	EnterQueue(Q1,v0);
	EnterQueue(Q2,Level);
	while(!IsEmpty(Q1)&&Level<K+1)
	{
		v=DeleteQueue(Q1);	//ȡ���ѷ��ʵĶ����
		Level=DeleteQueue(Q2);	//ȡ���ѷ��ʶ���Ĳ��
		w=FirstAdjVertex(g,v);	//�ҵ�һ���ڽӵ�
		while(w!=-1)
		{
			if(!visited[w])
			{
				visited[w]=TRUE;
				/* v��LevelΪK����ʾw��LevelΪK+1������Ҫ��������ý����������� */
				if(Level==K)
					printf("%d",w);
				else	//w��Level������Ҫ�󣬽�����
				{
					EnterQueue(Q1,w);
					EnterQueue(Q2,Level+1);
				}
				w=NextAdjVertex(g,v,w);	//����һ���ڽӵ�
			}
		}
	}
}
/**************************************************����**************************************************/
/* ���㷨7.18�� ����㷨��ͼg���ҳ�һ���������ж���ļ�·�� */
int visited[MAX_VERTEX_NUM];
int path[MAX_VERTEX_NUM];	//��¼·���ϵĶ�������
int n=0;	//��¼·���ϵĶ�����
int DepthFirstSearch(Graph g,int v0)
/* �õݹ�����������������ͼg��Ѱ��һ���������ж���ļ�·�����ӵ�ǰ���v0�ɹ��ҵ�ʱ����1�����򷵻�0 */
{
	visited[v0]=TRUE;	//���÷��ʱ�־
	n=n+1;	//�ݹ����ʱ��·���϶�������1
	path[n]=v0;	//����·���ϵĶ���
	if(n==g.vexnum)
	{
		Display(path);	//�ҵ�һ���������ж���ļ�·��
		return 1;	//�ɹ�����
	}
	w=FirstAdjVertex(g,v0);	//�ҵ�һ���ڽӵ�
	while(w!=-1)
	{
		if(!visited[w] && DepthFirstSearch(g,w)==1)
			return 1;	//���ڽӵ�w�����������ҳɹ�����
		w=NextAdjVertex(g,v0,w);	//����һ���ڽӵ�
	}
	visited[v0]=FALSE;	//�ݹ��˲�ʱ��ȡ�����ʱ�־���Ա����±����ö���
	n=n-1;	//�ݹ��˲�ʱ��·���϶�������1
	return 0;
}
void Hamilton(Graph g)
{
	for(i=0;i<g.vexnum;i++)
		visited[i]=FALSE;	//��ʼ�����ʱ�־����
	n=0;
	for(i=0;i<g.vexnum;i++)
		if(DepthFirstSearch(g,i)==1)
			return ;	//һ���ҵ�һ����·���򷵻�
}
/* ���㷨7.19�� ��ͼ�����Ķ��� */
#define MAXLEN 3E38	//������󸡵���
#define MAX 20	//������󶥵���Ŀ
int CenterVex(AdjMatrix G)
{	//�ڴ�ȨͼG����һ�����Ķ��㣬���ظö�����
	int i,j,k;
	float min,len;
	float A[MAX][MAX];	//A[i][j]���i��j֮������·������
	for(i=0;i<G.vexnum;i++)	//��ʼ��A[i][j]
	{
		for(j=0;j<G.vexnum;j++)
			A[i][j]=G.arcs[i][j].adj;
		A[i][j]=0;	//i��j��·������Ϊ0
	}
	for(k=0;k<G.vexnum;k++)
		for(i=0;i<G.vexnum;i++)
			for(j=0;j<G.vexnum;j++)
				if(A[i][k]+A[k][j]<A[i][j])
					A[i][j]=A[i][k]+A[k][j];
	min=MAXLEN; k=0;
	for(i=0;i<G.vexnum;i++)	//ѡ�����·������֮����С�Ķ���vk
	{
		len=0;
		for(j=0;j<G.vexnum;j++)	//��vi�����ඥ�����·������֮��
			len=len+A[i][j];
		if(len<min)
		{
			k=i;
			min=len;
		}
	}
	return k;
}