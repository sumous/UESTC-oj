#include<stdio.h>
#include<string.h>
#define max 362880

int par[8];
const int move[4] = {}
bool vis[max+5];
long pack(int* s)
{
	int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};
	int res = 0;
	
}

void depack()
{}
int main()
{
	while(scanf("%s", s) != EOF)
	{
		char s[20]
		long cur;
		memset(vis, false, sizeof(vis));
		int j = 0;
		for(int i = 0;i < 17;i += 2)
		{
			if(s[i] != 'x')
				par[j++] = s[i] - '0';
			else
				par[j++] = 0;
		}
		cur = pack(s);
		head[hfront++] = cur;
		vis[cur] = true;
	}
	return 0;
}