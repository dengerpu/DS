//�鲢�㷨
void merge(recordtype r1[],int low,int mid,int high,recordtype r2[])   //r1[low..mid]��r1[mid+1..high]�ֱ𰴹ؼ����������У������Ǻϲ���һ���������У������r2[low..high];
{
	int i,j,k;
	i=low;j=mid+1;k=low;
	while(i<=mid&&j<=high)
	{
		if(r1[i].key<=r1[j].key)
		{r2[k]=r1[i];i++;}
		else	
		{r2[k]=r1[j];j++;}		
		k++;
	}
	while(i<=mid)
	{r2[k]=r1[i];k++;i++;}
	while(j<=high)
	{r2[k]=r2[j];k++;j++;}	
}
void msort(recordtype r1[],int low,int high,recordtype r3[])   //r1[low..high]��������r3[low..high]�У�r2[low..high]Ϊ�����ռ�
{
	recordtype *r2;
	r2=(recordtype *)malloc(sizeof(recordtype)*(high-low+1));
	if(low==high)r3[low]=r1[low];
	else
	{
		mid=(high+low)/2;
		msort(r1,low,mid,r2);
		msort(r1,mid+1,high,r2);
		merge(r2,low,mid,high,r3);
	}
	free(r2);
}
void mergesort(recordtype r[],int n)
{
	msort(r,1,n,r);
}