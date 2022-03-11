 /* 交换类排序 */
//冒泡排序
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<n-i;j++)
			if(r[j].key>r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<n-i;j++)
			if(r[j].key>r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
//冒泡排序
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<n-i;j++)
			if(r[j].key<r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
//快速排序
void QKSort(RecordType r[],int low,int high)
{
	if(low<high)
	{
		pos=QKPass(r,low,high);
		QKSort(r,low,pos-1);
		QKSort(r,pos+1,high);
	}
}
int QKPass(RecordType r[],int low,int high)
{
	x=r[low];
	while(low<high)
	{
		while(low<high && r[high].key>=x.key) high--;
		if(low<high) { r[low]=r[high]; low++; }
		while(low<high && r[low].key<x.key) low++;
		if(low<high) { r[high]=r[low]; high--; }
	}
	r[low]=x;
	return low;
}
//快速排序
void QKSort(RecordType r[],int low,int high)
{
	if(low<high)
	{
		pos=QKPass(r,low,high);
		QKSort(r,low,pos-1);
		QKSort(r,pos+1,high);
	}
}
void QKPass(RecordType r[],int low,int high)
{
	x=r[low];
	while(low<high)
	{
		while(low<high && r[high].key>=x.key) high--;
		if(low<high) { r[low]=r[high]; low++; }
		while(low<high && r[low].key<x.key) low++;
		if(low<high) { r[high]=r[low]; high--; }
	}
	r[low]=x;
	return low;
}
//快速排序
void QKSort(RecordType r[],int low,int high)
{
	if(low<high)
	{
		pos=QKPass(r,low,high);
		QKSort(r,low,pos-1);
		QKSort(r,pos+1,high);
	}
}
void QKPass(RecordType r[],int low,int high)
{
	x=r[low];
	while(low<high)
	{
		while(low<high && r[high].key>=x.key) high--;
		if(low<high) { r[low]=r[high]; low++; }
		while(low<high && r[low].key<x.key) low++;
		if(low<high) { r[high]=r[low]; high--; }
	}
	r[low]=x;
	return low;
}
//选择排序
//简单选择排序
void SelectSort(RecordType r[],int n)
{
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
			if(r[j].key<r[k].key)
				k=j;
		if(k!=i)
		{ x=r[i]; r[i]=r[k]; r[k]=x; }
	}
}
//树形选择排序
//重建堆过程
void sift(RecordType r[],int k,int m)
{
	t=r[k];	//暂存“根”记录r[k]
	x=r[k].key;
	i=k;
	j=2*i;
	finished=FALSE;
	while(j<=m && !finished)
	{
		if(j+1<=m && r[j].key<r[j+1].key) j=j+1;
		if(x>=r[j].key) finished=TRUE;
		else
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}
	}
	r[i]=t;
}
//直接插入排序
void InsSort(RecordType r[],int length)
{
	for(i=2;i<=length;i++)
	{
		r[0]=r[i]; j=i-1;
		while(r[0].key<r[j].key)
		{ r[j+1]=r[j]; j=j-1; }
		r[j+1]=r[0];
	}
}
//直接插入排序
void InsSort(RecordType r[],int length)
{
	for(i=2;i<=length;i++)
	{
		r[0]=r[i]; j=i-1;
		while(r[0].key<r[j].key)
		{ r[j+1]=r[j]; j=i-1; }
		r[j+1]=r[j];
	}
}
//折半插入排序
void BinSort(RecordType r[],int length)
{
	for(i=2;i<=length;i++)
	{
		x=r[i];
		low=1;high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(x.key<r[mid].key) high=mid-1;
			else low=mid+1；
		}
		for(j=i-1;j>=low;j--)
			r[j+1]=r[j];
		r[low]=x;	//r[j+1]=x;
	}
}
//希尔排序
void ShellInsert(RecordType r[],int length,int delta)
{
	for(i=1+delta;i<=length;i++)
	{
		if(r[i].key<r[i-delta].key)
		{
			r[0]=r[i];
			for(j=i-delta;j>0 && r[0].key<r[j].key;j-=delta)
				r[j+delta]=r[j];
			r[j+delta]=r[0];
		}
	}
}
void ShellSort(RecordType r[],int length,int delta[],int n)
{
	for(i=0;i<n;i++)
		ShellInsert(r,length,delta[i]);
}
//希尔排序
void ShellInsert(RecordType r[],int length,int delta)
{
	for(i=1+delta;i<=length;i++)
	{
		if(r[i].key<r[i-delta].key)
		{
			r[0]=r[i];
			for(j=i-delta;j>0; && r[0].key<r[j].key;j-=delta)
				r[j+delta]=r[j];
			r[j+delta]=r[0];
		}
	}
}
void ShellSort(RecordType r[],int length,int delta[],int n)
{
	for(i=0;i<n;i++)
		ShellInsert(r,length,delta[i]);
}
//希尔排序
void ShellInsert(RecordType r[],int length,int delta)
{
	for(i=1+delta;i<=length;i++)
	{
		if(r[i].key<r[i-delta].key)
		{
			r[0]=r[i];
			for(j=i-delta;j>0 && r[0].key<r[j].key;j-=delta)
				r[j+delta]=r[j];
			r[j+delta]=r[0];
		}
	}
}
void ShellSort(RecordType r[],int length,int delta[],int n)
{
	for(i=0;i<n;i++)
		ShellInsert(r,length,delta[i]);
}
//交换类排序
//冒泡排序
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<=n-i;i++)
			if(r[j].key>r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<=n-i;j++)
			if(r[j].key<r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<=n-i;j++)
			if(r[j].key<r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<=n-i;j++)
			if(r[j].key<r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<=n-i;j++)
			if(r[j].key<r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<=n-i;j++)
			if(r[j].key<r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
void BubbleSort(RecordType r[],int n)
{
	change=TRUE;
	for(i=1;i<n && change;i++)
	{
		change=FALSE;
		for(j=1;j<=n-i;j++)
			if(r[j].key<r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TRUE;
			}
	}
}
//快速排序
void QKSort(RecordType r[],int low,int high)
{
	if(low<high)
	{
		pos=QKPass(r,low,high);
		QKSort(r,low,pos-1);
		QKSort(r,pos+1,high);
	}
}
//一趟快速排序算法
int QKPass(RecordType r[],int low,int high)
{
	x=r[low];	//选择基准记录
	while(low<high)
	{
		while(low<high && r[high.key]>=x.key) high--;
		if(low<high) { r[low]=r[high]; low++; }
		while(low<high && r[low].key<x.key) low++;
		if(low<high) { r[high]=r[low]; high--; }
	}
	r[low]=x;
	return low;
}
//快速排序
void QKSort(RecordType r[],int low,int high)
{
	if(low<high)
	{
		pos=QKPass(r,low,high);
		QKSort(r,low,pos-1);
		QKSort(r,pos+1,high);
	}
}
int QKPass(RecordType r[],int low,int high)
{
	x=r[low];
	while(low<high)
	{
		while(low<high && r[high].key>=x.key) high--;
		if(low<high) { r[low]=r[high]; low++; }
		while(low<high && r[low].key<x.key) low++;
		if(low<high) { r[high]=r[low]; high--; }
	}
	r[low]=x;
	return low;
}
//选择排序
//简单选择排序
void SelectSort(RecordType r[],int n)
{
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
			if(r[j].key<r[k].key) k=j;
		if(k!=i)
		{
			x=r[i];
			r[i]=r[k];
			r[k]=x;
		}
	}
}
void SelectSort(RecordType r[],int n)
{
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
			if(r[j].key<r[k].key) k=j;
		if(k!=i)
		{
			x=r[i];
			r[i]=r[k];
			r[k]=x;
		}
	}
}
//堆排序
//重建堆过程
void sift(RecordType r[],int k,int m)
{
	t=r[k];
	x=r[k].key;
	i=k;
	j=2*i;
	finished=FALSE;
	while(j<=m && !finished)
	{
		if(j+1<=m && r[j].key<r[j+1].key) j=j+1;
		if(x>r[j].key) finished=TRUE;
		else
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}
	}
	r[i]=t;
}
//建初堆算法
void crt_heap(RecordType r[],int n)
{
	for(i=n/2;i>=1;i--)
		sift(r,i,n);
}
//重建堆过程
void sift(RecordType r[],int k,int m)
{
	t=r[k];
	x=r[k].key;
	i=k;
	j=2*i;
	finished=FALSE;
	while(j<=m && !finished)
	{
		if(j+1<=m && r[j].key<r[j+1].key) j=j+1;
		if(x.key>=r[j].key) finished=TRUE;
		else
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}
	}
	r[i]=t;
}
//建初堆算法
void ctr_heap(RecordType r[],int n)
{
	for(i=n/2;i>=1;i--)
		sift(r,i,n);
}
//堆排序重建
void sift(RecordType r[],int k,int m)
{
	t=r[k];
	x=r[k].key;
	i=k;
	j=2*k;
	finished=FALSE;
	while(j<=m && !finished)
	{
		if(j+1<=m && r[j].key<r[j+1].key) j=j+1;
		if(x>=r[j].key) finished=TRUE;
		else
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}
	}
	r[i]=t;
}
//建初堆
void crt_heap(RecordType r[],int n)
{
	for(i=n/2;i>=1;i--)
		sift(r,i,n);
}
//堆排序算法
void HeapSort(RecordType r[],int n)
{
	crt_heap(r,n);
	for(i=n;i>=2;i--)
	{
		b=r[1];	//将堆顶记录和堆尾记录进行互换
		r[1]=r[i];
		r[i]=b;
		sift(r,1,i-1);	//进行调整，使r[1..i-1]变成堆
	}
}
//堆排序算法
void HeapSort(RecordType r[],int n)
{
	crt_heap(r,n);
	for(i=n;i>=2;i--)
	{
		b=r[1];
		r[1]=r[i];
		r[i]=b;
		sift(r,1,i-1);
	}
}