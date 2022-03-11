#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 100	//最多顶点个数
#define INFINITY 32768    //表示极大值
typedef struct
{
	char vertex[max];		//用来存放顶点向量
	int arcx[max][max];		//邻接矩阵，用来存放顶点之间的关系
	int vexnum,arcnum;		//用来存放顶点数和弧数
}Mgraph;
void InitMgraph(Mgarph G)
{
	int i,j,x,y,z;
	srand(time(NULL));
	for(i=0;i<G.vexnum;i++)
		//G.vertex[i]=rand()%27+65;
		G.vertex[i]=i+65;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcx[i][j]=INFINITY;
		for(i=0;i<G.arcnum;i++)
		{
			x=rand()%G.vexnum+0;
			y=rand()%G.vexnum+0;
			//	if(x!=y)
			G.arcx[x][y]=rand()%INFINITY+1;
			
		}
}
void printMgarph(Mgraph G)
{
int i,j;
for(i=0;i<G.vexnum;i++)

}


int main()
{
	Mgraph G;
	scanf("%d%d",&G.vexnum,&G.arcnum);
	InitMgraph(G);
	return 0;
}

