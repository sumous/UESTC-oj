#include<stdio.h>
int main()
{
	long a[100005];
	a[0] = 1;a[1] = 2;
	for(long i = 2;i <= 100000;i ++)
	{
		a[i] = (a[i-1] +a[i-2])%10007;
	}
	long n;
	while(scanf("%ld", &n) != EOF)
		printf("%ld\n", a[n]);
	return 0;
}	