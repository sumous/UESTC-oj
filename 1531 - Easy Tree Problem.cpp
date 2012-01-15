#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200005
typedef struct node
{
	int val;
	struct node *next;
};
node* tree[MAX];
int d[MAX];
int n;
int dp(int x)
{
	int& ans=d[x];
	if(ans!=-1 ) return ans;
	ans=0;
	if(tree[x]->val==0) return 0;
	node* p=tree[x]->next;
	while(p!=NULL)
	{
		ans+=dp(p->val)+1;
		p=p->next;
	}
	return ans;
}
void destroy()//清理内存 
{
	node* p;
	for(int i=1;i<=n;i++)
	{
		p=tree[i];
		while(p!=NULL)
		{
			node* tmp=p;
			p=p->next;
			free(tmp);
		}
	}
}
int main()
{
	freopen("data.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		printf("Case #%d:",cas);
		memset(d,-1,sizeof(d));
		int i, j;
		
		scanf("%d",&n);
		for(i = 0;i <=n;i++) {tree[i]=(node *)malloc(sizeof(node));tree[i]->val=0;tree[i]->next=NULL;}//初始化,tree[i]->val记录相邻孩子个数 
		for(i = 2;i<=n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
		 	node* p=tree[tmp];
			tree[tmp]->val++;
			while(p->next!=NULL)  p=p->next;//找出尾结点 
			node* q=(node *)malloc(sizeof(node));
			q->val=i;
			q->next=NULL;
			p->next=q;
		}
	//	d[1]=n-1;
		dp(1);
		for(i=1;i<=n;i++) printf(" %d",d[i]);
		putchar('\n');
		destroy();
	}
	return 0;
}