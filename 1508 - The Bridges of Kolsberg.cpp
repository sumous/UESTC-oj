#include<stdio.h>
#include<string.h>
struct point
{
	char os[13];
	long val;
}key[3][1005];
long d[1005][1005];
long bri[1003][1003];

long min(long a, long b)
{
	return (a>b)?b:a; 
}

long same(int a, int b)//相同则返回权值和，否则返回0 
{
	return (strcmp(key[1][a].os,key[2][b].os)==0)?(key[1][a].val+key[2][b].val):-1;
}

long dp(int a, int b)
{ 
	long& ans=d[a][b];
	long& p=bri[a][b];
	if(ans!=-1) return ans;
	if(a==0 || b==0) return 0;
	long s=same(a,b);
	long tmp1=dp(a-1,b-1),tmp2=dp(a,b-1),tmp3=dp(a-1,b);
	long tmpd,tmpb;

	if (s!=-1)
	{
		tmp1+=s;
		if (tmp1>ans)
		{
			ans=tmp1;
	  		p=bri[a-1][b-1]+1;
		}
		    		
	}
	if (tmp2>tmp3)
	{
		tmpd=tmp2;
		tmpb=bri[a][b-1];
	}
	else if (tmp2<tmp3)
	{
		tmpd=tmp3;
		tmpb=bri[a-1][b];
	}
	else
	{		
		tmpd=tmp2;
		tmpb=min(bri[a-1][b],bri[a][b-1]);
	}
	if ((tmpd>ans)||(ans==tmpd && tmpb<p))
	{
		ans=tmpd;
		p=tmpb;
	}	
	return ans;
}
int main()
{
//	freopen("data.txt","r", stdin);
	int t;
	char ch[20];
	scanf("%d",&t);
	while(t--)
	{
		memset(d, -1, sizeof(d));
		memset(bri,0,sizeof(bri));
		int n[3];
		for(int i = 1 ;i <= 2;i++)
		{
			scanf("%d",&n[i]);
			for(int j = 1;j <= n[i];j ++)
				scanf("%s %s %ld",ch,key[i][j].os,&key[i][j].val);
		}
		long t=same(1,1);//起始步 
		if(t!=1)
		{
			d[1][1]=t;
			bri[1][1]=1;
		}
		long tmp=dp(n[1],n[2]);
		printf("%ld %ld\n", tmp, bri[n[1]][n[2]]);
	//	printf("%ld\n",bri[1][1]);
	}
	return 0;
}