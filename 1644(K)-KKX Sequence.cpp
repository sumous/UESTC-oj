#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
long long n, a[55], res, b[55], f[55][55] = {0};

/* 初始化组合数个数的数组f */
void init()
{
    f[1][1] = 1;
    for (int i = 2; i <= 50; i++)
    {
        int sig = 1;
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = sig* ( abs(f[i-1][j-1]) + abs(f[i-1][j]) );
            sig = -sig;
        }
    }
}
void load()
{
    scanf("%lld", &n);
    for (int i = 0;i < n; i++)
        scanf("%lld", &a[i]);
}

void solve()
{
    sort(a, a+n);

    for (int i = 0; i < n; i++)
    {
        b[i] = f[n][i+1];
    }

    sort(b, b+n);
    /* 最大的和最大的相乘即可，最小的和最小的 */
    for (int i = 0; i < n; i++)
        res += a[i]*b[i];

}
void out(int c)
{
	cout << "Case #" << c << ": " << res <<endl; 
}
int main()
{
	freopen("data", "r", stdin);
    init();
	long long t;
	scanf("%lld", &t);
	for (long long i = 0; i < t; i++)
	{
		res = 0;
		load();	
		solve();
		out(i+1);
	}
	return 0;
}
