 /* ���������� */
//ð������
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
//ð������
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
//��������
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
//��������
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
//��������
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
//ѡ������
//��ѡ������
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
//����ѡ������
//�ؽ��ѹ���
void sift(RecordType r[],int k,int m)
{
	t=r[k];	//�ݴ桰������¼r[k]
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
//ֱ�Ӳ�������
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
//ֱ�Ӳ�������
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
//�۰��������
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
			else low=mid+1��
		}
		for(j=i-1;j>=low;j--)
			r[j+1]=r[j];
		r[low]=x;	//r[j+1]=x;
	}
}
//ϣ������
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
//ϣ������
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
//ϣ������
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
//����������
//ð������
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
//��������
void QKSort(RecordType r[],int low,int high)
{
	if(low<high)
	{
		pos=QKPass(r,low,high);
		QKSort(r,low,pos-1);
		QKSort(r,pos+1,high);
	}
}
//һ�˿��������㷨
int QKPass(RecordType r[],int low,int high)
{
	x=r[low];	//ѡ���׼��¼
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
//��������
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
//ѡ������
//��ѡ������
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
//������
//�ؽ��ѹ���
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
//�������㷨
void crt_heap(RecordType r[],int n)
{
	for(i=n/2;i>=1;i--)
		sift(r,i,n);
}
//�ؽ��ѹ���
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
//�������㷨
void ctr_heap(RecordType r[],int n)
{
	for(i=n/2;i>=1;i--)
		sift(r,i,n);
}
//�������ؽ�
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
//������
void crt_heap(RecordType r[],int n)
{
	for(i=n/2;i>=1;i--)
		sift(r,i,n);
}
//�������㷨
void HeapSort(RecordType r[],int n)
{
	crt_heap(r,n);
	for(i=n;i>=2;i--)
	{
		b=r[1];	//���Ѷ���¼�Ͷ�β��¼���л���
		r[1]=r[i];
		r[i]=b;
		sift(r,1,i-1);	//���е�����ʹr[1..i-1]��ɶ�
	}
}
//�������㷨
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