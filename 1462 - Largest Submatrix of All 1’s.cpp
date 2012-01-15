#include<stdio.h>
#include<string.h>
#define M 2000+5
int h[M];
int find_max(int n)
{
	int i, l[M], r[M], max = 0;
	h[n + 1] = h[0] = -1;
	for (i = 1; i <= n; i++) l[i] = r[i] = i;
	for (i = 1; i <= n; i++)
		while(h[l[i] - 1] >= h[i]) l[i] = l[l[i] - 1];
		
	for (i = n; i >= 1; i--)
		while(h[r[i] + 1] >= h[i]) r[i] = r[r[i] + 1];
		
	for(i = 1;i <= n;i ++)
	{
		int temp = ( r[i] - l[i] + 1)*h[i];
		if(temp > max) max = temp;
	}
	return max;
}
int main()
{
	//freopen("data.txt", "r", stdin);
	int m , n;//printf("test");
	while(scanf("%d %d", &m, &n) != EOF)
	{
		int i, j, max = 0;
		int matri[M];
		memset(h, 0, sizeof(h));
		
		for(i = 1;i <= m;i ++)
		{
			for(j = 1;j <= n;j ++)
			{
				scanf("%d", &matri[j]);
				
				if(matri[j] != 0) h[j]++;
				else h[j] = 0;
			}
				
			int temp = find_max(n);
			if(temp > max) max = temp;
		}
		
	
		printf("%d\n", max);
	}
	return 0;
}