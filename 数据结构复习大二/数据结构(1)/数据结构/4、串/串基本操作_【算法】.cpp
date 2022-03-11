/* ˳�򴮽ṹ���� */
#define MAXLEN 50
typedef struct	/* ���ṹ���� */
{
	char ch[MAXLEN];
	int len;
}SString;
/* ���㷨4.1�� ˳�򴮲��뺯�� */
int StrInsert(SString * s,int pos,SString t)
/* �ڴ�S���±�Ϊpos���ַ�֮ǰ���봮t */
{
	int i;
	if(pos<0||pos>s->len)	/* ����λ�ò��Ϸ� */
		return 0;	
	if(s->len+t.len<=MAXLEN)	/* ���봮��<=MAXLEN */
	{
		for(i=s->len+t.len-1;i>=t.len+pos;i--)
			s->ch[i]=s->ch[i-t.len];
		for(i=0;i<t.len;i++)
			s->ch[i+pos]=t.ch[i];
		s->len=s->len+t.len;
	}
	else if(pos+t.len<=MAXLEN)	/* ����󴮳�>MAXLEN������t���ַ����п���ȫ������ */
	{
		for(i=MAXLEN-1;i>t.len+pos-1;i--)
			s->ch[i]=s->ch[i-t.len];
		for(i=0;i<t.len;i++)
			s->ch[i+pos]=t.ch[i];
		s->len=MAXLEN;
	}
	else	/* ����󴮳�>MAXLEN�����Ҵ�t�Ĳ����ַ�ҲҪ���� */
	{
		for(i=0;i<MAXLEN-pos;i++)
			s->ch[i+pos]=t.ch[i];
		s->len=MAXLEN;
	}
	return 1;
}
/* ���㷨4.2�� ˳��ɾ������ */
int StrDelete(SString * s,int pos,int len)
/* �ڴ�s��ɾ�����±�pos��len���ַ� */
{
	int i;
	if(pos<0||pos>(s->len-len))	/* ɾ���������Ϸ� */
		return 0;
	for(i=pos+len;i<s->len;i++)
		s->ch[i-pos]=s->ch[i];	/* ��pos+len��ʼ����β������ǰ�ƶ���ʵ��ɾ��len���ַ� */
	s->len=s->len-len;	/* ���ĳ��ȼ�len */
	return 1;
}
/* ���㷨4.3�� ���ȽϺ��� */
int StrCompare(SString s,SString t)
/* ����s��t����򷵻�0����s>t�򷵻���������s<t�򷵻ظ��� */
{
	int i;
	for(i=0;i<s.len&&i<t.len;i++)
		if(s.ch[i]!=t.ch[i])
			return (s.ch[i]-t.ch[i]);
		return (s.len-t.len);
}
/* ���㷨4.4�� ˳�򴮵ļ�ģʽƥ�䣨��λ������ */
int StrIndex(SString s,int pos,SString t)
/* �������s���±�pos�𣬴�t��һ�γ��ֵ�λ�ã��ɹ�����λ����ţ����ɹ�����-1 */
{
	int i,j,start;
	if(t.len==0)	/* ģʽ��Ϊ�մ�ʱ�������⴮��ƥ�䴮 */
		return 0;
	start=pos; i=start; j=0;	/* ������pos��ʼ��ģʽ����ͷ��0����ʼ */
	while(i<s.len&&j<t.len)
		if(s.ch[i]==t.ch[j])	/* ��ǰ��Ӧ���ַ����ʱ�ƽ� */
		{
			i++;
			j++;
		}
		else
		{
			start++;	/* ��ǰ��Ӧ�ַ�����ʱ���� */
			j=0;	/* ������start+1��ʼ��ģʽ����ͷ��0����ʼ */
		}
	if(j>=t.len)
		return (start);	/* ƥ��ɹ�ʱ������ƥ����ʼλ�� */
	else
		return (-1);	/* ƥ�䲻�ɹ��Ƿ���-1 */
}
/***************************************************************/
/* �Ѵ����ͽṹ���� */
typedef struct
{
	char * ch;
	int len;
}HString;
/* ���㷨4.5�� �Ѵ����뺯�� */
int StrInsert(HString * s,int pos,HString * t)
/* �ڴ�s���±�Ϊpos���ַ�֮ǰ���봮t */
{
	int i;
	char * temp;
	if(pos<0||pos>s->len||s->len==0)	/* ����λ�ò��Ϸ� */
		return 0;
	temp=(char *)malloc(s->len+t->len);	/* ��̬�����㹻�Ŀռ��Ų����Ĵ� */
	if(temp==NULL)
		return 0;
	for(i=0;i<pos;i++)
		temp[i]=s->ch[i];
	for(i=0;i<t->len;i++)
		temp[i+pos]=t->ch[i];
	for(i=pos;i<s->len;i++)
		temp[i+t->len]=s->ch[i];
	s->len+=t->len;
	free(s->ch);
	s->ch=temp;
	return 1;
}
/* ���㷨4.6�� �Ѵ���ֵ���� */
int StrAssign(HString * s,char * tval)
/* ���ַ�������tval��ֵ�����Ѵ�s */
{
	int len,i=0;
	if(s->ch!=NULL)
		free(s->ch);
	while(tval[i]!='\0')
		i++;
	len=i;
	if(len)
	{
		s->ch=(char *)malloc(len);
		if(s->ch==NULL)
			return 0;
		for(i=0;i<len;i++)
			s->ch[i]=tval[i];
	}
	else
		s->ch=NULL;
	s->len=len;
	return 1;
}
/***************************************************************/
/* ���������ͽṹ���� */
#define BLOCK_SIZE 4	/* ÿ������ַ�����4 */
typedef struct Block
{
	char ch[BLOCK_SIZE];
	struct Block * next;
}Block;
typedef struct
{
	Block * head;
	Block * tail;
	int len;
}BLString;
/* ��BLOCK_SIZE����1ʱ��ÿ�������һ���ַ����ṹͬ�������������£� */
#define BLOCK_SIZE 1
typedef struct chBlock
{
	char ch;
	struct chBlock * next;
}chBlock;