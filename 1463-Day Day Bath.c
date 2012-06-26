/**
 * 1463-Day Day Bath
 * 使用最小堆,维护最小值,每次在最小值的基础上加上下一个时间值
 * 直到t数组为空,此时的最小值即为所需等待时间
 */
# include <iostream>
# include <cstdio>
# define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;
int t[100005], n, m, size;
int A[100005];
int res;
void load()
{
    cin >> n >> m;
    size = m;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= m; i++)
        A[i] = t[i];
}
int parent(int i)
{
    return i/2;
}
int left(int i)
{
    return i*2;
}
int right(int i)
{
    return i*2+1;
}
/* 使以i为根节点的树保持最小堆性质 */
void min_heapify(int i)
{
    int l = left(i), r = right(i);
    int largest = 0;
    if (l <= size && A[i] > A[l])
        largest = l;
    else
        largest = i;
    if (r <= size && A[largest] > A[r])
        largest = r;
    if (i != largest)
    {
        swap(A[i], A[largest]);
        min_heapify(largest);
    }
}
/* 构建最小堆 */
void build_min_heap()
{
    for (int i = m/2; i > 0; i--)
    {
        min_heapify(i);
    }
}
/* 堆排序 */
void heap_sort()
{
    build_min_heap();
    for (int i = size; i > 1; i--)
    {
        swap(A[i], A[1]);
        size --;
        min_heapify(1);
    }
}

void solve()
{
    res = 0;
    int p = m+1;
    while (p <= n)
    {
        if (A[1] > 600)
        {
            res = -1;
            return;
        }
        A[1] += t[p++];
        min_heapify(1);
    }
    res = A[1];
}
void out()
{
    cout << res << endl;
}
int main()
{
    freopen("data", "r", stdin);
    int cas;
    cin >> cas;
    while (cas--)
    {
        load();
        build_min_heap();
        solve();
        out();
    }
    return 0;
}
