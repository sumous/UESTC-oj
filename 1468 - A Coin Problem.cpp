#include<stdio.h>
int f[30000];
int main()
{
	int i;
	f[0] = 1;
	f[1] = 1;
	for(i = 2;i <= 29999;i ++)
	{
		f[i] = (f[i-1]+f[i-2])%10000;
	}
	long long n;
	long t;
	scanf("%ld", &t);
	while(t --)
	{
		scanf("%lld", &n);
		n %= 30000;
		printf("%d\n", f[n+1]);
	} 
	return 0;
}