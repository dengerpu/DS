#include <stdio.h>
#include <windows.h>
const int MAX_N=12000;
long KeyList[MAX_N];
int main() {
	int i,j;
	double run_time;
	_LARGE_INTEGER time_start;	//开始时间
	_LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	for(i=1;i<=MAX_N;i++)
	{
		KeyList[i]=MAX_N-i+1;	
	}
	QueryPerformanceCounter(&time_start);	//计时开始
	for(i=2;i<=MAX_N;i++)
	{
		KeyList[0]=KeyList[i];
		j=i-1;
		while(KeyList[0]<KeyList[j])
		{
			KeyList[j+1]=KeyList[j];
			j=j-1;
		}
		KeyList[j+1]=KeyList[0];
	}
	QueryPerformanceCounter(&time_over);	//计时结束
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n直接插入排序时间为：%fus\n",run_time);
	return 0;
}