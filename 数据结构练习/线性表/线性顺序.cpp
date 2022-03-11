#define max 1024;
typedf struct
{
	int a[max];
	int length;
}list;
listinsert(list *l,int i.int e)
{
	int i;
	if(i<1||i>length)
		return flase;
	if(length>max)
		return flase;
	for(j=length;j>=i;j--)
		a[j]=a[j-1];
	a[i-1]=e;
	length++;
	return ture;
}
