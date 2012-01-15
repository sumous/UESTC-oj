#include<stdio.h>
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
int n, m;
long tot, sum;
int maze[1005][1005];

bool is_fit(int x , int y)//判断是否被访问或者越界 
{
	if(x < 1||x > n) return false;
	if(y < 1||y > m) return false;
	if(maze[x][y] == 1) return false;
	return true;
}
void bfs(int x, int y)
{
//printf("%d %d\n", x, y);
	if(maze[x][y] == 2) 
	{
		sum ++;
		maze[x][y] = 1;
		//if(tot == sum) return;
	}maze[x][y] = 1;
	for(int i = 0;i < 4;i ++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(is_fit(nx, ny))
		{			
			bfs(nx, ny);
			
		}
	}
}
int main()
{
	//freopen("data.txt", "r", stdin);
	int i, j;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		int start_x, start_y;
		getchar();
		tot = sum = 0;
		/*
		输入数据并处理，将墙标记为1，
		通道标记为0，treasure标记为2，
		并统计总共的treasure数tot 
		*/
		for(i = 1;i <= n;i ++)
		{
			for(j = 1;j <= m;j ++)
			{
				char ch;				
				ch = getchar();
				if(ch == 'X')
				{
					maze[i][j] = 1;
					start_x = i;
					start_y = j;
				}
				else if(ch == '*')
				{
					maze[i][j] = 2;
					tot++;
				}
				else if(ch == '#')
					maze[i][j] = 1;
				else maze[i][j] = 0;
			}
			
			getchar();
		}
		bfs(start_x, start_y);
		printf("%ld\n", sum );
	}
	return 0;
}