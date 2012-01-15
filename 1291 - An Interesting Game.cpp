#include<stdio.h>
#include<string.h>
#define INF 2139062143
int d[105][105];
int N,M,K;
int main()
{
	int t;
//	freopen("data.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		memset(d,127,sizeof(d));
		scanf("%d %d %d",&N,&M,&K);
		while(M--)
		{
			char ch;
			int a, b;
			scanf("%d %c %d",&a,&ch,&b);
			if(ch=='>') d[b][a]=1;
			else d[a][b]=d[b][a]=0;
		}
		for(int i = 0;i < N;i++) d[i][i]=0;
		for(int k = 0;k < N;k++)
			for(int i = 0;i < N;i++)
				for(int j = 0;j < N;j++)
				{
					if(d[i][k]!=INF && d[k][j]!=INF && d[i][j]>d[i][k]+d[k][j])
						d[i][j]=d[i][k]+d[k][j];
				}
		while(K--)
		{
			int a ,b;
			scanf("%d%d",&a,&b);
			if(d[a][b]==INF && d[b][a]==INF) printf("N\n");
			else if(d[b][a]==INF && d[a][b]>0) printf("<\n");
			else if(d[a][b]==INF && d[b][a]>0) printf(">\n");
			else printf("=\n");
		}
	}
	return 0;
}