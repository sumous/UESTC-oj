#include<stdio.h>
#include<string.h>
#include <iostream>
#include <queue>
#define N 22
using namespace std;
static int ckl[]={1,2,4,8,16,32,64,128,256,512,1024};
static int dx[]={0,0,1,-1};
static int dy[]={1,-1,0,0};
struct point
{
	int x, y;
	int step;
	bool key[10];
	int sum;
};
point start, end;
int n, m, t;
bool vst[N][N][1025];//判重 
char map[N][N];

int bfs()
{
	queue <point> q;
	q.push(start);
	while(q.empty() == false)
	{
		point cur = q.front();
		q.pop();
		
		if(cur.x==end.x && cur.y==end.y && cur.step<t)
			return cur.step;
		point nxt;
		nxt.step = cur.step + 1;
		for(int i = 0; i < 4;i ++)
		{			
			nxt.x = cur.x + dx[i];
			nxt.y = cur.y + dy[i];
			if(nxt.x>=0 && nxt.x<n && nxt.y>=0 && nxt.y<m && map[nxt.x][nxt.y]!='*')
			{
				for(int j = 0;j < 10;j ++) nxt.key[j] = cur.key[j];
				
				if(map[nxt.x][nxt.y]>='a' && map[nxt.x][nxt.y]<='j')
				{//碰到钥匙了 
					int tmp = ckl[map[nxt.x][nxt.y]-'a'];
					if(nxt.key[map[nxt.x][nxt.y]-'a'] == false)
					{//
						nxt.key[map[nxt.x][nxt.y]-'a'] = true;
						nxt.sum = cur.sum + tmp;
					}
					else
						nxt.sum = cur.sum;
					if(vst[nxt.x][nxt.y][nxt.sum]==false && nxt.step<t)
					{
						vst[nxt.x][nxt.y][nxt.sum]==true;
						q.push(nxt);
					}
				}				
				else if(map[nxt.x][nxt.y]>='A' && map[nxt.x][nxt.y]<='J')
				{			
					int tmp = ckl[map[nxt.x][nxt.y]-'A'];
					if(nxt.key[map[nxt.x][nxt.y]-'A'] == true)
					{
						nxt.sum = cur.sum;//printf("test");
						if(nxt.step<t && vst[nxt.x][nxt.y][nxt.sum] == false)
						{//printf("%d %d %d\n", nxt.x,nxt.y,tmp);
							vst[nxt.x][nxt.y][nxt.sum] == true;
							q.push(nxt);
						}
					}
				}
				else
				{
					nxt.sum = cur.sum;
					if(nxt.step < t && vst[nxt.x][nxt.y][nxt.sum] == false)
					{
						vst[nxt.x][nxt.y][nxt.sum] == true;
						q.push(nxt);
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
//	freopen("data.txt","r",stdin);
	while(scanf("%d%d%d", &n, &m, &t) != EOF)
	{
		for(int i = 0;i < n;i ++)
		{
			scanf("%s", map[i]);
			map[i][m] = '\0';
			for(int j = 0;j < m;j ++)//寻找入口和出口 
			{
				if(map[i][j] == '@')
				{
					start.x = i;
					start.y = j;
					start.step = 0;
					start.sum = 0;
					for(int k=0;k<11;k++){
      					 start.key[k] = false;
      				}
				//	start.key = 0;
				}
				if(map[i][j] == '^')
				{
					end.x = i;
					end.y = j;
					end.step = -1;
				}
			}
		}
		memset(vst, false, sizeof(vst));
		printf("%d\n", bfs());
	}
	return 0;
}