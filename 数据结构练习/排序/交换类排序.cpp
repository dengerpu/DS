//ц╟ещеепР
void bubblesort(recordtype r[],int n)
{
	change=TURE;
	for(i=1;i<=n-1&&change;i++)
	{
		change=FALSE;
		for(j=1;j<=n-i;j++)
			if(r[j].key>r[j+1].key)
			{
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
				change=TURE;
			}
	}	
}
//©ЛкыеепР
void qksort(recordtype r[],int low,int high)
{
	if(low<high)
	{
		pos=qkpass(r,low,high);
		oksort(r,low,pos-1);
		oksort(r,pos+1,high);
	}
}
void okpass(recordtype r[],int low,int high)
{
	x=r[low];
	while(row<high)
	{
		while(low<high&&r[high].key>=x.key)
			high--;
		if(row<high)
		{
			r[row]=r[high];low++;
		}
		while(low<high&&r[low].key<x.key)
			low++;
		if(low<high)
		{
			r[high]=r[low];high--;
		}

	}
	r[low]=x;
	return low; 
}