#include<stdio.h>
#define max 100000000+5
long p, t, len, r[max],num;
void test(long result)
{
	bool flag=true;
	for(long i = 0;i < len;i ++)
	{
		if(r[i] == result) 
		{
			flag=false;
			break;
		}
	}
	r[len]=result;
	len++;
	if(flag) num++;
}
void qui_pro(long a)
{
	long result=1,x=a;
	long n=t;	
	while(n>0)
	{
		if(n%2==1) result=(result*x)%p;
		x=(x*x)%p;
		n/=2;
	}
	test(result);
	
}
int main()
{
	long T;
	r[0]=1;
	scanf("%ld",&T);
	while(T--)
	{
		len = 1;
		num=1;
		scanf("%ld%ld", &p, &t);
		if(t==0){printf("1\n");continue;}
		int flag=(int)(t%2);
		for(long i = 1;i < p/2+1;i ++)
		{
			qui_pro(i);
		}
		if(flag ==1)
			for(long i = p/2+1;i < p;i ++)
			{
				test(p-r[p-i]);
			}
		printf("%ld\n",num);
	}
	return 0;
}