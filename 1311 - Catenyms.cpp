#include<stdio.h>
#include<string.h>

#include<algorithm>
using namespace std;
struct edge
{
	char s[21];
	int st,en;
}e[1001];
bool vis[1001];
int n, st,en;
int in[27],out[27],res[1001];
bool cmp(struct edge a, struct edge b)
{
	if(strcmp(a.s,b.s)>0) return false;
	return true;
}
int Euler()
{
	st=-1,en=-1;
	for(int i=0;i < 26;i++)
	{
		if(in[i]==0 && out[i]==0) continue;
		if(in[i] > out[i]+1 || out[i]>in[i]+1) return 0;		
		if(in[i]==out[i]+1){if(st!=-1) return 0;else st=i;}
		if(out[i]==in[i]+1){if(en!=-1) return 0;else en=i;}
		
	}
	if((st!=-1 && en==-1) || (st==-1 && en!=-1) ) return 0;
	if(st==-1 && en==-1) return 2;
	return 1;
}
bool dfs(int source,int t)
{
	if(t==n) return true;
	
	for(int i = 0;i<n;i++)
	{
		if(vis[i]) continue;		
		if(e[i].st==source) 
		{
			res[t]=i;
			vis[i]=true;
			if(dfs(e[i].en,t+1)) return true;
			vis[i]=false;
		}
	}
	return false;
}

int main()
{
	int t;
//	freopen("data.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,false,sizeof(vis));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%s",e[i].s);
			e[i].st=e[i].s[0]-'a';
			e[i].en=e[i].s[strlen(e[i].s)-1]-'a';
			in[e[i].st]++;
			out[e[i].en]++;
		}
		int flag=Euler();
		if(flag==0) printf("***");
		else 
		{
			sort(e,e+n,cmp);
			if(flag==2) st=en=e[0].st;
			if(!dfs(st,0)) printf("***");
			else
			{
				printf("%s",e[res[0]].s);
				for(int i = 1;i<n;i++)
					printf(".%s",e[res[i]].s);
			}
		}
		putchar('\n');
	}
	return 0;
}
