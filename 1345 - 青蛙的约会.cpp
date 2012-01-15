#include<stdio.h>
void e_gcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0){x=1;y=0;return;}
	e_gcd(b,a%b,x,y);
	long long temp=x;
	x=y;
	y=temp-(a/b)*y;
	return;
} 
int main()
{
	long long x, y, m, n, L;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L)!=EOF)
	{
		if(m==n) {printf("Impossible\n");continue;}
		x=(x-y+L)%L;m=(m-n+L)%L;
		long long k=0,t=0;
		e_gcd(m,L,k,t);
		if(k<0) k+=L;
		printf("%lld\n",k);
		
	}
	return 0;
}