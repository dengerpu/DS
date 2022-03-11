#include<stdio.h>
#include<malloc.h>
#define M 101
typedef struct node
{
	int adjvex;    //顶点
	struct node *next;
}arcnode;
typedef struct
{
	int vertex;   //记录每个顶点的入度
	int chudu;   //记录每个顶点的出度，提交后发现会出出现多个起点或者中点
	arcnode *firstarc;
}vexnode;
vexnode adjlist[M];
int cost[M][M];
int creatadjlist()  //创建图
{
	arcnode *ptr;
	int i;
	int vexnum,arcnum,k,v1,v2; // vexnum顶点个数,vexnum边数,v1,v2代表顶点数，k代表两个顶点之间路径长度
	scanf("%d%d",&vexnum,&arcnum);
	for(i=0;i<vexnum;i++)   //初始化，各顶点的入度为0
	{
		adjlist[i].firstarc=NULL;
		adjlist[i].vertex=0;
		for(int j=0;j<vexnum;j++)
			cost[i][j]=0;
	}
	for(i=0;i<arcnum;i++)
	{
		scanf("%d%d%d",&v1,&v2,&k);
		cost[v1][v2]=k;
		ptr=(arcnode *)malloc(sizeof(struct node));
		ptr->adjvex=v2;            //把v2插在v1后面
		ptr->next=adjlist[v1].firstarc;
		adjlist[v1].firstarc=ptr;
		adjlist[v1].chudu ++;
		adjlist[v2].vertex++;       //顶点v2的入度加1
	}
	
	return vexnum;
}
void tuoposort(int n)//拓扑算法加求关键路径（最早开始时间）
{
	int stack[M];
	int ve[M]={0},a[M],max;
	int top=-1;
	int v,w,sum,i,j=0;
	arcnode *p;
	sum=0;     //用来记录去掉点顶点个数
	for(v=0;v<n;v++)
		if(adjlist[v].vertex==0)
		{
			top++;
			stack[top]=v;
		}
		while(top!=-1)
		{
			v=stack[top];
		    top--;
			p=adjlist[v].firstarc;
			while(p!=NULL)
			{
				w=p->adjvex;
				adjlist[w].vertex--;  //入度减1
				sum++;	
				if(ve[v]+cost[v][w]>=ve[w])  
					ve[w]=ve[v]+cost[v][w];   //取最大值
				if(adjlist[w].vertex==0)
				{
					
					top++;
					stack[top]=w;
				}
				p=p->next;
			}
		}
		if(sum<n)  //说明构成回路
			printf("Impossible\n");
		else
		{
			for(i=0;i<n;i++)
				if(adjlist[i].chudu ==0)  //出度为0就代表是终点
					a[j++]=i;
			max=ve[a[0]];
				for(i=1;i<j-1;i++)
					if(ve[a[i]]>max)
						max=ve[a[i]];
					printf("%d\n",max);
		}
		
}
int main()
{
	int n;
	n=creatadjlist();
	tuoposort(n);
	return 0;
}