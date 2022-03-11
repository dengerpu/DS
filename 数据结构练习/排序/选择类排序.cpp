//ºÚµ•—°‘Ò≈≈–Ú
void selectsort(recordtype r[],int n)
{
	for(i=1;i<=n-1;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
			if(r[j].key<r[k].key)
				k=j;
			if(k!=i)
			{
				x=r[i];
				r[i]=r[k];
				r[k]=x;
			}
	}
}