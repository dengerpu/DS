typedef struct
{
	int key;
}recordtype;
//÷±Ω”≤Â»Î≈≈–Ú
void inssort(recordtype r[],int length)
{
	for(int i=2;i<=length;i++)
	{
		r[0]=r[i];j=i-1;
		while(r[0].ley<r[j].key)
		{
			r[j+1]=r[j];
			j=j-1;
		}
		r[j+1]=r[0];
	}
}
//’€∞Î≤Â»Î≈≈–Ú
void binsort(recordtype r[],int length)
{
	int x,low,high;
	for(int i=2;i<=length;i++)
	{
		x=r[i];
		low=1,high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(x.key<r[mid].key)high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>=low;--j) r[j+1]=r[j];
		r[low]=x;
	}
}
//œ£∂˚≈≈–Ú
void shellinsert(recordtype r[],int length,int delta)
{
	for(i=1+delta;i<=length;i++)
	{
		if(r[i].key<r[i-delta].key)
		{
			r[0]=r[i];
			for(j=i-delta;j>0&&r[0].key<r[j].key;j-=delta)
				r[j+delta]=r[j];
			r[j+delta]=r[0];
		}
	}
}
void shellsort(recordtype r[],int length,int delta[],int n)
{
	for(i=0;i<=n-1;i++)
		shellinsert(r,length,length,delta[i]);
}