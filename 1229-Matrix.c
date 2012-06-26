/**
 * 1229-Matrix
 * 可以用树状数组做,二维数状数组
 * 首先线看一维的树状数组翻转的例子,我们统计的是被翻转的次数.
 * 如果需要翻转[i, j]区间,则f[i]++和f[j+1]--
 * 这时,对于任何[i, j]区间中的k,sum(f[1], f[2], ... , f[k])都会减1,
 * 而对于[j+1, N]区间中的k,sum(f[1], f[2], ... , f[k])由于f[i]++,f[j]--而保持不变
 * 对于[1, i-1]区间中的k,sum(f[1], f[2], ..., f[k])不变.
 * 有个技巧就是,f[i]++,f[j+1]--可以改成f[i]++, f[j+1]++.因为翻转两次等于保持不变.
 */
# include <stdio.h>
# include <string.h>
# define lowbit(a) (a&(-a))
int X, n, t;
int tree[1005][1005];

void init()
{
    memset(tree, 0, sizeof(tree));
}
void update(int x, int y, int val)
{
    while (x <= n)
    {
        int tmp = y;
        while (tmp <= n)
        {
            tree[x][tmp] += val;
            tmp += lowbit(tmp);
        }
        x += lowbit(x);
    }
}
int query(int x, int y)
{
    int sum = 0;
    while (x > 0)
    {
        int tmp = y;
        while (tmp > 0)
        {
            sum += tree[x][tmp];
            tmp -= lowbit(tmp);
        }
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
//	freopen("data","r",stdin);
    scanf("%d", &X);
    int i;
    for (i = 0; i < X; i++)
    {
        init();
        scanf("%d %d", &n, &t);
        int j;
        for (j = 0; j < t; j++)
        {
            char ch;
            int x1, y1, x2, y2;
            getchar();
            scanf("%c %d %d", &ch, &x1, &y1);
            if (ch == 'C')
            {
                scanf("%d %d", &x2, &y2);
                update(x1, y1, 1);              
                update(x2+1, y1, 1);
                update(x1, y2+1, 1);
                update(x2+1, y2+1, 1);
            }
            else
            {
                printf("%d\n", query(x1, y1)&1);
            }
        }
        printf("\n");
    }
	return 0;
}
