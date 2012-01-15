#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
int n, m;
int maze[255][255];
struct node
{
	int x , y;
	int dist;
};


queue <node> q;
void init()
{
	while(!q.empty())
		q.pop();
}
bool is_fit(int x , int y)
{
	if(x < 1||x > n) return false;
	if(y < 1||y > m) return false;
	if(maze[x][y] == 1) return false;
	return true;
}
int bfs()
{
	init();
	node begin;
	begin.x = 1;
	begin.y = 1;
	begin.dist = 0;
	q.push(begin);
	while(q.empty() == false)
	{
		node t = q.front();
		q.pop();
		for(int i = 0;i < 4;i ++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];//printf("%d %d %d\n", nx,ny,maze[nx][ny]);
			if(is_fit(nx, ny))
			{
				if(nx == n&&ny == m)
				{//printf("%d %d", t.x,t.y);
					return t.dist + 1;
				}
				else
				{
					node temp;
					temp.x = nx;
					temp.y = ny;
					temp.dist = t.dist + 1;
					q.push(temp);
				}
				maze[nx][ny] = 1;
			}
		}
		
	}
	return -1;
}
int main()
{
	//freopen("data.txt", "r",stdin);
	int t, i;
	scanf("%d", &t);
	for(i = 1;i <= t;i ++)
	{
		int  j ,k;
		scanf("%d%d", &n, &m);

		for(j = 1;j <= n;j ++)
			for(k = 1;k <= m;k ++)
			{
				scanf("%d", &maze[j][k]);
			//	printf("%d ", maze[j][k]);
			}//printf("\n");}

		printf("Case #%d: %d\n", i, bfs());
	}
	return 0;
}