#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m,s1,s2;
typedef struct
{
	unsigned int weight;
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
}HTNode,* HuffmanTree;	//��̬��������洢��������
typedef char * HuffmanCode;	//��̬��������洢�����������
void Select(HuffmanTree HT,int n)
{
	int i,j,tmp;
	for(i=1;i<=n;i++)
		if(!HT[i].parent)
		{
			s1=i; break;
		}
	for(j=i+1;j<=n;j++)
		if(!HT[j].parent)
		{
			s2=j; break;
		}
	for(i=1;i<=n;i++)
		if((HT[s1].weight>HT[i].weight) && (!HT[i].parent) && (s2!=i))
			s1=i;
	for(j=1;j<=n;j++)
		if((HT[s2].weight>HT[j].weight) && (!HT[j].parent) && (s1!=j))
			s2=j;
	if(HT[s1].weight>HT[s2].weight)
	{
		tmp=s1;
		s1=s2;
		s2=tmp;
	}
}
void HuffmanCoding(HuffmanTree &HT,HuffmanCode HC[],int * w,int n)
{
	//w���n���ַ���Ȩֵ����>0��������������� HT��
	//�����n���ַ��Ĺ���������
	int i,j;
	char * cd;
	int p;
	int cdlen;
	if(n<=1)
		return ;
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));	//0�ŵ�Ԫδ��
	for(i=1;i<=n;i++)
	{
		//��ʼ��
		HT[i].weight=w[i-1];
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		//��ʼ��
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	puts("\n���������Ĺ������������ʾ��");
	printf("HT ��̬��\n  ���  weight  parent  lchild  rchild");
	for(i=1;i<=m;i++)
		printf("\n%4d%8d%8d%8d%8d",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	for(i=n+1;i<=m;i++)
	{
		//����������
		//��HT[1...i-1]��ѡ��parentΪ0��weight��С���������
		//����ŷֱ�Ϊs1��s2
		Select(HT,i-1);
		HT[s1].parent=i; HT[s2].parent=i;
		HT[i].lchild=s1; HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		printf("\nselect:s1=%d s2=%d\n",s1,s2);
		printf(" ���  weight  parent  lchild  rchild");
		for(j=1;j<=i;j++)
			printf("\n%4d%8d%8d%8d%8d",j,HT[j].weight,HT[j].parent,HT[j].lchild,HT[j].rchild);
	}
	//------��ջ�ǵݹ�������������������������
	cd=(char *)malloc(n*sizeof(char));	//���������Ĺ����ռ�
	p=m; cdlen=0;
	for(i=1;i<=m;++i)	//������������ʱ�������״̬��־
		HT[i].weight=0;
	while(p)
	{
		if(HT[p].weight==0)
		{
			//����
			HT[p].weight=1;
			if(HT[p].lchild!=0)
			{
				p=HT[p].lchild;
				cd[cdlen++]='0';
			}
			else if(HT[p].rchild==0)
			{
				//�Ǽ�Ҷ�ӽ����ַ��ı���
				HC[p]=(char *)malloc((cdlen+1)*sizeof(char));
				cd[cdlen]='\0';
				strcpy(HC[p],cd);	//���Ʊ��루����
			}
		}
		else if(HT[p].weight==1)
		{
			//����
			HT[p].weight=2;
			if(HT[p].rchild!=0)
			{
				p=HT[p].rchild;
				cd[cdlen++]='1';
			}
		}
		else
		{
				//HT[p].weight=2�����˵�����㣬���볤�ȼ�1
				HT[p].weight=0; p=HT[p].parent;
				--cdlen;
		}
	}
}	//HuffmanCoding
int main()
{
	HuffmanTree HT;
	HuffmanCode * HC;
	int * w,n,i;
	puts("����������");
	scanf("%d",&n);
	HC=(HuffmanCode *)malloc(n*sizeof(HuffmanCode));
	w=(int *)malloc(n*sizeof(int));
	printf("����%d������Ȩֵ\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	HuffmanCoding(HT,HC,w,n);
	puts("\n�����Ĺ��������룺");
	for(i=1;i<=n;i++)
		printf("%2d(%4d):%s\n",i,w[i-1],HC[i]);
	return 0;
	//getchar();
}