#include <iostream>
using namespace std;

void dp()
{
    /* 计算sum[i][j] */
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            sum[i][j] = sum[i][j-1] + s[j];
        }
    }
    /* 计算d[i][j] */
    for (int i = 1; i <= n; i++) d[i][i] = s[i];
    for (int i = n; i > 0; i--)
        for (int j = i+1;j <= n; j++)
        {
            //if(i == j) continue;
            d[i][j] = sum[i][j] - min(d[i][j-1], d[i+1][j]);
        }
}
