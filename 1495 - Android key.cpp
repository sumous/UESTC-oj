#include<stdio.h>
#include<string.h>
int n, m, k;
static int dx[4] = {1,-1,0,0};
static int dy[4] = {0,0,-1,1};
int vis[110];
bool is_ok(int x, int y)
{
	if(x>0 && x<=n && y>0 && y<=m)
		return true;
	return false;
}
long waynum(int x, int y, int len)
{
	if(len == k)
	{
		return 1;
	}
	long way = 0;
	for(int i = 0;i < 4;i ++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		int cur = nx*m+ny;
		if(is_ok(nx ,ny)&&vis[cur] == 0)
		{
			vis[cur] = 1;
			way += waynum(nx, ny, len+1);
			vis[cur] = 0;
		}
	}
	return way;
}
int main()
{
	while(scanf("%d%d%d", &n, &m, &k)!=EOF)
	{
		if(k == 0) {printf("0\n");continue;}
		memset(vis, 0, sizeof(vis));
		long way  = 0;
		if(n%2==0)
		{
			if(m%2==0)
			{
				for(int i = 1;i <= n/2;i ++)
					for(int j = 1;j <= m/2;j ++)
					{
						int cur = i*m+j;
						vis[cur] = 1;
						way += waynum(i, j, 1);
						vis[cur] = 0;
					}
				printf("%ld\n", way*4);
			}
			else
			{
				for(int i = 1;i <= n/2;i ++)
					for(int j = 1;j <= m/2;j ++)
					{
						int cur = i*m+j;
						vis[cur] = 1;
						way += waynum(i, j, 1);
						vis[cur] = 0;
					}
				way*=4;
				long tmp = 0;
				int j = m/2+1;
				for(int i = 1;i <= n/2;i ++)
				{
					int cur = i*m+j;
					vis[cur] = 1;
					tmp += waynum(i, j, 1);
					vis[cur] = 0;
				}
				way+=tmp*2;
				printf("%ld\n", way);
			}
		}
		else
		{
			if(m%2==0)
			{
				for(int i = 1;i <= n/2;i ++)
					for(int j = 1;j <= m/2;j ++)
					{
						int cur = i*m+j;
						vis[cur] = 1;
						way += waynum(i, j, 1);
						vis[cur] = 0;
					}
				int i = n/2+1;
				way*=4;
				long tmp = 0;
				for(int j = 1;j <= m/2;j ++)
				{
					int cur = i*m+j;
					vis[cur] = 1;
					tmp += waynum(i, j, 1);
					vis[cur] = 0;
				}
				way+=tmp*2;
				printf("%ld\n", way);
			}
			else
			{
				for(int i = 1;i <= n/2;i ++)
					for(int j = 1;j <= m/2;j ++)
					{
						int cur = i*m+j;
						vis[cur] = 1;
						way += waynum(i, j, 1);
						vis[cur] = 0;
					}
				int i = n/2+1;
				way*=4;
				long tmp = 0;
				for(int j = 1;j <= m/2;j ++)
				{
					int cur = i*m+j;
					vis[cur] = 1;
					tmp += waynum(i, j, 1);
					vis[cur] = 0;
				}
				way+=tmp*4+waynum(n/2+1,m/2+1,1);
				printf("%ld\n", way);
			}
		}
		
	}
	return 0;
}