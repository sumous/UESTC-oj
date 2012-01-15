#include<stdio.h>
#include<string.h>
int n;
int pack[205];
int g[205][205];
bool toposort()
{
	int i, j, k, odeg[205];
	for(i = 1;i <=n;i++)
		for(odeg[i]=0,j=1;j<=n;j++) odeg[i]+=g[i][j];
	for(i = n;i > 0;i--)
	{
		for(j = n;j>0 && odeg[j];j-- );
		if(j==0) return false;
		odeg[j]=-1;
		pack[j]=i;
		for(k = n;k>0;k--) odeg[k]-=g[k][j];
	}
	return true;
}
int main()
{
//	freopen("data.txt","r",stdin);
	int T, M;
	scanf("%d",&T);
	while(T--)
	{
		memset(g,0,sizeof(g));
		scanf("%d%d",&n,&M);
		while(M--)
		{
			int a, b;
			scanf("%d%d",&a,&b);
			g[a][b]=1;
		}
		if(!toposort()) printf("-1");
		else 
		{
			for(int i = 1;i < n;i++) 
				printf("%d ",pack[i]);
			printf("%d",pack[n]);
		}
			
		putchar('\n');
	}
	
	return 0;
}