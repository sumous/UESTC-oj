#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct team
{
	char id[25];
	long s;
	long p;
};

bool cmp(team a, team b)
{
	if(a.s > b.s) return true;
	if(a.s == b.s && a.p < b.p) return true;
	if(a.s == b.s && a.p == b.p)
	{
		if(strcmp(a.id, b.id) < 0) return true;
	}
	return false;
}
int main()
{
	//freopen("data.txt", "r", stdin);
	int T, n, i;
	//char rank[25];
	scanf("%d", &T);//printf("tesy");
	while(T --)
	{
		struct team t[105];
		scanf("%d", &n);
		getchar();
		for(i = 0;i < n;i ++)
			scanf("%s%ld%ld", t[i].id, &t[i].s, &t[i].p);
			
		sort(t, t+n, cmp);
		
		printf("%s\n", t[0].id);
	}
	return 0;
}