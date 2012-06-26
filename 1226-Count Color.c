/**
 * 1226-Count Color
 * 线段树应用,tree.c用于记录当前是否只有一种颜色
 * 因为颜色最多只有30种,所有用二进制记录颜色信息
 */
# include <stdio.h>
# include <string.h>
# define swap(A, B) {int tmp = A;A=B;B=tmp;}
int L, T, O;
int res = 0;

struct Tree
{
	int l, r;
	int c;
}tree[500000];
void build(int l, int r, int k)
{
	tree[k].l = l, tree[k].r = r;
	tree[k].c = 1;
    if (l != r)
    {
        int mid = (l+r)>>1;
        build(l, mid, k<<1);
        build(mid+1, r, (k<<1) + 1);
    }
}

void update(int l, int r, int c, int k)
{
    int mid = (tree[k].l + tree[k].r)>>1;
    if (tree[k].c == c) return;
    //  if (tree[k].l == l && tree[k].r == r) 时间的瓶颈一部分就在这里,另外一部分就是C和C++的效率上了
    if (l <= tree[k].l && tree[k].r <= r)
    {
        tree[k].c = c;
        return;
    }
    if (tree[k].l == tree[k].r) return;
    if (tree[k].c > 0)
    {
        tree[k<<1].c = tree[(k<<1)+1].c = tree[k].c;

    }
    
    if (l > mid)
        update(l, r, c, (k<<1) + 1);
    else if (r <= mid)
        update(l, r, c, k<<1);
    else
    {
        update(l, mid, c, k<<1);
        update(mid+1, r, c, (k<<1)+1);
    }
    tree[k].c = -1;
}

void query(int l, int r, int k)
{
    int mid = (tree[k].l + tree[k].r)>>1;
	if (tree[k].c > 0)
    {
        res |= (1<<tree[k].c);
        return;
    }
    
    if (l > mid)
        query(l, r, (k<<1) + 1);
    else if (r <= mid)
        query(l, r, k<<1);
    else
    {
        query(l, mid, k<<1);
        query(mid+1, r, (k<<1) + 1);
    }
            
}

int cal1(int n)
{
	int ans = 0;
	for ( ;n; n -= n&-n) ans ++;
	return ans;
}

int main()
{

	freopen("data","r",stdin);
    int i;
	scanf("%d %d %d", &L, &T, &O);
	build(1, L, 1);
    
	for (i = 0; i < O; i++)
	{
		char ch;
		int A, B, C;
        getchar();
        scanf("%c %d %d", &ch, &A, &B);
		if (ch == 'C')
		{
            scanf("%d", &C);
            if (A > B)
                swap(A, B);
			update(A, B, C, 1);
		}
		else
		{
			if (A > B) swap(A, B);
            res = 0;
            query(A, B, 1);
            printf("%d\n", cal1(res));
		}
	}
	return 0;
}
