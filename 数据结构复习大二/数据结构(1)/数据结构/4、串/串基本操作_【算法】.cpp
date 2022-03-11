/* 顺序串结构定义 */
#define MAXLEN 50
typedef struct	/* 串结构定义 */
{
	char ch[MAXLEN];
	int len;
}SString;
/* 【算法4.1】 顺序串插入函数 */
int StrInsert(SString * s,int pos,SString t)
/* 在串S中下标为pos的字符之前插入串t */
{
	int i;
	if(pos<0||pos>s->len)	/* 插入位置不合法 */
		return 0;	
	if(s->len+t.len<=MAXLEN)	/* 插入串后长<=MAXLEN */
	{
		for(i=s->len+t.len-1;i>=t.len+pos;i--)
			s->ch[i]=s->ch[i-t.len];
		for(i=0;i<t.len;i++)
			s->ch[i+pos]=t.ch[i];
		s->len=s->len+t.len;
	}
	else if(pos+t.len<=MAXLEN)	/* 插入后串长>MAXLEN，但串t的字符序列可以全部插入 */
	{
		for(i=MAXLEN-1;i>t.len+pos-1;i--)
			s->ch[i]=s->ch[i-t.len];
		for(i=0;i<t.len;i++)
			s->ch[i+pos]=t.ch[i];
		s->len=MAXLEN;
	}
	else	/* 插入后串长>MAXLEN，并且串t的部分字符也要舍弃 */
	{
		for(i=0;i<MAXLEN-pos;i++)
			s->ch[i+pos]=t.ch[i];
		s->len=MAXLEN;
	}
	return 1;
}
/* 【算法4.2】 顺序串删除函数 */
int StrDelete(SString * s,int pos,int len)
/* 在串s中删除从下标pos起len个字符 */
{
	int i;
	if(pos<0||pos>(s->len-len))	/* 删除参数不合法 */
		return 0;
	for(i=pos+len;i<s->len;i++)
		s->ch[i-pos]=s->ch[i];	/* 从pos+len开始至串尾依次向前移动，实现删除len个字符 */
	s->len=s->len-len;	/* 串的长度减len */
	return 1;
}
/* 【算法4.3】 串比较函数 */
int StrCompare(SString s,SString t)
/* 若串s和t相等则返回0；若s>t则返回正数；若s<t则返回负数 */
{
	int i;
	for(i=0;i<s.len&&i<t.len;i++)
		if(s.ch[i]!=t.ch[i])
			return (s.ch[i]-t.ch[i]);
		return (s.len-t.len);
}
/* 【算法4.4】 顺序串的简单模式匹配（定位）函数 */
int StrIndex(SString s,int pos,SString t)
/* 求从主串s的下标pos起，串t第一次出现的位置，成功返回位置序号，不成功返回-1 */
{
	int i,j,start;
	if(t.len==0)	/* 模式串为空串时，是任意串的匹配串 */
		return 0;
	start=pos; i=start; j=0;	/* 主串从pos开始，模式串从头（0）开始 */
	while(i<s.len&&j<t.len)
		if(s.ch[i]==t.ch[j])	/* 当前对应的字符相等时推进 */
		{
			i++;
			j++;
		}
		else
		{
			start++;	/* 当前对应字符不等时回溯 */
			j=0;	/* 主串从start+1开始，模式串从头（0）开始 */
		}
	if(j>=t.len)
		return (start);	/* 匹配成功时，返回匹配起始位置 */
	else
		return (-1);	/* 匹配不成功是返回-1 */
}
/***************************************************************/
/* 堆串类型结构定义 */
typedef struct
{
	char * ch;
	int len;
}HString;
/* 【算法4.5】 堆串插入函数 */
int StrInsert(HString * s,int pos,HString * t)
/* 在串s中下标为pos的字符之前插入串t */
{
	int i;
	char * temp;
	if(pos<0||pos>s->len||s->len==0)	/* 插入位置不合法 */
		return 0;
	temp=(char *)malloc(s->len+t->len);	/* 动态产生足够的空间存放插入后的串 */
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
/* 【算法4.6】 堆串赋值函数 */
int StrAssign(HString * s,char * tval)
/* 将字符串常量tval的值赋给堆串s */
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
/* 块链串类型结构定义 */
#define BLOCK_SIZE 4	/* 每结点存放字符个数4 */
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
/* 当BLOCK_SIZE等于1时，每个结点存放一个字符，结构同线性链表定义如下： */
#define BLOCK_SIZE 1
typedef struct chBlock
{
	char ch;
	struct chBlock * next;
}chBlock;