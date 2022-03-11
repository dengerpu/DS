typedef struct stact
{
	int a[100];
	int top[2];
}*seqstact;
void insert_stact()
{
	seqstact l;
	if(l->top[0]+1==l->top[1])
	{
		printf("Õ»Âú\n");
		exit(0);
	}
	switch(i)
	{
	case 0:l->top[0]++;
		l->a[top[0]]=n;
		break;
	case 1:l->top[1]--;
		l->a[top[1]]=n;
		break;
	default:
		return 0;
	}
}
void dele(seqstact)
{
	switch(i)
	{
	case 0:l->top[0]--;break;
	case 1:l->top[1]++;break;
	default :return 0;
	}
	
}

