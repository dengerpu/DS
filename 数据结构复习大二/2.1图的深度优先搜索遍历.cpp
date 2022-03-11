#include "stdio.h"
#define max 100
typedef int Arcell;
typedef int AdjMatrix[5][5];
typedef struct {
	char vexs[5];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;
void dfs(MGraph g,int v,int visited[])  //�ݹ����������������
{
	int j;
	printf("%c ",g.vexs[v]);
	visited[v]=1;  
	for(j=0;j<g.vexnum;j++)
	{
	if(!visited[j]&&g.arcs[v][j]==1)
		dfs(g,j,visited);
	}
}

void main(){
	int v,visited[max],i;
	MGraph g={
		{'a','b','c','d','e'},
		{{0,1,0,1,0},
		{1,0,0,0,1},
		{1,0,0,1,0},
		{0,1,0,0,1},
		{1,0,0,0,0}},5,9};
		printf("��������ĸ����㿪ʼ������0-4�ֱ����a��e\n");
		scanf("%d",&v);
		for(i=0;i<g.vexnum;i++)
		visited[i]=0;    //��ʼʱ��ȫ��û�б����ʹ�
		dfs(g,v,visited);
	for(i=0;i<g.vexnum;i++)//ͼ�п��ܴ�����ͨ��ͼ
		if(visited[i]==0)   
			dfs(g,i,visited);
}
