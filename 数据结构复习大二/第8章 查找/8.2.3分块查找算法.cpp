#include <stdio.h>
struct index    //定义块的结构
{
    int key;    //块的关键字
    int start;    //块的起始值
    int end;    //块的结束值
}index_table[4];    //定义结构体数组

int block_search(int key,int a[])    //自定义实现分块查找
{
    int i,j;
    i=1;
    while(i<=3&&key>index_ta
