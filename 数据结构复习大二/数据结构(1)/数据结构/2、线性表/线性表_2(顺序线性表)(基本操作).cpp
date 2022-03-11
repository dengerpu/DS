/*˳���ĳ��ò���*/
#include<stdio.h>
#include<stdlib.h>
#define INIT_SIZE 100	/*���Ա�洢�ռ�ĳ�ʼ������*/
#define INCREMENT 10	/*���Ա�洢�ռ�ķ�������*/
typedef int ElemType;	/*����Ԫ������Ϊint*/
/*���Ա�˳��洢�ṹ�Ķ���*/
typedef struct
{
	ElemType * elem;	/*�洢�ռ�Ļ���ַ*/
	int length;	/*��ǰ����*/
	int listsize;	/*��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��*/
}SqList;
/*���㷨2.1 ˳���ĳ�ʼ����*/
/*��ʼ��˳������ɹ�����1�����򷵻�0*/
int InitList_Sq(SqList *L)
{
	L->elem=(ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
	if(!L->elem)
		return -1;
	L->length=0;
	L->listsize=INIT_SIZE;
	return 1;
}
/*��ӡ˳���ĸ���Ԫ��*/
void PrintSqList(SqList L)
{
	int i;
	printf("\n�����Ա��Ԫ������Ϊ��\n");
	for(i=0;i < L.length;i++)
		printf("%d ",L.elem[i]);
	printf("\n");
}
/*����˳������Ԫ�ص�ֵ*/
void InputSqList(SqList * L)
{
	int i,n;
	printf("����������Ա��Ԫ�ظ�����n=");
	scanf("%d",&n);
	while(n>L->listsize)
	{
		printf("���������Ա�Ĵ洢�ռ䣬���������룺\n");
		scanf("%d",&n);
	}
	L->length=n;
	printf("��������������Ա��Ԫ�ص�ֵ��\n");
	for(i=0;i<n;i++)
		scanf("%d",&L->elem[i]);
}
/*���㷨2.2 ˳���Ĳ��롿*/
/*��˳���L�ĵ�i��λ��֮ǰ�����µ�Ԫ��e�����ɹ��򷵻�1�����򷵻�0*/
int ListInsert_Sq(SqList * L,int i,ElemType e)
{
	int j;
	ElemType * newbase;
	if(i<0||i>L->length)	/*����λ�ò��Ϸ�*/
		return 0;
	if(L->length >= L->listsize)	/*��ǰ�洢�ռ����������ӷ���*/
	{
		newbase=(ElemType *)realloc(L->elem,(L->listsize + INCREMENT)*sizeof(ElemType));
		if(!newbase)	/*�洢����ʧ��*/
			return 0;
		L->elem = newbase;
		L->listsize += INCREMENT;
	}
	for(j=L->length-1;j>=i;j--)
		L->elem[j+1]=L->elem[j];	/*����λ�ü�֮���Ԫ�غ���*/
	L->elem[i]=e;	/*����e*/
	++L->length;	/*����1*/
	return 1;
}
/*���㷨2.3 ˳����ɾ����*/
/*��˳���L��ɾ����i��Ԫ�أ�����e������ֵ�����ɹ��򷵻�1�����򷵻�0*/
int ListDelete_Sq(SqList * L,int i,ElemType * e)
{
	int j;
	if(i<0||i>L->length-1)	/*iֵ���Ϸ�*/
		return 0;
	* e=L->elem[i];	/*��ɾ��Ԫ�ص�ֵ����e*/
	for(j=i+1;j<=L->length-1;j++)
		L->elem[j-1]=L->elem[j];	/*��ɾԪ��֮���Ԫ��ǰ��*/
	--L->length;
	return 1;
}
/*���㷨2.4 ˳���Ĳ��ҡ�*/
/*��˳�����Ա�L�в��ҵ�i��ֵ��e��ȵ�Ԫ��λ�����ҵ����򷵻�����L�е�λ�򣬷��򷵻�0*/
int LocateElem_Sq(SqList L,ElemType e)
{
	int i=0;	/*i�ĳ�ֵΪ��һ��Ԫ�ص�λ��*/
	while(i<L.length&&L.elem[i]!=e)
		i++;
	if(L.elem[i]==e)
		return i;
	else
		return -1;
}
/*���㷨2.5 ��ȡ˳����е�Ԫ�ء�*/
/*��˳�����Ա�L��ȡ��i��Ԫ�ش���e�У����ɹ����򷵻�1�����򷵻�0*/
int Get_SqList(SqList L,int i,ElemType * e)
{
	if(i<0||i>L.length-1)	/*û�е�i��Ԫ�أ���ȡʧ��*/
		return 0;
	* e=L.elem[i];
	return 1;	/*��ȡ�ɹ�*/
}
int main()
{
	SqList L;
	int status,e,i;
	status=InitList_Sq(&L);
	if(status)
		printf("˳����ʼ���ɹ���\n");
	else
	{
		printf("˳����ʼ��ʧ�ܣ�\n");
		return 0;
	}
	InputSqList(&L);
	PrintSqList(L);
	printf("���������λ�ã�");
	scanf("%d",&i);
	status=ListInsert_Sq(&L,i,30);	/*�ڵ�i��Ԫ��֮ǰ����30*/
	if(status)
	{
		printf("���в��������");
		PrintSqList(L);
	}
	else
	{
		printf("\n����ʧ�ܣ�");
		return 0;
	}
	printf("������ɾ����λ�ã�");
	scanf("%d",&i);
	status=ListDelete_Sq(&L,i,&e);	/*ɾ�����Ա�ĵ�i��Ԫ�أ���e������ֵ*/
	if(status)
	{
		printf("\n��ɾ��Ԫ�ص�ֵΪ��%d",e);
		printf("\n����ɾ��������");
		PrintSqList(L);
	}
	else
	{
		printf("\nɾ��ʧ�ܣ�");
		return 0;
	}
	i=LocateElem_Sq(L,15);
/*��˳���L�в��ҵ�i��ֵ��15��ȵ�Ԫ�ص�λ��*/
	printf("��ֵ��15��ȵ�Ԫ�������Ա��е�λ��Ϊ��%d\n",i);
	i=LocateElem_Sq(L,36);
/*��˳���L�в��ҵ�i��ֵ��36��ȵ�Ԫ�ص�λ��*/
	printf("��ֵ��36��ȵ�Ԫ�������Ա��е�λ��Ϊ��%d\n",i);
	printf("�������ȡԪ�ص�λ�ã�");
	scanf("%d",&i);
	status=Get_SqList(L,i,&e);
	if(status)
		printf("\n��ȡ��Ӧλ�õ�Ԫ�ص�ֵΪ��%d\n",e);
	free(L.elem);
	return 0;
}