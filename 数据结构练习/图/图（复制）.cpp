
/*Ԥ������*/ 
#include <stdio.h> 
#include <stdlib.h> 
#define INFINITY 2147483647 //4�ֽ��з������������ֵ
#define MAX 20 //ͼ����󶥵����
#define OK 1 
#define ERROR 0 
/*�ṹ���Ͷ��岿��*/ 
typedef char VertexType; //ͼ�������������
typedef int Status; 
typedef int VRType; //����Ĺ�ϵ������������
typedef enum {DG,DN,UDG,UDN}GraphKind; //{����ͼ��������������ͼ��������} 
typedef struct { 
	VertexType vexs[MAX]; //���㼯
	VRType arcs[MAX][MAX]; //��ϵ��
	int vexnum; //�������
	int arcnum; //��ϵ��
	GraphKind kind; //ͼ������
}MGraph; 
typedef struct { 
	VertexType adjvex; 
	VRType lowcost; 
}edge; 
MGraph G[4]; //ȫ�ֱ��������Էֱ�洢4�в�ͬ���͵�ͼ
int visited[MAX]; //ȫ�ֱ��������Ա�Ƿ��ʹ��Ķ����±�
Status (*VisitFunc) (MGraph G,int v); //ȫ�ֺ���ָ��
edge closedge[MAX]; //ȫ�ֱ�����������С�������ı�
/*������������*/ 
int LocateVex (MGraph G,VertexType v); 
Status CreateDG (MGraph &G); 
Status CreateUDG (MGraph &G); 
Status CreateDN (MGraph &G); 
Status CreateUDN (MGraph &G); 
Status PrintVex (MGraph G,int v); 
int FirstAdjVex (MGraph G,int v); 
int NextAdjVex (MGraph G,int v,int w); 
void DFS (MGraph G,int v); 
void DFSTraverse (MGraph G,Status (*Visit) (MGraph G,int v)); 
void BFSTraverse (MGraph G,Status (*Visit) (MGraph G,int v)); 
Status ShortestPath_DIJ (MGraph G,int v0,int P[][MAX],int *D); 
Status PrintShortestPath (MGraph G,int v0,int P[][MAX],int *D); 
int mininum (edge *closedge,int v); 
Status MiniSpanTree_PRIM (MGraph G,int v0); 
/*�������岿��*/ 
int LocateVex (MGraph G,VertexType v) { 
	//��λ���㼯�е�Ԫ��
	int i=0; 
	while ((v!=G.vexs[i])&&(i<G.vexnum)) i++; 
	return i; 
} //end LocateVex 
Status CreateDG (MGraph &G) { 
	//��������ͼ
	int i=0,j=0,k=0;VertexType v1,v2; 
	printf ("������ͼ�еĶ���������"); 
	scanf ("%d",&G.vexnum); 
	printf ("�����뻡������"); 
	scanf ("%d",&G.arcnum); 
	printf ("������%d������ֵ��",G.vexnum); 
	getchar (); 
	for ( ;i<G.vexnum;i++) 
		scanf ("%c",&G.vexs[i]); //����ͼ����ֵ(ע��%cǰ�пո�ʱ���������м�ӿո��磺a b c���޿ո�ʱ���������м䲻�ӿո��磺abc) 
	for (i=0;i<G.vexnum;i++) 
		for (j=0;j<G.vexnum;j++) G.arcs[i][j]=0; //��ʼ����ϵ��
		for ( ;k<G.arcnum;k++) { //�����ڽӾ���
			printf ("�������%d����Ϊ��β����ͷ��Ԫ�أ�",k+1); //�����й�ϵ��һ�Զ���
			getchar (); 
			scanf ("%c%c",&v1,&v2); 
			i=LocateVex (G,v1);j=LocateVex (G,v2); //ȷ��v1,v2��G�Ķ��㼯�е�λ��
			if ((i==G.vexnum)||(j==G.vexnum)) { 
				printf ("����Ԫ���������\n");return ERROR; 
			} 
			G.arcs[i][j]=1; 
		} 
		printf ("�ɹ���������ͼ\n"); 
		return OK; 
} //end CreateDG 
Status CreateUDG (MGraph &G) { 
	//��������ͼ
	int i=0,j=0,k=0;VertexType v1,v2; 
	printf ("������ͼ�еĶ���������"); 
	scanf ("%d",&G.vexnum); 
	printf ("�������������"); 
	scanf ("%d",&G.arcnum); 
	printf ("������%d������ֵ��",G.vexnum); 
	getchar (); 
	for ( ;i<G.vexnum;i++) scanf (" %c",&G.vexs[i]); //����ͼ����ֵ(ע��%cǰ�пո�ʱ���������м�ӿո��磺a b c���޿ո�ʱ���������м䲻�ӿո��磺abc) 
	for (i=0;i<G.vexnum;i++) 
		for (j=0;j<G.vexnum;j++) G.arcs[i][j]=0; //��ʼ����ϵ��
		for ( ;k<G.arcnum;k++) { //�����ڽӾ���
			printf ("�������%d����Ϊ�����˵�Ԫ�أ�",k+1); //�����й�ϵ��һ�Զ���
			getchar (); 
			scanf ("%c%c",&v1,&v2); 
			i=LocateVex (G,v1);j=LocateVex (G,v2); //ȷ��v1,v2��G�Ķ��㼯�е�λ��
			if ((i==G.vexnum)||(j==G.vexnum)) { 
				printf ("�߶�Ԫ���������\n");return ERROR; 
			} 
			G.arcs[i][j]=1;G.arcs[j][i]=1; 
		} 
		printf ("�ɹ���������ͼ\n"); 
		return OK; 
} //end CreateUDG 
Status CreateDN (MGraph &G) { 
	//����������
	int i=0,j=0,k=0,qz=0;VertexType v1,v2; 
	printf ("������ͼ�еĶ���������"); 
	scanf ("%d",&G.vexnum); 
	printf ("�����뻡������"); 
	scanf ("%d",&G.arcnum); 
	printf ("������%d������ֵ��",G.vexnum); 
	getchar (); 
	for ( ;i<G.vexnum;i++) scanf ("%c",&G.vexs[i]); //����������ֵ
	for (i=0;i<G.vexnum;i++) 
		for (j=0;j<G.vexnum;j++) G.arcs[i][j]=INFINITY; //��ʼ����ϵ��
		for ( ;k<G.arcnum;k++) { //�����ڽӾ���
			printf ("�������%d����Ϊ��β����ͷ��Ԫ�ؼ�Ȩֵ��",k+1); //�����й�ϵ��һ�Զ���
			getchar (); 
			scanf ("%c%c%d",&v1,&v2,&qz); 
			i=LocateVex (G,v1);j=LocateVex (G,v2); //ȷ��v1,v2��G�Ķ��㼯�е�λ��
			if ((i==G.vexnum)||(j==G.vexnum)) { 
				printf ("����Ԫ���������\n");return ERROR; 
			} 
			G.arcs[i][j]=qz; 
		} 
		printf ("�ɹ�����������\n"); 
		return OK; 
} //end CreateDN 
Status CreateUDN (MGraph &G) { 
	//����������
	int i=0,j=0,k=0,qz=0;VertexType v1,v2; 
	printf ("������ͼ�еĶ���������"); 
	scanf ("%d",&G.vexnum); 
	printf ("�������������"); 
	scanf ("%d",&G.arcnum); 
	printf ("������%d������ֵ��",G.vexnum); 
	getchar (); 
	for ( ;i<G.vexnum;i++) scanf ("%c",&G.vexs[i]); //����������ֵ
	for (i=0;i<G.vexnum;i++) 
		for (j=0;j<G.vexnum;j++) G.arcs[i][j]=INFINITY; //��ʼ����ϵ��
		for ( ;k<G.arcnum;k++) { //�����ڽӾ���
			printf ("�������%d����Ϊ�߶˵���Ԫ�ؼ�Ȩֵ��",k+1); //�����й�ϵ��һ�Զ���
			getchar (); 
			scanf ("%c%c%d",&v1,&v2,&qz); 
			i=LocateVex (G,v1);j=LocateVex (G,v2); //ȷ��v1,v2��G�Ķ��㼯�е�λ��
			if ((i==G.vexnum)||(j==G.vexnum)) { 
				printf ("�߶�Ԫ���������\n");return ERROR; 
			} 
			G.arcs[i][j]=qz;G.arcs[j][i]=qz; 
		} 
		printf ("�ɹ�����������\n"); 
		return OK; 
} //end CreateUDN 
Status PrintVex (MGraph G,int v) { 
	//���ͼ�ĵ�v������
	printf ("%c",G.vexs[v]); 
	return OK; 
} //end PrintVex 
int FirstAdjVex (MGraph G,int v) { 
	//��ͼG�в��ҵ�v������ĵ�1���ڽӶ���
	int i=0; 
	while ((i<G.vexnum)&&((G.arcs[v][i]==0)||(G.arcs[v][i]==INFINITY))) i++; 
	if (i==G.vexnum) return -1; 
	else return i; 
} //end FirstAdjVex 
int NextAdjVex (MGraph G,int v,int w) { 
	int i=0,k=0; 
	for (i=w+1;(i<G.vexnum)&&((G.arcs[v][i]==0)||(G.arcs[v][i]==INFINITY));i++) {} 
	if (i==G.vexnum) return -1; 
	else return i; 
} //end NextAdjVex 
void DFS (MGraph G,int v) { 
	//�ӵ�v������ݹ�����������������ͼG 
	int w=0; 
	VisitFunc (G,v);visited[v]=1; //���ʶ��㣬���ñ�׼��������ӦԪ��ֵΪ1 
	for (w=FirstAdjVex (G,v);w>=0;w=NextAdjVex (G,v,w)) 
		if (!visited[w]) DFS (G,w); //��v��δ���ʵ��ڽӶ���ݹ�ص���DFS 
} //end DFS 
void DFSTraverse (MGraph G,Status (*Visit) (MGraph G,int v)) { 
	//���������������
	int v=0;char y='\0'; 
	printf ("����������׶��㣺"); 
	getchar (); 
	scanf ("%c",&y); 
	printf ("�������������������Ϊ��"); 
	VisitFunc=Visit; //ʹ��ȫ�ֱ�����ʹ��DFS���������躯������
	for ( ;v<G.vexnum;v++) visited[v]=0; //��־�����ʼ��
	v=LocateVex (G,y); 
	DFS (G,v); //���׶������DFS 
	for (v=0;v<G.vexnum;v++) 
		if (!visited[v]) DFS (G,v); //��δ���ʵĶ������DFS 
} //end DFSTraverse 
void BFSTraverse (MGraph G,Status (*Visit) (MGraph G,int v)) { 
	//���������������
	int w=0,i=0,v=0,u=0;char y='\0'; 
	int Queue[MAX]={0},front=0,rear=0; 
	printf ("����������׶��㣺"); 
	getchar (); 
	scanf ("%c",&y); 
	printf ("�������������������Ϊ��"); 
	for ( ;v<G.vexnum;v++) visited[v]=0; //��־�����ʼ��
	v=LocateVex (G,y); 
	i=v; 
	Visit (G,i);visited[i]=1; 
	Queue[rear++]=i; //i���
	while (front!=rear) { 
		u=Queue[front++]; //��ͷԪ�س���
		for (w=FirstAdjVex (G,u);w>=0;w=NextAdjVex (G,u,w)) { 
			if (visited[w]==0) { //wΪu����δ���ʵ��ڽӶ���
				Visit (G,w);visited[w]=1; 
				Queue[rear++]=w; 
			} 
		} 
	} 
	for (i=0;i<G.vexnum;i++) 
		if (visited[i]==0) { //i��δ����
			Visit (G,i);visited[i]=1; 
			Queue[rear++]=i; //i���
			while (front!=rear) { 
				u=Queue[front++]; //��ͷԪ�س���
				for (w=FirstAdjVex (G,u);w>=0;w=NextAdjVex (G,u,w)) { 
					if (visited[w]==0) { //wΪu����δ���ʵ��ڽӶ���
						Visit (G,w);visited[w]=1; 
						Queue[rear++]=w; 
					} 
				} 
			} 
		} 
} //end BFSTraverse 
Status ShortestPath_DIJ (MGraph G,int v0,int P[][MAX],int *D) { 
	//Dijkstra�㷨��v0���㵽��������������;�����䳤��
	//P[v][w]Ϊ1����ʾw�Ǵ�v0��v�����·���ĵ�ǰ����
	//final[v]Ϊ1����ʾv��v0�����·������ã���v����S��
	int i=0,v=0,w=0,u=0,final[MAX],min=0; 
	for (v=0;v<G.vexnum;v++) { 
		final[v]=0;D[v]=G.arcs[v0][v]; 
		for (w=0;w<G.vexnum;w++) P[v][w]=0; //���·��
		if (D[v]<INFINITY) {P[v][v0]=1;P[v][v]=1;} 
	} 
	D[v0]=0;final[v0]=1; //��ʼ��,v0���������S��
	for (i=1;i<G.vexnum;i++) { //ѭ��G.vexnum-1��
		min=INFINITY; 
		for (w=0;w<G.vexnum;w++) { 
			if (final[w]==0) 
				if (D[w]<min) {v=w;min=D[w];} //w����v0����
		} 
		if (v==G.vexnum) return ERROR; 
		final[v]=1; //v����S��
		for (w=0;w<G.vexnum;w++) //���µ�ǰ���·�����䳤��
			if ((final[w]==0)&&(G.arcs[v][w]!=INFINITY)&&(min+G.arcs[v][w]<D[w])) { //w����V-S�����޸�D[w]��P[w] 
				D[w]=min+G.arcs[v][w]; 
				for (u=0;u<G.vexnum;u++) P[w][u]=P[v][u]; 
				P[w][w]=1; 
			} 
	} 
	return OK; 
} //end ShortestPath_DIJ 
Status PrintShortestPath (MGraph G,int v0,int P[][MAX],int *D) { 
	//������·�����䳤��
	int i=0,w=0,r=0,u=0,min;int wz[MAX]; 
	printf ("Դ��%c����������������·�����䳤��Ϊ��\n",G.vexs[v0]); 
	for (i=0;i<G.vexnum;i++) { 
		if (i!=v0) { 
			if (D[i]==INFINITY) printf ("%c->%c: ��·��\n",G.vexs[v0],G.vexs[i]); 
			else { 
				printf ("%c->%c: %c",G.vexs[v0],G.vexs[i],G.vexs[v0]); 
				for (w=0;w<G.vexnum;w++) wz[w]=-1; 
				for (w=0;w<G.vexnum;w++) { 
					if (P[i][w]==1) wz[w]=w; 
				} 
				while (wz[v0]!=i) { 
					min=INFINITY; 
					for (w=0;w<G.vexnum;w++) { 
						if ((wz[w]==w)&&(G.arcs[wz[v0]][w]<min)) { 
							r=w;min=G.arcs[wz[v0]][r]; 
						} 
					} 
					wz[r]=-1;wz[v0]=r; 
					printf ("->%c",G.vexs[wz[v0]]); 
				} 
				printf (" (%d)\n",D[i]); 
			} 
		} 
	} 
	return OK; 
} //end PrintShortestPath 
int mininum (edge *closedge,int v) { 
	//���������д���Ϊ������С���±�
	int i=0,mini=-1; 
	for (i=0;i<=v;i++) { 
		if (closedge[i].lowcost>0) { 
			if (mini==-1) mini=i; 
			else if (closedge[mini].lowcost>closedge[i].lowcost) mini=i; 
		} 
	} 
	return mini; 
} //end mininum 
Status MiniSpanTree_PRIM (MGraph G,int v0) { 
	//��Prim�㷨����������ͨͼ����С������
	if (G.kind==DG) {printf ("��ͼΪ����ͼ����������\n");return ERROR;} 
	if (G.kind==DN) {printf ("��ͼΪ����������������\n");return ERROR;} 
	if (G.kind==UDG) {printf ("��ͼΪ����ͼ����������\n");return ERROR;} 
	int k=v0,i=0,j=0,min=0; 
	for (j=0;j<G.vexnum;j++) { //���������ʼ��
		if (j!=k) { 
			closedge[j].adjvex=G.vexs[k]; 
			closedge[j].lowcost=G.arcs[k][j]; 
		} 
	} 
	closedge[k].lowcost=0; //��ʼ
	printf ("��С�������ĸ��߼���Ȩֵ���£�\n"); 
	for (i=1;i<G.vexnum;i++) { //ѡ������G.vexnum-1������
		k=mininum (closedge,G.vexnum); 
		if (k<0) { 
			printf ("���������ǵ���ͨ�����������������㣬������һ����ͨ��ͼ����С������\n"); 
			break; 
		} 
		printf ("%c-->%c (%d)\n",closedge[k].adjvex,G.vexs[k],closedge[k].lowcost); 
		closedge[k].lowcost=0; 
		for (j=0;j<G.vexnum;j++) { 
			if (G.arcs[k][j]<closedge[j].lowcost) { 
				closedge[j].adjvex=G.vexs[k];closedge[j].lowcost=G.arcs[k][j]; 
			} 
		} 
	} 
	return OK; 
} //end MiniSpanTree_PRIM 
/*����������*/ 
void main () { 
	char menu=1,wz=0,lx=0,y='\0';int D[MAX],P[MAX][MAX],v0=0; 
	while (menu) { 
		printf ("***************************�˵�����******************************\n"); 
		printf (" 0������������������������������������\n"); 
		printf (" 1������������������������������ͼ\n"); 
		printf (" 2�������������������������������������������\n"); 
		printf (" 3�������������������������������������������\n"); 
		printf (" 4����������������������������Դ��ķ�ɢ���·�����䳤��\n"); 
		printf (" 5����������������������������������ͨ������С������\n"); 
		printf ("��ѡ��˵���"); 
		scanf ("%d",&menu); 
		switch (menu) { 
		case 0: 
			break; 
		case 1: 
			printf ("*******************��ʼ��ͼ********************\n"); 
			printf ("������ͼ�����ͣ�0-DG��1-DN��2-UDG��3-UDN����"); 
			scanf ("%d",&lx); 
			printf ("������ͼ�����͵Ĵ洢λ�ã�0-DG��1-DN��2-UDG��3-UDN����"); 
			scanf ("%d",&wz); 
			switch (lx) { 
			case 0: 
				G[wz].kind=DG;printf ("��ʼ������ͼ\n");CreateDG (G[wz]);break; 
			case 1: 
				G[wz].kind=DN;printf ("��ʼ��������\n");CreateDN (G[wz]);break; 
			case 2: 
				G[wz].kind=UDG;printf ("��ʼ������ͼ\n");CreateUDG (G[wz]);break; 
			case 3: 
				G[wz].kind=UDN;printf ("��ʼ��������\n");CreateUDN (G[wz]);break; 
			default: 
				printf ("ͼ����ѡ�����\n");break; 
			} 
			printf ("*******************������ͼ********************\n"); 
			break; 
			case 2: 
				printf ("**************��ʼ���������������*************\n"); 
				printf ("������Ҫ�����������������ͼ�Ĵ洢λ�ã�0-DG��1-DN��2-UDG��3-UDN����"); 
				scanf ("%d",&wz); 
				if (G[wz].vexnum!=0) {DFSTraverse (G[wz],PrintVex);printf ("\n");} 
				else printf ("ͼΪ��ͼ\n"); 
				printf ("**************�������������������*************\n"); 
				break; 
			case 3: 
				printf ("**************��ʼ���������������*************\n"); 
				printf ("������Ҫ�����������������ͼ�Ĵ洢λ�ã�0-DG��1-DN��2-UDG��3-UDN����"); 
				scanf ("%d",&wz); 
				if (G[wz].vexnum!=0) {BFSTraverse (G[wz],PrintVex);printf ("\n");} 
				else printf ("ͼΪ��ͼ\n"); 
				printf ("**************�������������������*************\n"); 
				break; 
			case 4: 
				printf ("************��ʼ���Դ��ķ�ɢ���·�����䳤��*************\n"); 
				printf ("������ͼ�Ĵ洢λ�ã�0-DG��1-DN��2-UDG��3-UDN����"); 
				scanf ("%d",&wz); 
				getchar (); 
				printf ("������Դ��ֵ��"); 
				scanf ("%c",&y); 
				v0=LocateVex (G[wz],y); 
				if (v0==G[wz].vexnum) {printf ("����Ԫ�ز���ͼ��\n");break;} 
				ShortestPath_DIJ (G[wz],v0,P,D); 
				PrintShortestPath (G[wz],v0,P,D); 
				printf ("************�������Դ��ķ�ɢ���·�����䳤��*************\n"); 
				break; 
			case 5: 
				printf ("*****************��ʼ����������ͨ������С������****************\n"); 
				printf ("���������Ĵ洢λ�ã�"); 
				scanf ("%d",&wz); 
				getchar (); 
				printf ("����������Ԫ�أ�"); 
				scanf ("%c",&y); 
				v0=LocateVex (G[wz],y); 
				if (v0==G[wz].vexnum) {printf ("����Ԫ�ز�������\n");break;} 
				MiniSpanTree_PRIM (G[wz],v0); 
				printf ("*****************��ʼ����������ͨ������С������****************\n"); 
				break; 
			default: 
				printf ("ѡ�����\n"); 
				break; 
		} 
		printf ("\n"); 
	} 
	printf ("������ȫ����\n"); 
} //end main