# include <iostream>
# include <stdio.h>
# include <string.h>
using namespace std;
char floor[105][105];
int f[105][2];
int n, m;

void load()
{
    scanf("%d %d", &n, &m);
    // getchar();
    for (int i = 1; i <= n; i ++)
    {
        getchar();
        for (int j = 0; j < m; j++)
            floor[i][j] = getchar();
    }

}
int left(int i)
{
    for (int j = m-2; j > 0; j--)
    {
        if (floor[i][j] == '*')
            return j*2;
    }
    return 0;
}
int right(int i)
{
    for (int j = 1; j < m-1; j ++)
        if (floor[i][j] == '*')
            return (m-j-1)*2;
    return 0;
}
void dp()
{
       f[1][0] = left(1), f[1][1] = right(1);
       //  f[0][0] = f[0][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = min(f[i-1][0]+left(i), f[i-1][1]+m-1) + 1;
        f[i][1] = min(f[i-1][1]+right(i), f[i-1][0]+m-1) + 1;
    }
}
void out(int cas)
{
    //  for (int i = 1; i <= n; i++)
    //  cout<<f[i][0]<<" "<<f[i][1]<<endl;
    int res = min(f[n][0], f[n][1]);
    printf("Case #%d: %d\n", cas, res);
}
int main()
{
    freopen("data", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        memset(f, 0, sizeof(f));
        load();
        dp();
        out(i);
    }
    return 0;
}
