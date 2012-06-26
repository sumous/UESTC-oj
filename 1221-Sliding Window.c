/**
* 1221-Sliding Window UESTC
* 数据结构题,可以用线段树来做,或者优先队列也行.比较简单,但是一直出现各种问题.
* 线段树的长度不一定是2*N-1,会超过这个值的.
*/
# include <stdio.h>

const int MAX_NUM = 1000001;
int w[MAX_NUM], n, k;
int a[MAX_NUM], b[MAX_NUM];

struct node
{
    int left, right;
    int max, min;
}tree[MAX_NUM*3];//这边阿,不一定的嘛

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int min(int a, int b)
{
    return (a > b) ? b : a;
}
void load()
{
    scanf("%d %d", &n, &k);
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
}

/*建立线段树*/
void build(int left, int right, int root)
{
    tree[root].left = left; tree[root].right = right;
    if (left == right)
    {
        tree[root].max = w[left];
        tree[root].min = w[left];
        return;
    }
    else
    {
        int mid = (left+right)>>1;
        build(left, mid, root<<1);
        build(mid+1, right, (root<<1) + 1);
        tree[root].min = min(tree[root<<1].min, tree[ (root<<1) +1].min);
        tree[root].max = max(tree[root<<1].max, tree[ (root<<1)+1].max);
        
    }
}

/*查询区间最小值*/
int query_min(int l, int r, int root)
{
    if (tree[root].left == l && tree[root].right == r)
        return tree[root].min;
    else  
    {
        int mid = (tree[root].left + tree[root].right)>>1;
        if (l > mid)
            return query_min(l, r, (root<<1)+1);
        else if (r <= mid)
            return query_min(l, r, root<<1);
        return min( query_min(l, mid, root<<1), query_min(mid+1, r, (root<<1) + 1) );
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
        if (l > mid)
            return query_max(l, r, (root<<1)+1);
        else if (r <= mid)
            return query_max(l, r, root<<1);
        return max( query_max(l, mid, root<<1), query_max(mid+1, r, (root<<1) + 1) );
    }
}

void solve()
{
    /*求出所有最小值*/
    int i = 1;
    while (i <= n-k+1)
    {
        a[i] = query_min(i, i+k-1, 1);
        i++;
    }
        
    i = 1;
    /*求出所有最大值*/
    while (i <= n-k+1)
    {
        b[i] = query_max(i, i+k-1, 1);
        i++;
    }
}

void out()
{
    int i;
    for (i = 1; i < n-k+1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[i]);

    for (i = 1; i < n-k+1; i++)
        printf("%d ", b[i]);
    printf("%d\n", b[i]);
}

int main()
{
//    freopen("data", "r", stdin);
    load();
    build(1, n, 1);		

     solve();	
     out();
    return 0;
}
