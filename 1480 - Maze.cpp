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
    bool ok(int x, int y)      //�ж�(x,y)�Ƿ��ھ����У�����ھ����п��Ƿ����
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
     while (!q.empty())       //��ʼ������
     {
      q.pop();
     }
     node start;         
     start.x = 1;
     start.y = 1;
     start.step = 0;
     q.push(start);        //����ʼλ��ѹ�����
     while (!q.empty())       //�Ӷ�����ȡ���ڵ�
     {
      node nn = q.front();
      q.pop();
      for (int k = 0; k < 4; k++)    //���ĸ���������
      {
       int i = nn.x + dx[k];
       int j = nn.y + dy[k];
       if (ok(i, j))
       {
        if (i == n && j == m)   //�������(n,m)���ز���
        {
         return nn.step + 1;
        }
        else       //���δ�ﵽ��ѹ�����
        {
         node temp;
         temp.x = i;
         temp.y = j;
         temp.step = nn.step + 1;
         q.push(temp);
        }
       }
      }
      g[nn.x][nn.y] = 1;      //��Ƿ��ʹ��ĵ�
     }
     return -1;         //����ﲻ���յ㣬����-1
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