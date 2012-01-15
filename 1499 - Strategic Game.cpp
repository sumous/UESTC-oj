#include<stdio.h>
int tree[1505][25];
int d[1505][2];
int min(int a, int b)
{
	return a>b?b:a;
}
int dp(int i, int j)
{
	if(d[i][j] != -1) return d[i][j];
	if(j == 0)
	{
		d[i][j] = 0;
		for(int x = 1;x <= tree[i][0];x ++)
		{
			d[i][j] += dp(tree[i][x],1);
		}
	}
	else
	{
		d[i][j] = 0;
		for(int x = 1;x <= tree[i][0];x ++)
		{
			d[i][j] += min(dp(tree[i][x],1),dp(tree[i][x],0));
		}
		d[i][j]+=1;
	}
	return d[i][j];
}
int main()
{
//	freopen("data.txt","r",stdin);
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int root;
		for(int i = 0;i < n;i++)	d[i][0]=d[i][1]=-1;
		for(int i = 0;i < n;i ++)
		{
			int tmp1, tmp2;
			
			scanf("%d:(%d)",&tmp1,&tmp2);
			if(i == 0) root = tmp1;
			tree[tmp1][0]=tmp2;//记录孩子个数 
			
			for(int j = 1;j <= tmp2;j ++)
				scanf("%d", &tree[tmp1][j]);
		}//printf("%d\n",root);
		printf("%d\n", min(dp(root,1),dp(root,0))); 
	}
	return 0;
}