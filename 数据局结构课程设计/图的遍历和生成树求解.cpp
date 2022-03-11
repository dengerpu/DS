#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
#define max 1000			//��ඥ�����
#define INFINITY 32768		//��ʾ����ֵ
int visited[max],select;
int father[max],min,num;	//������Ÿ��׽ڵ�
int path[max];				//��������ѡ�ߵ�˳��
int n,m,low=0,cunt=1;		//����������m������
int elect[max],back[max],go[max],end[max],value[max],cost[max][max];
typedef struct
{
	char vertex[max];		//������Ŷ�������
	int arcx[max][max];		//�ڽӾ���������Ŷ���֮��Ĺ�ϵ
	int vexnum,arcnum;		//������Ŷ������ͻ���
}Mgraph;
Mgraph G;
typedef struct node
{
	int from;    
	int end;
	int dis;   //��¼Ȩֵ
}edged[100];
edged e;
edged p;
void InitMgraph()
{
	int i,j,x,y,z;
	srand(time(NULL));
	for(i=1;i<=G.vexnum;i++)
		father[i]=i;      //��ʼ����ÿ������ĸ��׽ڵ����Լ�����
	for(i=1;i<=G.vexnum;i++)
		G.vertex[i]=i+64;
	for(i=1;i<=G.vexnum;i++)
		for(j=1;j<=G.vexnum;j++)
			G.arcx[i][j]=INFINITY;
		if(select==1)
		{
			printf("(�������ʽ)**********************\n");
			for(i=1;i<=G.arcnum;i++)
			{
				x=rand()%G.vexnum+1;
				y=rand()%G.vexnum+1;
				while(x==y||(G.arcx[x][y]<INFINITY&&G.arcx[y][x]<INFINITY))
				{
					x=rand()%G.vexnum+1;
					y=rand()%G.vexnum+1;
				}
				z=rand()%30+1;  //Ȩֵ��Χ��1,30;
				p[i].from=x;e[i].from=x;
				p[i].end=y;e[i].end=y;
				p[i].dis=z;e[i].dis=z;
				G.arcx[x][y]=G.arcx[y][x]=z;
				printf("%d %d %d\n",x,y,z);
			}
		}
		if(select==2)
		{
			printf("(�������ʽ)**********************\n");
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
	
	printf("(������ʽ)**********************\n");
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
void DFS(int v)    //���������������
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
void BFS(int v)   //���������������
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
	visited[max]=0;   //��������Ƿ񱻷��ʹ�
	printf("(�����������)********************\n");
	DFS(v);
	printf("\n");
	for(i=1;i<=G.vexnum;i++)
		if(visited[i]==0)  
		{
			DFS(i);
			printf("\n");
		}
		printf("(�����������)********************\n");
		BFS(v);
		printf("\n");
		for(i=1;i<=G.vexnum;i++)
			if(visited[i]==1)
			{
				BFS(i);
				printf("\n");
			}
}
void firstprime()   //��ͨ��һ��prime�㷨�����С��������Ȩֵ
{
	int lowcost[max],closevert[max],i,j,k,min;
	for(i=1;i<=n;i++)
	{
		lowcost[i]=G.arcx[1][i];    //v1���������Ȩֵ
		closevert[i]=1;				
	}
	closevert[1]=-1;
	for(i=2;i<=n;i++)   //��n-1����
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
						closevert[j]=k;   //�洢��һ����
					}
			}
	}
	
}
int prime()    //��һ���ߵ�����ķ�㷨
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
				back[i]=1;     //�洢��һ����
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
						go[number]=back[k];    //����ߵ����
						end[number]=k;			//����ߵ��յ�
						value[number++]=min;	//����ߵ�Ȩֵ
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
void printprime(int n)//��ӡprime�㷨���ɵ���
{
	int i,j;
	printf("�� %d ����С��������ȨֵΪ%d:\n",cunt++,low);
	for(i=1;i<=n;i++)
	{
		
		for(j=1;j<=i;j++)
			printf("%c-%c:%d  ",go[j]-1+'A',end[j]-1+'A',value[j]);
		printf("\n");
		
	}
}
void choice(int side,int num,int sum)//side��ʾ�ڼ����ߣ�num-1��ʾ���б�����sum��ʾȨֵ֮��
{
	if(num>n||sum>low)
		return ;
	if(side==m+1)
	{
		if(num==n&&sum==low)
		{
			int c=prime();
			if(c==low)//���һ������ķ�㷨���ɵ�Ȩֵ��ȣ���ȵĻ������
				printprime(n-1);
		}
		return ;
	}
	elect[side]=1;        //ѡ��������
	choice(side+1,num+1,sum+p[side].dis);
	elect[side]=0;		//��ѡ��������
	choice(side+1,num,sum);
}
int cmp(node x,node y)			//sort�����е�������
{
	if(x.dis!=y.dis)
		return x.dis<y.dis;		//����Ȩֵ��С��������
	return x.from<y.from;		//��Ȩֵ�൱�����������С��������
}
int find_root(int x)			//���Ҹ��ڵ�
{
	if(x!=father[x])
		father[x]=find_root(father[x]);
	return father[x];
}
int merge(int x,int y)			//�ж��Ƿ���Ժϲ�
{
	int t1=find_root(x);
	int t2=find_root(y);
	if(t1!=t2)					//�������ͬһ�������У��Ϳ��Ժϲ�
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
	printf("�� %d ����С��������ȨֵΪ%d:\n",num++,sum);
	for(int i=1;i<=n-1;i++)   //n�����㣬��n-1����
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
void kruskal(int cur,int num,int sum)			//��cur���ߣ�������������num-1���ߣ���������Ȩֵ������sum
{
	if (cur>m+1)
		return ;
	if(num==n)
	{
		print(sum);
		return ;
	}
	int k=cur;
	while(k<=m&&e[k].dis==e[k+1].dis)				//�ߵ�Ȩֵ��ȣ���ȵı���ֻȡһ����
		k++;
	if(k==cur)										 //û��Ȩֵ��ȵıߣ������Ȩֵ�ı�ֻ��һ���������Ȩֵ�ı�ֻ��һ��
	{
		if(merge(e[cur].from,e[cur].end))				//����һ��������ͼ�����С������
		{
			path[num]=cur;								//����·����
			kruskal(cur+1,num+1,sum+e[cur].dis);	//�ж���һ���ߣ��������еıߵ�������1
		}
		else
			kruskal(cur+1,num,sum);						//��ͬһ��������ж���һ����
		return;
	}
	//��������Ȩֵ�ı��ж�����ִ���������
	int temp[100];
	int i;
	for(i=1;i<=n;i++)								//���׽ڵ��һ�飬��¼ԭֵ
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
				father[i]=temp[i];				//�ָ�ԭֵ
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
		father[i]=i;				 //��ʼ���Լ��ĸ��׽ڵ�Ϊ�Լ�
		
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
	printf("�����붥������ͱ���\n");
	scanf("%d%d",&n,&m);
	while(n<=0||m>(n*(n-1)/2)||m<n-1)
	{
	printf("������������������\n");
	scanf("%d%d",&n,&m);
	}
	printf("��ѡ��\n1.������� 2.�Լ�����\n");
	scanf("%d",&select);
	while(select!=1&&select!=2)
	{
		printf("ѡ�����������ѡ��\n");
		scanf("%d",&select);
	}
	G.vexnum=n;G.arcnum=m;
	kruskalinit();
	InitMgraph();
	printMgarph();
	foreach();                //��Ⱥ͹�����ȱ���
	printf("(����ķ�㷨)**********************\n");
	firstprime();
	choice(1,1,0);
	printf("(��³˹�����㷨)******************\n");
	sort(e+1,e+m+1,cmp);
	kruskal(1,1,0);
	return 0;
}
/*
3 3
1 2 1
2 3 2
3 1 3
һ��
4 4
1 2 2
2 3 2
3 4 2
4 1 2
����
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
��ʮ����
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
һ��
*/