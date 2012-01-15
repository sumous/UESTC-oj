#include<stdio.h>
#include<string.h>
#define m 1000+5
int n, ini[m],  max;
int lar(int j)
{	
	if(ini[j+1] == ini[j] && j+1<n)	
		return 1;
	if(ini[j+2] == ini[j] && j+2<n)
		return 2;
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i, j;
		max = 1;
		scanf("%d",&n);
		for(i = 0;i < n;i++ ) scanf("%d",&ini[i]);
		
		for(i = 0;i < n;i ++)
		{
			int tmp1=1;
			for(j = i; j < n;j ++)
			{
				int tmp2=lar(j);
				if(tmp2 == 0) break;
				if(tmp2 == 1){tmp1++;continue;}
				if(tmp2 == 2){tmp1++;j++;}
			}
			if(tmp1>max) max=tmp1;
				
		} 
		printf("%d\n",max);
	}
	return 0;
}