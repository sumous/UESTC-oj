#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct postion
{
	int x,y;
}p[1000001];
long long tot,tree[1000001],coun[10001];
struct IcmpMuls
{
bool operator()(postion a,postion b)
{
	if (a.y > b.y) 
		return true;
	if (a.y == b.y)
		if (a.x > b.x)
		    return true;
	return false;
}
} myobject;
void update(int k,int val)
{
	
	while(k <= tot)
	{
		tree[k] += val;
		k += k&(-k);
	}
}

void create_point(int x)
{
	while(x <= 10000)
	{
		coun[x]++;
		x += x&(-x);
	}
}

long long ask_point(int x)
{
	long long sum = 0;
	while (x > 0)
	{
		sum += coun[x];
		x -= x&(-x);
	}
	return sum;
}

long long query(int k)
{
	long long sum = 0;
	while(k > 0)
	{
		sum += tree[k];
		k -= k&(-k);
	}
	return sum;
}



int main()
{
	int T,n,m,i,j;
	long long tt,ans;
	freopen("data.txt","r",stdin);
	scanf("%d",&T);
	for(int cas = 1;cas <= T;cas++)
	{
		memset(tree,0,sizeof(tree));
		memset(coun,0,sizeof(coun));
		scanf("%d%d%d",&n,&m,&tot);
		for(i = 1;i <= tot;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p+1,p+tot+1,myobject);

		for(i = 1;i <= tot;i++)
		{
			tt = ask_point(p[i].x - 1);
			create_point(p[i].x);
			update(i,tt);
			printf("%lld\n",tt);
		}
		ans = query(tot);
		printf("Test case %d: %lld\n",cas,ans);
		
	}
	return 0;
} 

