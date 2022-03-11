/* ≤Â»Î¿‡≈≈–Ú */

/* ÷±Ω”≤Â»Î≈≈–Ú */
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
/* ’€∞Î≤Â»Î≈≈–Ú */
void BinSort(RecordType r[],int length)
{
	for(i=2;i<=length;i++)
	{
		x=r[i];
		low=1; high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(x.key<r[mid].key) high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>=low;--j) r[j+1]=r[j];
		r[mid]=x;
	}
}
/* œ£∂˚≈≈–Ú */
void ShellInsert(RecordType r[],int length,int delta)
{
	for(i=1+delta;i<=length;i++)
		if(r[i].key<r[i-delta].key)
		{
			r[0]=r[i];
			for(j=i-delta;j>0 && r[0].key<r[j].key;j-=delta)
				r[j+delta]=r[j];
			r[j+delta]=r[0];
		}
}
void ShellSort(RecordType r[],int length,int delta[],int n)
{
	for(i=0;i<n;i++)
		ShellInsert(r,length,delta[i]);
}
