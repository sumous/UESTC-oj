/**
 * 1222-The Suspects
 * 并查集的简单应用
 * 首先构造并查集,然后找到0的根节点,遍历所有的节点,若该节点的根节点和0的根节点相同,sum+1
 */
# include <stdio.h>
int m, n;
int set[30005];
int sum = 0;

void init()
{
    int i = 0;
    for (i = 0; i < n; i++)
        set[i] = i;
}
int findSet(int x)
{
    if (x == set[x])
        return x;
    else
        return set[x] = findSet(set[x]);
}
void unionSet(int x, int y)
{
    int fx = findSet(x);
    int fy = findSet(y);
    set[fy] = fx;
}
void load()
{
    
    int i;
    for (i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        int j, x;
        scanf ("%d", &x);
        for (j = 1; j < t; j++)
        {
            int y;
            scanf ("%d", &y);
            unionSet(x, y);
            
        }
    }
}
void solve()
{
    sum = 1;
    int i, p = findSet(0);
    
    for (i = 1; i < n; i++)
        if (findSet(i) == p)
            sum++;
}
void out()
{
    printf("%d\n", sum);
}
int main()
{
    freopen("data", "r", stdin);
    while (scanf("%d %d", &n, &m ) && (n|m) )
    {
        init();
        load();
        solve();
        out();
    }
    return 0;
}
