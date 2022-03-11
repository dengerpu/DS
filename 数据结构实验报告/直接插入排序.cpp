#include <stdio.h>
#include <windows.h>
const int MAX_N=12000;
long KeyList[MAX_N];
int main() {
	int i,j;
	double run_time;
	_LARGE_INTEGER time_start;	//��ʼʱ��
	_LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	for(i=1;i<=MAX_N;i++)
	{
		KeyList[i]=MAX_N-i+1;	
	}
	QueryPerformanceCounter(&time_start);	//��ʱ��ʼ
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
	QueryPerformanceCounter(&time_over);	//��ʱ����
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\nֱ�Ӳ�������ʱ��Ϊ��%fus\n",run_time);
	return 0;
}