#include <stdio.h>
struct index    //�����Ľṹ
{
    int key;    //��Ĺؼ���
    int start;    //�����ʼֵ
    int end;    //��Ľ���ֵ
}index_table[4];    //����ṹ������

int block_search(int key,int a[])    //�Զ���ʵ�ַֿ����
{
    int i,j;
    i=1;
    while(i<=3&&key>index_ta
