    #include <iostream>
    #include <cstdio>
    #include <queue>
    using namespace std;
    const int dx[4]={1,0,0,-1};
    const int dy[4]={0,-1,1,0};
    int n, m;
    long tot;
    int maze[1005][1005];
    struct point
    {
    int x, y;
    };
    point start;
    queue <point> q;
    void init()//初始化队列
    {
    while(!q.empty())
    q.pop();
    }
    bool is_fit(int x , int y)//判断是否被访问或者越界
    {
    if(x < 1||x > n) return false;
    if(y < 1||y > m) return false;
    if(maze[x][y] == 1) return false;
    return true;
    }
    long bfs()
    {
    long num = 0;
    init();
    q.push(start);//第一个入队列
    while(q.empty() == false)
    {
    point p = q.front();//取出头结点
    q.pop();
    for(int i = 0;i < 4;i ++)
    {
    int nx = p.x + dx[i];
    int ny = p.y + dy[i];
    if(is_fit(nx, ny))//该方向未被访问，且不越界
    {
    if(maze[nx][ny] == 2)//该位置是treasure
    {
    num ++;
    maze[nx][ny] = 1;
    if(num == tot) return tot;
    }
    else
    {
    point temp;
    temp.x = nx;
    temp.y = ny;
    q.push(temp);
    }
    maze[nx][ny] = 1;
    }
    }
    }
    return num;
    }
    int main()
    {
    // freopen("data.txt", "r", stdin);
    int i, j;
    while(scanf("%d %d", &n, &m) != EOF)
    {
    getchar();
    tot = 0;
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
    start.x = i;
    start.y = j;
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
    printf("%ld\n", bfs());
    }
    return 0;
    }