/**
* 1458-Frequent values
* 数据结构题,线段树
* 线段树的长度不一定是2*N-1,会超过这个值的.
* 以下例子:-1 -1 1 1 1 1 3 10 10 10
* 1.用w.lr记录当前节点起到最左端连续相同数个数, w.rl记录当前节点起到最右端连续相同数个数
*  比如,w[4].lr = 2, w[4].rl = 3
* 2.建树过程中,需要分左儿子最右端数和右儿子最左端数相等和不相等的两种清空
* 3.查询时,需要考虑跟建树过程一样样的东西
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>

#define MAX_NUM 100005
int n, q;
int a[MAX_NUM];
int min_l, max_r;

struct node
{
    int left, right;
    int max;
}tree[MAX_NUM*6];//这边阿,不一定的嘛,肯定是要超的
struct node_w
{
    int lr, rl;
    int maxr;
}w[MAX_NUM*2];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void load()
{
    memset(w, 0, sizeof(w));
    scanf("%d", &q);
    int i = 0;
    
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    //当前节点起到最左端连续相同数个数
    for (i = 1; i <= n; i++)
    {
        int sum = 0;
        while (i < n && a[i] == a[i+1])
        {            
            sum++;
            w[i].lr = sum;
            i++;
        }
        w[i].lr = sum+1;
    }
    //当前节点起到最右端连续相同数个数
    for (i = n; i >= 1; i--)
    {
        int sum = 0;
        while (i > 1 && a[i] == a[i-1])
        {
            sum++;
            w[i].rl = sum;
            i--;
            
            
        }
        w[i].rl = sum+1;
    }

       for (i = 1; i <= n; i++)
         printf("ll:%d rr%d\n", w[i].lr, w[i].rl);
    
}

/*建立线段树*/
void build(int left, int right, int root)
{
    
    tree[root].left = left; tree[root].right = right;
    if (left == right)
    {
        tree[root].max =1;
        //   return;
    }
    else
    {
        int mid = (left+right)>>1;
        int tl = root<<1, tr = (root<<1) + 1;
        build(left, mid, tl);
        build(mid+1, right, tr);
        tree[root].max = max(tree[tl].max, tree[tr].max);
        if (a[ tree[tl].right ] == a[ tree[tr].left ])
        {
            int ll = tree[tl].right - tree[tl].left + 1;
            int rr = tree[tr].right - tree[tr].left + 1;
            if (ll > w[ tree[tl].right ].lr)
                ll = w[ tree[tl].right ].lr;
            if (rr > w[ tree[tr].left ].rl)
                rr = w[ tree[tr].left ].rl;
            tree[root].max = max(tree[root].max, ll+rr);
        }
  
    }
 
}

/*查询区间最大值*/
int query_max(int l, int r, int root)
{
    if (tree[root].left == l && tree[root].right == r)
        return tree[root].max;
    else 
    {
        int mid = (tree[root].left + tree[root].right)>>1;
        int tl = root<<1, tr = (root<<1) + 1;
        if (l > mid)
            return query_max(l, r, tr);
        else if (r <= mid)
            return query_max(l, r, tl);
        
        int m = max( query_max(l, mid, tl), query_max(mid+1, r, tr ) );
        if (a[ tree[tl].right ] == a[ tree[tr].left ])
        {
            //这里跟建树过程稍微有点区别
            int ll = tree[tl].right - l + 1;
            int rr = r - tree[tr].left + 1;
            if (ll > w[ tree[tl].right ].lr)
                ll = w[ tree[tl].right ].lr;
            if (rr > w[ tree[tr].left ].rl)
                rr = w[ tree[tr].left ].rl;
            
            m = max(m, ll+rr);
        }
        return m;
    }
}

void solve()
{
    int l, r, i;
    for (i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
          int m = query_max( l, r, 1);
          printf("%d\n", m);
    }	
}

int main()
{
    freopen("data", "r", stdin);
    while (scanf("%d", &n) && n != 0)
    {
        load();
        build(1, n, 1);		
        
        solve();
    }
    
    return 0;
}
