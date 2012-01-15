#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 100
static int dx[8]={1,-1,2,-2,2,-2,1,-1};
static int dy[8]= {2,2,1,1,-1,-1,-2,-2};
//const int dx[8]={2,-2,1,-1,2,-2,1,-1};
//const int dy[8]={1,1,2,2,-1,-1,-2,-2};
int n, m;
bool vis[MAX+5][MAX+5], flag;
int ax[MAX+5], ay[MAX+5];

bool is_fit(int x, int y)
{
	if(x >= 1 && x <= n && y >= 1 && y <= m)
		return true;
	return false;
}

void dfs(int step, int x, int y)
{
	ax[step] = x;
	ay[step] = y;//printf("%d\n", step);	
	if(step == n*m)//找到了  
	{
		flag = true;
		return;
	}

	for(int i = 0;i < 8;i ++)
 	{
 		int nx = x+dx[i], ny = y+dy[i];
 		if(is_fit(nx, ny)&&!vis[nx][ny]&&!flag)
 		{		
 			vis[nx][ny] = true;
 			dfs(step+1, nx, ny);//找到的情况，并将位置保存数组 			
 			vis[nx][ny] = false;
		 }
 	}
}
int main()
{
	int  t;
	scanf("%d", &t);
	for(int i = 1; i<=t;i ++)
	{	
		memset(vis, false, sizeof(vis));
		scanf("%d%d", &n, &m);
		vis[n][m] = true;
		flag = false;
		dfs(1, n, m);
		if(flag)
		{
			printf("Scenario #%d:\n", i);
			for(int j = 1;j <= n*m;j ++)
			{
				printf("%c%d", 'A'+ay[j]-1, ax[j]);
			}
			printf("\n\n");
		}		 	
		else printf("Scenario #%d:\nimpossible\n\n", i);
	}
	return 0;
}