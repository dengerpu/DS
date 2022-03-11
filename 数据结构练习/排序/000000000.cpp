#include<stdio.h>
#define error 0
char fh[4]={'+','-','*','/'};
float hx(float x, float y, int fh0)
{
    switch(fh0)
    {
        case 0: return x+y;
        case 1: return x-y;
        case 2: return x*y;
        case 3: return x/y;
    }
}
float js1(float i,float j,float k,float t,int fh1,int fh2,int fh3)
{
    float r1,r2,r3;
    r1=hx(i,j,fh1);
    r2=hx(r1,k,fh2);
    r3=hx(r2,t,fh3);
    return r3;
}
float js2(float i,float j,float k,float t,int fh1,int fh2,int fh3)
{
    float r1,r2,r3;
    r1=hx(j,k,fh2);
    r2=hx(i,r1,fh1);
    r3=hx(r2,t,fh3);
    return r3;
}
float js3(float i,float j,float k,float t,int fh1,int fh2,int fh3)
{
    float r1,r2,r3;
    r1=hx(j,k,fh2);
    r2=hx(r1,t,fh3);
    r3=hx(i,r2,fh1);
    return r3;
}
float js4(float i,float j,float k,float t,int fh1,int fh2,int fh3)
{
    float r1,r2,r3;
    r1=hx(k,t,fh3);
    r2=hx(j,r1,fh2);
    r3=hx(i,r2,fh1);
    return r3;
}
float js5(float i,float j,float k,float t,int fh1,int fh2,int fh3)
{
    float r1,r2,r3;
    r1=hx(i,j,fh1);
    r2=hx(k,t,fh3);
	if(r1==0&&r2==0)
	{
		return error;
	}
	else
	{
		r3=hx(r1,r2,fh2);
		return r3;
	}
}
int get24(int i,int j,int k,int t)
{
    int fh1,fh2,fh3;
    int n=0;
    for(fh1=0;fh1<4;fh1++)
        for(fh2=0;fh2<4;fh2++)
            for(fh3=0;fh3<4;fh3++)
            {
                if(js1(i,j,k,t,fh1,fh2,fh3)==24)
                {
                    printf("((%d%c%d)%c%d)%c%d=24\n",i,fh[fh1],j,fh[fh2],k,fh[fh3],t);
                    n=1;
                }
                if(js2(i,j,k,t,fh1,fh2,fh3)==24)
                {
                    printf("(%d%c(%d%c%d))%c%d=24\n",i,fh[fh1],j,fh[fh2],k,fh[fh3],t);
                    n=1;
                }
				if(js3(i,j,k,t,fh1,fh2,fh3)==24)
                {
                    printf("%d%c((%d%c%d)%c%d)=24\n",i,fh[fh1],j,fh[fh2],k,fh[fh3],t);
                    n=1;
                }
                if(js4(i,j,k,t,fh1,fh2,fh3)==24)
                {
                    printf("%d%c(%d%c(%d%c%d))=24\n",i,fh[fh1],j,fh[fh2],k,fh[fh3],t);
                    n=1;
                }
                if(js5(i,j,k,t,fh1,fh2,fh3)==24)
                {
                    printf("(%d%c%d)%c(%d%c%d)=24\n",i,fh[fh1],j,fh[fh2],k,fh[fh3],t);
                    n=1;
                }
            }
    return n;
}
void px(int a[],int k)
{
	int i,j,m,n;
	for(i=0;i<k;i++)
		for(j=0;j<k;j++)
		{
			if(j==i)continue;
				for(m=0;m<k;m++)
				{
					if(m==i||m==j)continue;
						for(n=0;n<k;n++)
						{
							if(n==i||n==j||n==m)
								continue;
							if(get24(a[i],a[j],a[m],a[n]));
						}
				}
		}
}
int main(void)
{
	int a[4];
	int i;
	printf("请输入4个1~10范围内的整数:\n");
	loop:	for(i=0;i<4;i++)
				scanf("%d",&a[i]);
	for(i=0;i<4;i++)
		if(a[i]<1||a[i]>10)
		{
			printf("请重新输入4个1~10范围内的整数:\n");
			goto loop;
		}
	px(a,4);
    return 0;
}