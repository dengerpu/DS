#include "stdio.h"
#define max 100
typedef int Arcell;
typedef int AdjMatrix[5][5];
typedef struct {
	char vexs[5];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;
void bfs(MGraph g,int v,int visited[])   //����һ��ֻ�ܱ�������ͨ��ͼ�е㣬�����Ҫ���������ͨͼ����Ҫ��ε��ã����ü��ξ��м�����ͨ��ͼ
{
	
{
	
	int queue[max],a[max];
	int front=0,rear=1,i,j,k;
	printf("%c ",g.vexs[v]);
	visited[v]=1;  //��ʾ�Ѿ������ʹ�
	queue[rear]=v;
	while(front!=rear)
	{
		front=(front+1)%max;
		v=queue[front];
		i=0;     //�൱�ڼ�¼����
		for(j=0;j<g.vexnum;j++)
			if(g.arcs[v][j]==1)
				a[i++]=j;
			k=0;
			while(k<i)
			{
				if(visited[a[k]]==0)   //���û�б����ʹ�
				{
					visited[a[k]]=1;   //��ʾ�Ѿ����ʹ�
					printf("%c ",g.vexs[a[k]]);
					rear=(rear+1)%max;
					queue[rear]=a[k];  
				}
				k++;
			}
	}
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
		bfs(g,v,visited);
	for(i=0;i<g.vexnum;i++)//ͼ�п��ܴ�����ͨ��ͼ
		if(visited[i]==0)   
			bfs(g,i,visited);
}
