/* 向量结构定义 */
typedef int KeyType;
typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;
/* 【算法9.1】 直接插入法 */
void InsSort(RecordType r[],int length)
/* 对记录数组r做直接插入排序，length为数组中待排序记录的数目 */
{
	for(i=2;i<=length;i++)
	{
		r[0]=r[i]; j=i-1;	//将待插入记录存放到监视哨r[0]中
		while(r[0].key<r[j].key)	//寻找插入位置
		{ r[j+1]=r[j]; j=j-1; }
		r[j+1]=r[0];	//将待插入记录插入到已排序的序列中
	}
}
/* 【算法9.2】 折半插入排序 */
void BinSort(RecordType r[],int length)
/* 对记录数组r进行折半插入排序，length为数组的长度 */
{
	for(i=2;i<=length;++i)
	{
		x=r[i];
		low=1; high=i-1;
		while(low<=high)	//确定插入位置
		{
			mid=(low+high)/2;
			if(x.key<r[mid].key)
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=low;--j)
			r[j+1]=r[j];	//记录依次向后移动
		r[low]=x;	//插入记录
	}
}
/* 【算法9.3】 希尔排序 */
void ShellInsert(RecordType r[],int length,int delta)
/* 对记录数组r做一趟希尔插入排序，length为数组的长度，delta为增量 */
{
	for(i=1+delta;i<=length;i++)	//1+delta为第一个子序列的第二个元素下标
		if(r[i].key<r[i-delta].key)
		{
			r[0]=r[i];	//备份r[i]（不做监视哨）
			for(j=i-delta;j>0 && r[0].key<r[j].key;j-=delta)
				r[j+delta]=r[j];
			r[j+delta]=r[0];
		}
}	//ShellInsert
void ShellSort(RecordType r[],int length,int delta,int n)
/* 对记录数组r做希尔排序，length为数组r的长度，delta为增量数组，n为delta[]的长度 */
{
	for(i=0;i<=n-1;++i)
		ShellInsert(r,length,delta[i]);
}
/* 【算法9.4】 冒泡排序法 */
void BubbleSort(RecordType r[],int n)
/* 对记录数组r做冒泡排序，n数组的长度 */
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
/* 【算法9.5】 完整的快速排序算法 */
void QKSort(RecordType r[],int low,int high)
/* 对记录数组r[low...high]用快速排序算法进行排序 */
{
	if(low<high)
	{
		pos=QKPass(r,low,high);	//调用一趟快速排序，以枢轴元素为界划分两个子表
		OKSort(r,low,pos-1);	//对左部子表快速排序
		QKSort(r,pos+1,high);	//对右部子表快速排序
	}
}
/* 【算法9.6】 一趟快速排序算法 */
int QKPass(RecordType r[],int low,int high)
/* 用基准记录对r[low]至r[high]部分进行一趟快速排序（划分），并得到基准记录的新位置，使得基准记录之前所有记录的关键字，
而基准记录之后所有记录的关键字均大于或等于基准记录的关键字 */
{
	x=r[low];	//选择基准记录
	while(low<high)
	{
		while(low<high && r[high].key>=x.key)
			high--;	//high从右到左找小于x.key的记录
		if(low<high) { r[low]=r[high]; low++; }	//找到小于x.key的记录，则送入“空单元”r[low]
		while(low<high && r[low].key<x.key)
			low++;	//low从左到右找大于或等于x.key的记录
		if(low<high) { r[high]=r[low]; high--; }	//找到大于x.key的记录，则送入“空单元”r[high]
	}
	r[low]=x;	//将基准记录保存到low=high的位置
	return low;	//返回基准记录的位置
}
/* 【算法9.7】 简单选择排序 */
void SelectSort(RecordType r[],int n)
/* 对记录数组r做简单选择排序，n为数组的长度 */
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
/* 【算法9.8】 重建堆过程 */
void sift(RecordType r[],int k,int m)
/* 假设r[k...m]是以r[k]为根的完全二叉树，且分别以r[2*k]和r[2*k+1]为根的左、右子树为大根堆，调整r[k]，使整个序列r[k...m]满足堆的性质 */
{
	t=r[k];	//暂存“根”记录r[k]
	x=r[k].key;
	i=k;
	j=2*i;
	finished=FALSE;
	while(j<=m && !finished)
	{
		if(j+1<=m && r[j].key<r[j+1].key)
			j=j+1;	//若存在右子树，且右子树根的关键字大，则沿右分支“筛选”
		if(x>=r[j].key)
			finished=TRUE;	//筛选完毕
		else
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}	//继续筛选
	}
	r[i]=t;	//r[k]填入到恰当的位置
}
/* 【算法9.9】 建初堆算法 */
void crt_heap(RecordType r[],int n)
/* 对记录数组r建堆，n的数组的长度 */
{
	for(i=n/2;i>=1;--i)	//自第[n/2]个记录开始进行筛选建堆
		sift(r,i,n);
}
/* 【算法9.10】 堆排序算法 */
void HeapSort(RecordType r[],int n)
/* 对r[1...n]进行堆排序，执行本算法后，r中记录按关键字由小到大有序排列 */
{
	crt_heap(r,n);
	for(i=n;i>=2;--i)
	{
		b=r[1];	//将堆顶记录和堆尾记录互换
		r[1]=r[i];
		r[i]=b;
		sift(r,1,i-1);	//进行调整，使r[1...i-1]变成堆
	}
}	//HeapSort
/* 【算法9.11】 相邻两个有序子序列的合并成算法 */
void Merge(RecordType r1[],int low,int mid,int high,RecordType r2[])
/* 已知r1[low...mid]和r1[mid+1...high]分别按关键字有序排列，将它们合并成一个有序序列，存放在r2[low...high] */
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
/* 【算法9.12】 2-路归并排序的递归算法 */
void NSort(RecordType r1[],int low,int high,RecordType r3[])
/* r1[low...high]排序后放在r3[low...high]中，r2[low...high]为辅助空间 */
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
/* 【算法9.13】 2-路归并排序的初始调用过程 */
void MergeSort(RecordType r[],int n)
/* 对记录数组r[1...n]做归并排序 */
{
	MSort(r,1,n,r);
}
/* 分配类排序静态链表数据类型定义如下 */
#define RADIX 10
#define KEY_SIZE 6
#define LIST_SIZE 20
typedef int KeyTYpe;
typedef struct
{
	KeyType keys[KEY_SIZE];	//子关键字数组
	OtherType other_data;	//其他数据项
	int next;	//静态链域
}RecordType;
typedef struct
{
	RecordType r[LIST_SIZE+1];	//r[0]为头结点
	int length;
	int keynum;
}SLinkList;	//静态链表
typedef int PVector[RADIX];
/* 【算法9.14】 链式基数排序算法 */
void Distribute(RecordType r[],int i,PVector head,PVector tail)
/* 记录数组r中记录已按低位关键字key[i+1]，...，key[d]进行过“低位优先”排序。本算法按第i位关键字key[i]建立RADIX个队列，
同一个队列中记录的key[i]相同。head[j]和tail[j]分别指向各队列中第一个和最后一个记录（j=0,1,2，...，RADIX-1）。head[j]=0
表示相应队列为空队列 */
{
	for(j=0;j<=RADIX-1;++j)
		head[j]=0;	//将RADIX个对列初始化为空队列
	p=r[0].next;	//p指向链表中的第一个记录
	while(p!=0)
	{
		j=Order(r[p].key[i]);	//用记录中第i位关键字求相应队列号
		if(head[j]==0) head[j]=p;	//将p所指向的结点加入第i个队列中
		else r[tail[j]].next=p;
		tail[j]=p;
		p=r[p].next;
	}
}	/* Distribute */
void Collect(RecordType r[],PVector head,PVector tail)
/* 本算法从0到RADIX-1扫描各对列，将所有非空队列首尾相接，重新链接成一个链表 */
{
	j=0;
	while(head[j]==0) ++j;	//找第一个非空队列
	r[0].next=head[j]; t=tail[j];
	while(j<RADIX-1)
	{
		++j;
		while(j<RADIX-1) && (head[j]==0)) ++j;	//找下一个非空队列
		if(head[j]!=0)	//链接非空队列
		{ r[t].next=head[j]; t=tail[j]; }
	}
	r[t].next=0;	//t指向最后一个非空队列中的最后一个结点
}	/* Collect */
void RadixSort(RecordType r[],int n,int d)
/* n个记录存放在数组r中，d为关键字位数，执行本算法进行基数排序后，链表中的记录将按关键字从小到大的顺序相连接 */
{
	n=length;
	for(i=0;i<=n-1;++i) r[i].next=i+1;	//构造静态链表
	r[n].next=0;
	for(i=d-1;i>=0;--i)	//从最低位子关键字开始，进行d趟分配和收集
	{
		Distribute(r,i,head,tail);	//第i趟分配
		Collect(r,head,tail);	//第i趟收集
	}
}	//RadixSort
/* 【算法9.15】 解决荷兰国旗问题的算法1（简单选择排序） */
/* 条块颜色依次存放在L[0...n-1]中，本算法利用简单选择排序思想，将整个序列按红、白、蓝进行排序 */
{
	int i,j,x;
	i=0;	//i指向第一个红色条块应该放的位置
	for(j=i;j<n;j++)	//j扫描所有尚未放置好的条块，寻找红色条块
		if(L[j]==1)	//找到一个红色条块
		{
			if(j!=i)	//找到的红色条块不在下一个红色条块应该放的位置则换位
			{
				x=L[j];
				L[j]=L[i];
				L[i]=x;
			}
			i++;	//i指向下一个红色条块应该放的位置
		}
	/* 退出前面循环后，i指向第一个白色条块应该放的位置 */
	for(j=i;j<n;j++)	//j扫描所有尚未放置好的条块，寻找白色条块
		if(L[j]==2)	//找到一个白色条块
		{
			if(j!=i)
			{
				x=L[j];
				L[j]=L[i];
				L[i]=x;
			}
			i++;	//i指向下一个白色条块应该放的位置
		}
}
/* 【算法9.15】 解决荷兰国旗问题的算法2（快速排序） */
void Sort(int L[],int n)
/* 条块颜色依次存放在L[0...n-1]中，本算法利用快速排序思想，将整个序列按红、白、蓝进行排序 */
{
	int x;
	int r;	//r指向红色条块区的下一个单元（同时也是白色条块区的第一个单元）
	int w;	//w指向白色条块区的下一个单元（同时也相当于快速排序中的low指针）
	int b;	//b指向蓝色条块区的前一个单元（同时也相当于快速排序中的high指针）
	r=w=0;	//相当于low=0
	b=n-1;	//相当于high=n-1
	while(w<=b)
	{
		x=L[w];
		if(x==1)	//L[w]是红色条块，并且在白色条块区的下一个单元
		{
			L[w]=L[r];	//L[r]是第一个白色条块，将其移到白色条块区最后
			w++;	//w指向白色条块区的下一个单元
			L[r]=x;	//将红色条块x放到红色条块区的下一个单元
			r++;	//r指向红色条块区的下一个单元
		}
		else if(x==2)	//L[w]是白色条块，并且恰好在白色条块区的下一个单元
			w++;	//w指向白色条块区的下一个单元
		else	//L[w]是蓝色条块
		{
			L[w]=L[b];	//b指向蓝色条块区的前一个单元，将L[b]与L[w]交换
			L[b]=x;
			b--;	//b指向蓝色条块区的前一个单元
		}
	}
}
