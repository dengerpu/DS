/* �����ṹ���� */
typedef int KeyType;
typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;
/* ���㷨9.1�� ֱ�Ӳ��뷨 */
void InsSort(RecordType r[],int length)
/* �Լ�¼����r��ֱ�Ӳ�������lengthΪ�����д������¼����Ŀ */
{
	for(i=2;i<=length;i++)
	{
		r[0]=r[i]; j=i-1;	//���������¼��ŵ�������r[0]��
		while(r[0].key<r[j].key)	//Ѱ�Ҳ���λ��
		{ r[j+1]=r[j]; j=j-1; }
		r[j+1]=r[0];	//���������¼���뵽�������������
	}
}
/* ���㷨9.2�� �۰�������� */
void BinSort(RecordType r[],int length)
/* �Լ�¼����r�����۰��������lengthΪ����ĳ��� */
{
	for(i=2;i<=length;++i)
	{
		x=r[i];
		low=1; high=i-1;
		while(low<=high)	//ȷ������λ��
		{
			mid=(low+high)/2;
			if(x.key<r[mid].key)
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=low;--j)
			r[j+1]=r[j];	//��¼��������ƶ�
		r[low]=x;	//�����¼
	}
}
/* ���㷨9.3�� ϣ������ */
void ShellInsert(RecordType r[],int length,int delta)
/* �Լ�¼����r��һ��ϣ����������lengthΪ����ĳ��ȣ�deltaΪ���� */
{
	for(i=1+delta;i<=length;i++)	//1+deltaΪ��һ�������еĵڶ���Ԫ���±�
		if(r[i].key<r[i-delta].key)
		{
			r[0]=r[i];	//����r[i]�����������ڣ�
			for(j=i-delta;j>0 && r[0].key<r[j].key;j-=delta)
				r[j+delta]=r[j];
			r[j+delta]=r[0];
		}
}	//ShellInsert
void ShellSort(RecordType r[],int length,int delta,int n)
/* �Լ�¼����r��ϣ������lengthΪ����r�ĳ��ȣ�deltaΪ�������飬nΪdelta[]�ĳ��� */
{
	for(i=0;i<=n-1;++i)
		ShellInsert(r,length,delta[i]);
}
/* ���㷨9.4�� ð������ */
void BubbleSort(RecordType r[],int n)
/* �Լ�¼����r��ð������n����ĳ��� */
{
	change=TRUE;
	for(i=1;i<=n-1 && change;++i)
	{
		change=FALSE;
		for(j=1;j<=n-1;++j)
			if(r[j].key>r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}	//BubbleSort
/* ���㷨9.5�� �����Ŀ��������㷨 */
void QKSort(RecordType r[],int low,int high)
/* �Լ�¼����r[low...high]�ÿ��������㷨�������� */
{
	if(low<high)
	{
		pos=QKPass(r,low,high);	//����һ�˿�������������Ԫ��Ϊ�绮�������ӱ�
		OKSort(r,low,pos-1);	//�����ӱ��������
		QKSort(r,pos+1,high);	//���Ҳ��ӱ��������
	}
}
/* ���㷨9.6�� һ�˿��������㷨 */
int QKPass(RecordType r[],int low,int high)
/* �û�׼��¼��r[low]��r[high]���ֽ���һ�˿������򣨻��֣������õ���׼��¼����λ�ã�ʹ�û�׼��¼֮ǰ���м�¼�Ĺؼ��֣�
����׼��¼֮�����м�¼�Ĺؼ��־����ڻ���ڻ�׼��¼�Ĺؼ��� */
{
	x=r[low];	//ѡ���׼��¼
	while(low<high)
	{
		while(low<high && r[high].key>=x.key)
			high--;	//high���ҵ�����С��x.key�ļ�¼
		if(low<high) { r[low]=r[high]; low++; }	//�ҵ�С��x.key�ļ�¼�������롰�յ�Ԫ��r[low]
		while(low<high && r[low].key<x.key)
			low++;	//low�������Ҵ��ڻ����x.key�ļ�¼
		if(low<high) { r[high]=r[low]; high--; }	//�ҵ�����x.key�ļ�¼�������롰�յ�Ԫ��r[high]
	}
	r[low]=x;	//����׼��¼���浽low=high��λ��
	return low;	//���ػ�׼��¼��λ��
}
/* ���㷨9.7�� ��ѡ������ */
void SelectSort(RecordType r[],int n)
/* �Լ�¼����r����ѡ������nΪ����ĳ��� */
{
	for(i=1;i<=n-1;++i)
	{
		k=i;
		for(j=i+1;j<=n;++j)
			if(r[j].key<r[k].key)
				k=j;
		if(k!=i)
		{ x=r[i]; r[i]=r[k]; r[k]=x; }
	}
}	//SelectSort
/* ���㷨9.8�� �ؽ��ѹ��� */
void sift(RecordType r[],int k,int m)
/* ����r[k...m]����r[k]Ϊ������ȫ���������ҷֱ���r[2*k]��r[2*k+1]Ϊ������������Ϊ����ѣ�����r[k]��ʹ��������r[k...m]����ѵ����� */
{
	t=r[k];	//�ݴ桰������¼r[k]
	x=r[k].key;
	i=k;
	j=2*i;
	finished=FALSE;
	while(j<=m && !finished)
	{
		if(j+1<=m && r[j].key<r[j+1].key)
			j=j+1;	//�������������������������Ĺؼ��ִ������ҷ�֧��ɸѡ��
		if(x>=r[j].key)
			finished=TRUE;	//ɸѡ���
		else
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}	//����ɸѡ
	}
	r[i]=t;	//r[k]���뵽ǡ����λ��
}
/* ���㷨9.9�� �������㷨 */
void crt_heap(RecordType r[],int n)
/* �Լ�¼����r���ѣ�n������ĳ��� */
{
	for(i=n/2;i>=1;--i)	//�Ե�[n/2]����¼��ʼ����ɸѡ����
		sift(r,i,n);
}
/* ���㷨9.10�� �������㷨 */
void HeapSort(RecordType r[],int n)
/* ��r[1...n]���ж�����ִ�б��㷨��r�м�¼���ؼ�����С������������ */
{
	crt_heap(r,n);
	for(i=n;i>=2;--i)
	{
		b=r[1];	//���Ѷ���¼�Ͷ�β��¼����
		r[1]=r[i];
		r[i]=b;
		sift(r,1,i-1);	//���е�����ʹr[1...i-1]��ɶ�
	}
}	//HeapSort
/* ���㷨9.11�� �����������������еĺϲ����㷨 */
void Merge(RecordType r1[],int low,int mid,int high,RecordType r2[])
/* ��֪r1[low...mid]��r1[mid+1...high]�ֱ𰴹ؼ����������У������Ǻϲ���һ���������У������r2[low...high] */
{
	i=low; j=mid+1; k=low;
	while(i<=mid && j<=high)
	{
		if(r1[i].key<=r1[j].key)
		{ r2[k]=r1[i]; ++i; }
		else
		{ r2[k]=r1[j]; ++j; }
		++k;
	}
	while(i<=mid)
	{ r2[k]=r1[i]; k++,i++; }
	while(j<=high)
	{ r2[k]=r1[j]; k++,j++; }
}	//Merge
/* ���㷨9.12�� 2-·�鲢����ĵݹ��㷨 */
void NSort(RecordType r1[],int low,int high,RecordType r3[])
/* r1[low...high]��������r3[low...high]�У�r2[low...high]Ϊ�����ռ� */
{
	RecordType * r2;
	r2=(RecordType *)malloc(sizeof(RecordType)*(high-low+1));
	if(low==high) r3[low]=r1[low];
	else
	{
		mid=(low+high)/2;
		MSort(r1,low,mid,r2);
			MSort(r1,mid+1,high,r2);
		Merge(r2,low,mid,high,r3);
	}
	free(r2);
}	//MSort
/* ���㷨9.13�� 2-·�鲢����ĳ�ʼ���ù��� */
void MergeSort(RecordType r[],int n)
/* �Լ�¼����r[1...n]���鲢���� */
{
	MSort(r,1,n,r);
}
/* ����������̬�����������Ͷ������� */
#define RADIX 10
#define KEY_SIZE 6
#define LIST_SIZE 20
typedef int KeyTYpe;
typedef struct
{
	KeyType keys[KEY_SIZE];	//�ӹؼ�������
	OtherType other_data;	//����������
	int next;	//��̬����
}RecordType;
typedef struct
{
	RecordType r[LIST_SIZE+1];	//r[0]Ϊͷ���
	int length;
	int keynum;
}SLinkList;	//��̬����
typedef int PVector[RADIX];
/* ���㷨9.14�� ��ʽ���������㷨 */
void Distribute(RecordType r[],int i,PVector head,PVector tail)
/* ��¼����r�м�¼�Ѱ���λ�ؼ���key[i+1]��...��key[d]���й�����λ���ȡ����򡣱��㷨����iλ�ؼ���key[i]����RADIX�����У�
ͬһ�������м�¼��key[i]��ͬ��head[j]��tail[j]�ֱ�ָ��������е�һ�������һ����¼��j=0,1,2��...��RADIX-1����head[j]=0
��ʾ��Ӧ����Ϊ�ն��� */
{
	for(j=0;j<=RADIX-1;++j)
		head[j]=0;	//��RADIX�����г�ʼ��Ϊ�ն���
	p=r[0].next;	//pָ�������еĵ�һ����¼
	while(p!=0)
	{
		j=Order(r[p].key[i]);	//�ü�¼�е�iλ�ؼ�������Ӧ���к�
		if(head[j]==0) head[j]=p;	//��p��ָ��Ľ������i��������
		else r[tail[j]].next=p;
		tail[j]=p;
		p=r[p].next;
	}
}	/* Distribute */
void Collect(RecordType r[],PVector head,PVector tail)
/* ���㷨��0��RADIX-1ɨ������У������зǿն�����β��ӣ��������ӳ�һ������ */
{
	j=0;
	while(head[j]==0) ++j;	//�ҵ�һ���ǿն���
	r[0].next=head[j]; t=tail[j];
	while(j<RADIX-1)
	{
		++j;
		while(j<RADIX-1) && (head[j]==0)) ++j;	//����һ���ǿն���
		if(head[j]!=0)	//���ӷǿն���
		{ r[t].next=head[j]; t=tail[j]; }
	}
	r[t].next=0;	//tָ�����һ���ǿն����е����һ�����
}	/* Collect */
void RadixSort(RecordType r[],int n,int d)
/* n����¼���������r�У�dΪ�ؼ���λ����ִ�б��㷨���л�������������еļ�¼�����ؼ��ִ�С�����˳�������� */
{
	n=length;
	for(i=0;i<=n-1;++i) r[i].next=i+1;	//���쾲̬����
	r[n].next=0;
	for(i=d-1;i>=0;--i)	//�����λ�ӹؼ��ֿ�ʼ������d�˷�����ռ�
	{
		Distribute(r,i,head,tail);	//��i�˷���
		Collect(r,head,tail);	//��i���ռ�
	}
}	//RadixSort
/* ���㷨9.15�� �����������������㷨1����ѡ������ */
/* ������ɫ���δ����L[0...n-1]�У����㷨���ü�ѡ������˼�룬���������а��졢�ס����������� */
{
	int i,j,x;
	i=0;	//iָ���һ����ɫ����Ӧ�÷ŵ�λ��
	for(j=i;j<n;j++)	//jɨ��������δ���úõ����飬Ѱ�Һ�ɫ����
		if(L[j]==1)	//�ҵ�һ����ɫ����
		{
			if(j!=i)	//�ҵ��ĺ�ɫ���鲻����һ����ɫ����Ӧ�÷ŵ�λ����λ
			{
				x=L[j];
				L[j]=L[i];
				L[i]=x;
			}
			i++;	//iָ����һ����ɫ����Ӧ�÷ŵ�λ��
		}
	/* �˳�ǰ��ѭ����iָ���һ����ɫ����Ӧ�÷ŵ�λ�� */
	for(j=i;j<n;j++)	//jɨ��������δ���úõ����飬Ѱ�Ұ�ɫ����
		if(L[j]==2)	//�ҵ�һ����ɫ����
		{
			if(j!=i)
			{
				x=L[j];
				L[j]=L[i];
				L[i]=x;
			}
			i++;	//iָ����һ����ɫ����Ӧ�÷ŵ�λ��
		}
}
/* ���㷨9.15�� �����������������㷨2���������� */
void Sort(int L[],int n)
/* ������ɫ���δ����L[0...n-1]�У����㷨���ÿ�������˼�룬���������а��졢�ס����������� */
{
	int x;
	int r;	//rָ���ɫ����������һ����Ԫ��ͬʱҲ�ǰ�ɫ�������ĵ�һ����Ԫ��
	int w;	//wָ���ɫ����������һ����Ԫ��ͬʱҲ�൱�ڿ��������е�lowָ�룩
	int b;	//bָ����ɫ��������ǰһ����Ԫ��ͬʱҲ�൱�ڿ��������е�highָ�룩
	r=w=0;	//�൱��low=0
	b=n-1;	//�൱��high=n-1
	while(w<=b)
	{
		x=L[w];
		if(x==1)	//L[w]�Ǻ�ɫ���飬�����ڰ�ɫ����������һ����Ԫ
		{
			L[w]=L[r];	//L[r]�ǵ�һ����ɫ���飬�����Ƶ���ɫ���������
			w++;	//wָ���ɫ����������һ����Ԫ
			L[r]=x;	//����ɫ����x�ŵ���ɫ����������һ����Ԫ
			r++;	//rָ���ɫ����������һ����Ԫ
		}
		else if(x==2)	//L[w]�ǰ�ɫ���飬����ǡ���ڰ�ɫ����������һ����Ԫ
			w++;	//wָ���ɫ����������һ����Ԫ
		else	//L[w]����ɫ����
		{
			L[w]=L[b];	//bָ����ɫ��������ǰһ����Ԫ����L[b]��L[w]����
			L[b]=x;
			b--;	//bָ����ɫ��������ǰһ����Ԫ
		}
	}
}
