#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 100	//��ඥ�����
#define INFINITY 32768    //��ʾ����ֵ
typedef struct
{
	char vertex[max];		//������Ŷ�������
	int arcx[max][max];		//�ڽӾ���������Ŷ���֮��Ĺ�ϵ
	int vexnum,arcnum;		//������Ŷ������ͻ���
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

