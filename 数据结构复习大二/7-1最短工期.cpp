#include<stdio.h>
#include<malloc.h>
#define M 101
typedef struct node
{
	int adjvex;    //����
	struct node *next;
}arcnode;
typedef struct
{
	int vertex;   //��¼ÿ����������
	int chudu;   //��¼ÿ������ĳ��ȣ��ύ���ֻ�����ֶ���������е�
	arcnode *firstarc;
}vexnode;
vexnode adjlist[M];
int cost[M][M];
int creatadjlist()  //����ͼ
{
	arcnode *ptr;
	int i;
	int vexnum,arcnum,k,v1,v2; // vexnum�������,vexnum����,v1,v2����������k������������֮��·������
	scanf("%d%d",&vexnum,&arcnum);
	for(i=0;i<vexnum;i++)   //��ʼ��������������Ϊ0
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
		ptr->adjvex=v2;            //��v2����v1����
		ptr->next=adjlist[v1].firstarc;
		adjlist[v1].firstarc=ptr;
		adjlist[v1].chudu ++;
		adjlist[v2].vertex++;       //����v2����ȼ�1
	}
	
	return vexnum;
}
void tuoposort(int n)//�����㷨����ؼ�·�������翪ʼʱ�䣩
{
	int queue[M];
	int ve[M]={0},a[M],max;
	int front=0,rear=0;
	int v,w,sum,i,j=0;
	arcnode *p;
	sum=0;     //������¼ȥ���㶥�����
	for(v=0;v<n;v++)
		if(adjlist[v].vertex==0)
		{
			rear++;
			queue[rear]=v;
		}
		while(front!=rear)
		{
			front++;
			v=queue[front];
			//printf("%d ",v);//������Ϊ0�Ķ���
			p=adjlist[v].firstarc;
			while(p!=NULL)
			{
				w=p->adjvex;
				adjlist[w].vertex--;  //��ȼ�1
				sum++;	
				if(ve[v]+cost[v][w]>=ve[w])  
					ve[w]=ve[v]+cost[v][w];   //ȡ���ֵ
				if(adjlist[w].vertex==0)
				{
					
					rear++;
					queue[rear]=w;
				}
				p=p->next;
			}
		}
		if(sum<n)  //˵�����ɻ�·
			printf("Impossible\n");
		else
		{
			for(i=0;i<n;i++)
				if(adjlist[i].chudu ==0)  //����Ϊ0�ʹ������յ�
					a[j++]=i;
				max=ve[a[0]];
				for(i=1;i<j-1;j++)
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