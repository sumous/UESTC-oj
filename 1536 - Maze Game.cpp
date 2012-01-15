#include<stdio.h>
#include<string.h>
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int sx, sy;
int nox,noy;
int n , m;
long len;
char s[1005][1005];
bool vis[1005][1005];
bool visa[1005][1005];
void dfs(int x, int y,long step)
{
	visa[x][y]=true;
	if(step>len)
	{
		sx=x;sy=y;
		len=step;
	}
	for(int i = 0;i < 4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>0 && nx<=m && ny>0 && ny<=n && (!vis[nx][ny]) && (s[nx][ny]=='.'))
		{
			vis[nx][ny]=true;
			dfs(nx,ny,step+1);
			vis[nx][ny]=false;
		}
	}
	
}
bool is_visall()
{
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
		{
			if(!visa[i][j])
			{
				nox=i;noy=j;
				return false;
			}
		}
	return true;
}
int main()
{
//	freopen("data.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int i = 1;i <= t;i++)
	{
		memset(visa,false,sizeof(visa));
		scanf("%d%d",&n, &m);
		int j,k;	
		for(j = 1;j<=m;j++)
		{
			getchar();
			for(k = 1;k<=n;k++)
			{
				scanf("%c",&s[j][k]);
				if(s[j][k]=='#') visa[j][k]=true;
			}
		}
		int flag=0;
		for(j = 1;j<=m;j++)
		{
			if(flag) break;
			for(k = 1;k<=n;k++)
				if(s[j][k]=='.'){sx=j;sy=k;flag=1;break;}
		}
		//printf("%d %d\n",sx,sy);
		len=0;
		memset(vis,false,sizeof(vis));
		vis[sx][sy]=true;
		dfs(sx,sy,0);//printf("%d %d\n",sx,sy);
		len=0;
		memset(vis,false,sizeof(vis));
		vis[sx][sy]=true;
		dfs(sx,sy,0);
		while(!is_visall())
		{
			memset(vis,false,sizeof(vis));
			vis[nox][noy]=true;
			dfs(nox,noy,0);//printf("%d %d\n",sx,sy);
			len=0;
			memset(vis,false,sizeof(vis));
			vis[sx][sy]=true;
			dfs(sx,sy,0);
		}
		printf("Case #%d:\n%ld\n",i,len);
	}
	return 0;
}