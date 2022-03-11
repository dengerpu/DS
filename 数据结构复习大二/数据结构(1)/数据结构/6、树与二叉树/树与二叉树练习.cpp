typedef struct Node
{
	char data;
	int Ltag,Rtag;
	Node * LChild,RChild;
}* BiTree;
BiTree pre=NULL;
void Inthread(BiTree root)
{
	if(root!=NULL)
	{
		Inthread(root->LChild);
		if(root->LChild==NULL)
		{
			root->Ltag=1; root->LChild=pre;
		}
		if(pre!=NULL && pre->RChild==NULL)
		{
			pre->RChild=root; pre->RChild=1;
		}
		pre=root;
		Inthread(root->RChild);
	}
}
void Inthread(BiTree root)
{
	if(root!=NULL)
	{
		Inthread(root->LChild);
		if(root->LChild==NULL)
		{
			root->Ltag=1; root->LChild=pre;
		}
		if(pre!=NULL && pre->LChild==NULL)
		{
			pre->RChild=root; pre->Rtag=1;
		}
		pre=root;
		Inthread(root->RChild);
	}
}
BiTree InPre(BiTree p)
{
	if(p->Ltag==1)
		pre=p->LChild;
	else
	{
		for(BiTree q=p->LChild;q->Rtag==0;q=q->RChild);
		pre=q;
	}
	return pre;
}
BiTree InPre(BiTree p)
{
	if(p->Ltag==1)
		pre=p->LChild;
	else
	{
		for(BiTree q=p->LChild;q->Rtag==0;q=q->RChild);
		pre=q;
	}
	return pre;
}
BiTree InNext(BiTree p)
{
	if(p->Rtag==1)
		next=p->RChild;
	else
	{
		for(BiTree q=p->RChild;q->Ltag==0;q=q->LChild);
		next=q;
	}
	return next;
}
BiTree InFirst(BiTree bt)
{
	BiTree p=bt;
	if(!p)
		return NULL;
	while(p->Ltag==0)
		p=p->LChild;
	return p;
}
void TInOrder(BiTree bt)
{
	BiTree p;
	p=InFirst(Bt);
	while(p)
	{
		printf("%c ",p->data);
		p=InNext(p);
	}
}
void TInOrder(BiTree bt)
{
	BiTree p;
	p=InFirst(bt);
	while(p)
	{
		printf("%c ",p->data);
		p=InNext(p);
	}
}
/* 树的孩子兄弟表示法 */
/*typedef struct Node
{
	char data;
	Node * FirstChild,* Nextsibling;
}* CSTree;*/
void RootFirst(CSTree root)
{
	if(root!=NULL)
	{
		printf("%c ",root->data);
		p=root->FirstChild;
		while(p)
		{
			RootFirst(p);
			p=p->Nextsibling;
		}
	}
}
void RootFirst(CSTree root)
{
	BiTree p=bt;
	if(root!=NULL)
	{
		printf("%c ",p->data);
		p=p->FirstChild;
		while(p)
		{
			RootFirst(p);
			p=p->Nextsibling;
		}
	}
}
void RootFirst2(CSTree bt)
{
	BiTree p=bt;
	if(root!=NULL)
	{
		printf("%c ",p->data);
		RootFirst2(p->FirstChild);
		RootFirst2(p->Nextsibling);
	}
}
#define N 20
#define M 2*N-1
typedef struct
{
	int weight;
	int parent;
	int LChild;
	int RChild;
}HuffmanTree[M+1];
void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
{
	char * cd;
	cd=(char *)malloc(sizeof(char));
	cd[n-1]='\0';
	for(int i=0;i<=n;i++)
	{
		start=n-1;
		c=i; p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].LChild==c)
				cd[start]='0';
			else
				cd[start]='1';
			c=p; p=ht[p].parent;
		}
		hc[i]=(char *)malloc(sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}
