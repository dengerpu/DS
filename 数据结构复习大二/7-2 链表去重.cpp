#include<stdio.h>
#include<malloc.h>
#include<math.h>					//����fabs();����ֵ�������õ�
#include<string.h>
#define max 10000
typedef struct node
{
	char firstaddress[5];				//�׵�ַ
	int data;
	char endaddress[5];					//β��ַ
	struct node *next;
}*Linklist,Node;
typedef struct node1				//����ṹ������������������
{
	char a[5];							//�׵�ַ
	int data1;
	char b[5];									//β��ַ
	int flag;										//��������Ƿ�ѡ��
}array[max];
void enter(array v,int n)								//��������
{
	for(int i=0;i<n;i++)
	{
		int temp;
		temp=scanf("%s%d%s",v[i].a,&v[i].data1,v[i].b);
		v[i].flag=0;
	}
}
void creat(Linklist L,char address[],int n,array v)
{
	Linklist p,s;
	p=L;
	int x=n,i;
	while(x!=0)
	{
		for(i=0;i<n;i++)
		{
			if(v[i].flag==0)
			{
				if(strcmp(v[i].a,address)==0)
				{
					s=(Linklist)malloc(sizeof(Node));
					s->data=v[i].data1;
					strcpy(s->firstaddress,v[i].a);
					strcpy(s->endaddress,v[i].b);
					p->next=s;
					p=s;
					p->next=NULL;
					strcpy(address,v[i].b);
					v[i].flag=1;
				}
			}
		}
			x--;
	}
	
}
void quchong(Linklist L,Linklist a,Linklist b)				//a�洢ȥ�غ�����ݣ��洢ɾȥ����ȥ
{
    Linklist p,q,s,c,l;int sign=0;
	s=a;p=L->next ;c=b;
	while(p!=NULL)
	{
		q=(Linklist)malloc(sizeof(Node));					//qΪ��������
		q->data =p->data ;
		strcpy(q->firstaddress,p->firstaddress);
		strcpy(q->endaddress ,p->endaddress );
		s->next =q;
		s=q;
		s->next =NULL;
		p=p->next ;	
		if(p!=NULL)
		{
			l=a->next;
			while(l!=NULL)
			{
				if(fabs(p->data )==fabs(l->data ))			//��һ�����У�L�����е�һ�����Ѿ�����a�У�L�ڶ�����Ҫ��a�е����Ƚϣ�����ظ�����b�У����ظ�����a��
				{
					sign=1;
					q=(Linklist)malloc(sizeof(Node));		//qΪ��������
					q->data =p->data ;
					if(p->next !=NULL)
						strcpy(l->endaddress ,p->next->firstaddress );    //���ظ�����β��ַ������һ����					
					strcpy(q->firstaddress,p->firstaddress);
					if(p->next!=NULL)
						strcpy(q->endaddress ,p->next->endaddress );
					else
						strcpy(q->endaddress,"-1");
					c->next =q;
					c=q;
					c->next =NULL;
				}
				l=l->next ;
			}
		}	
		if(sign==1)
			{
				p=p->next ;
				sign=0;
			}
		
	}
	strcpy(s->endaddress ,"-1");
	
	
}
void print(Linklist L)    //�������
{
	Linklist p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%s %d %s\n",p->firstaddress,p->data,p->endaddress);
		p=p->next;
	}
}
int main()
{
	int n;
	char firstaddress[5];
	Linklist L,a,b;
	array v;
	L=(Linklist)malloc(sizeof(Node));
	a=(Linklist)malloc(sizeof(Node));
	b=(Linklist)malloc(sizeof(Node));
	int temp;
	temp=scanf("%s %d",firstaddress,&n);					//�����׵�ַ��Ҫ������������
	enter(v,n);	
    creat(L,firstaddress,n,v);
	quchong(L,a,b);	
	print(a);
	print(b);
	return 0;
}