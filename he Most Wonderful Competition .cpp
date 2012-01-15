#include<stdio.h>
#include<string.h>
#define m 65536
double dn[m+5];
double a[17][17];
int n;
double max(double a, double b)
{
	return a>b?a:b;
}
double d(int i)
{
	if(dn[i] != -1.0) return dn[i];
//	dn[i] = 0.0;
	for(int j = 0;j < n;j ++)
		for(int k = j+1;k < n;k ++)
		{
			if((i&(1<<j))>0 && (i&(1<<k))>0 )
			{
				int cur = i^(1<<j)^(1<<k);
				dn[i] = max(d(cur)+a[j][k],dn[i]);
			}
		}
	return dn[i];
}
int main()
{
//	freopen("data.txt","r",stdin);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		
		scanf("%d",&n);
		int M = 1<<n;
		for(int i = 0;i < M;i ++) dn[i] = -1.0;//³õÊ¼»¯ 
		dn[0] = 0.0;
		
		for(int i = 0;i < n;i ++)//ÊäÈë 
			for(int j = 0;j < n;j ++)
				scanf("%lf", &a[i][j]);
		
		
		printf("%.2lf\n", d((1<<n)-1));
	}
}