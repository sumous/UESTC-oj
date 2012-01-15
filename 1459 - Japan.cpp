#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define M 1000005
struct node 
{
	long x, y;
}tree[M];

long long c[10010];

long long tot;

bool comp(struct node a, struct node b)
{
	if(a.y > b.y) return true;
 	if(a.x > b.x && a.y == b.y) return true;

	return false;
}
long long query(long k)
{
	long long sum=0; 
	while (k>0) 
	{ 
		sum += c[k]; 
		k-=k&(-k); 
	} 
	return sum; 
}

void update(long k) 
{ 
	while (k<=10010) 
	{ 
		c[k]++; 
		k+=k&(-k); 
	} 
}
int main()
{
	//freopen("data.txt", "r", stdin);
	long t, i;
	long n, m, j;
	scanf("%ld", &t);
	for(i = 1;i <=  t;i ++)
	{
 		long long max = 0;
		scanf("%ld%ld%lld", &n, &m, &tot);
		
		for(j = 1;j <= tot;j ++)
			scanf("%ld%ld", &tree[j].x, &tree[j].y);
		memset(c, 0, sizeof(c));
		sort(tree+1, tree+tot+1, comp);
		
		for(j = 1;j <= tot;j ++)
		{
			max += query(tree[j].x-1);
			update(tree[j].x);		
		}
		printf("Test case %ld: %lld\n", i, max);
	}
	return 0;
}