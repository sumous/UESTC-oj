    #include <iostream>
    #include <cstdio>
    #include <queue>
    using namespace std;
    const int MAXLEN = 255;
    bool g[MAXLEN][MAXLEN];
    struct node {
     int x,y;
     int step;
    };
    queue <node> q;
    int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
    int n, m;
    bool ok(int x, int y)      //判断(x,y)是否在矩阵中，如果在矩阵中看是否可走
    {
     if (x < 1 || y < 1)
     {
      return false;
     }
     if (x > n || y > m)
     {
      return false;
     }
     if (g[x][y] == 1)
     {
      return false;
     }
     return true;
    }
    int BFS()
    {
     while (!q.empty())       //初始化队列
     {
      q.pop();
     }
     node start;         
     start.x = 1;
     start.y = 1;
     start.step = 0;
     q.push(start);        //将起始位置压入队列
     while (!q.empty())       //从队列中取出节点
     {
      node nn = q.front();
      q.pop();
      for (int k = 0; k < 4; k++)    //向四个方向搜索
      {
       int i = nn.x + dx[k];
       int j = nn.y + dy[k];
       if (ok(i, j))
       {
        if (i == n && j == m)   //如果到达(n,m)返回步数
        {
         return nn.step + 1;
        }
        else       //如果未达到，压入队列
        {
         node temp;
         temp.x = i;
         temp.y = j;
         temp.step = nn.step + 1;
         q.push(temp);
        }
       }
      }
      g[nn.x][nn.y] = 1;      //标记访问过的点
     }
     return -1;         //如果达不到终点，返回-1
    }
    int main()
    {
     int T;
     freopen("data.txt","r", stdin);
     scanf("%d", &T);
     for (int cas = 1; cas <= T; cas++)
     {
      scanf("%d %d", &n, &m);
      for (int i = 1; i <= n; i++)
      {
       for (int j = 1; j <= m; j++)
       {
        scanf("%d", &g[i][j]);
       }
      }
      printf("Case #%d: %d\n", cas, BFS());
     }
     return 0;
    }