typedef struct Node
{
	char data;
	Node * LChild,* RChild;
}BiTNode,* BiTree;
int like(BiTree t1,BiTree t2)
{
	int like1,like2;
	if(t1==NULL && t2==NULL)
		return 1;
	else if(t1==NULL || t2==NULL)
		return 0;
	else
	{
		like1=like(t1->LChild,t2->LChild);
		like2=like(t1->RChild,t2->RChild);
		return (like1 && like2);
	}
}
int like(BiTree t1,BiTree t2)
{
	int like1,like2;
	if(t1==NULL && t2==NULL)
		return 1;
	else if(t1==NULL || t2==NULL)
		return 0;
	else
	{
		like1=like(t1->LChild);
		like2=like(t2->RChild);
		return (like1 && like2);
	}
}
void path(BiTree root,BiTree r)
{
	BiTree p,q;
	int i,top=0;
	BiTree s[Stack_Size];
	q=NULL;
	p=root;
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++;
			if(top>=Stack_Size)
				OverFlow();
			s[top]=p;
			p=p->LChild;
		}
		if(top>0)
		{
			p=s[top];
			if(p->RChild==NULL || p->RChild==q)
			{
				if(p==r)
				{
					for(i=1;i<=top;i++)
						printf("%c ",s[i]->data);
					return ;
				}
				else
				{
					q=p;
					top--;
					p=NULL;
				}
			}
			else
				p=p->RChild;
		}
	}
}
void path(BiTree root,BiTree r)
{
	BiTree p,q;
	int i,top=0;
	BiTree s[Stack_Size];
	q=NULL;	//用q保存刚遍历过的结点，初始为空
	p=root;
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++;
			if(top>=Stack_Size)
				OverFlow();
			s[top]=p;
			p=p->LChild;
		}
		if(top>0)
		{
			p=s[top];
			if(p->RChild==NULL || p->RChild==q)
			{
				if(p==r)
				{
					for(i=1;i<=top;i++)
						printf("%c ",s[i]->data);
					return ;
				}
				else
				{
					q=p;
					top--;
					p=NULL;
				}
			}
			else
				p=p->RChild;
		}
	}
}
void path(BiTree root,BiTree r)
{
	BiTree p,q;
	int i,top=0;
	BiTree s[Satck_Size];
	q=NULL;
	p=root;
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++;
			if(top>=Stack_Size)
				OverFlow();
			s[top]=p;
			p=p->LChild;
		}
		if(top>0)
		{
			p=s[top];
			if(p->RChild==NULL || p->RChild==q)
			{
				if(p==r)
				{
					for(i=1;i<=top;i++)
						printf("%c ",s[i]->data);
					return ;
				}
				else
				{
					q=p;
					top--;
					p=NULL;
				}
			}
			else
				p=p->RChild;
		}
	}
}
void path(BiTree root,BiTree r)
{
	BiTree p,q;
	int i,top=0;
	BiTree s[Stack_Size];
	q=NULL;
	p=root;
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++;
			if(top>=Stack_Size)
				OverFlow();
			s[top]=p;
			p=p->LChild;
		}
		if(top>0)
		{
			p=s[top];
			if(p->RChild==NULL || p->RChild==q)
			{
				if(p==r)
				{
					for(i=1;i<=top;i++)
						printf("%c ",s[i]->data);
					return ;
				}
				else
				{
					q=p;
					top--;
					p=NULL;
				}
			}
			else
				p=p->RChild;
		}
	}
}
int LayerOrder(BiTree bt)
{
	SeqQueue Q;
	BiTree p;
	InitQueue(&Q);
	if(bt==NULL)
		return ERROR;
	EnterQueue(&Q,bt);
	while(!IsEmpty(Q))
	{
		DeleteQueue(&Q,&p);
		printf("%c ",p->data);
		if(p->LChild) EnterQueue(&Q,p->LChild);
		if(p->RChild) EnterQueue(&Q,p->RChild);
	}
	return OK;
}
int LayerOrder(BiTree bt)
{
	SeqQueue Q;
	BiTree p;
	InitQueue(&Q);
	if(bt==NULL)
		return ERROR;
	EnterQueue(&Q,bt);
	while(!IsEmpty(Q))
	{
		DeleteQueue(&Q,&p);
		printf("%c ",p->data);
		if(p->LChild) EnterQueue(&Q,p->LChild);
		if(p->RChild) EnterQueue(&Q,p->RChild);
	}
	return OK;
}
int LayerOrder(BiTree bt)
{
	SeqQueue Q;
	BiTree p;
	InitQueue(&Q);
	if(!bt)
		return ERROR;
	EnterQueue(&Q,bt);
	while(!IsEmpty(Q))
	{
		DeleteQueue(&Q,&p);
		printf("%c ",p->data);
		if(p->LChild) EnterQueue(&Q,p->LChild);
		if(p->RChild) EnterQueue(&Q,p->RChild);
	}
	return OK:
}
