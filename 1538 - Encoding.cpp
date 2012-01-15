#include<stdio.h>
#include<string.h>
const char letter[][6]={"00001","00010","00011","00100","00101","00110","00111",
						"01000","01001","01010","01011","01100","01101","01110",
						"01111","10000","10001","10010","10011","10100","10101",
						"10110","10111","11000","11001","11010"};
int c,r;
char ch[85];
char res[21][21];
bool vis[21][21];

void fill(char* f, int len)
{
	int x=0,y=-1;
	int i = 0;
	while(i<len)
	{//printf("test");
		while(y+1<c && !vis[x][y+1] && i<len){vis[x][++y]=true;res[x][y]=f[i++];}
		while(x+1<r && !vis[x+1][y] && i<len){vis[++x][y]=true;res[x][y]=f[i++];}
		while(y-1>=0 && !vis[x][y-1] && i<len){vis[x][--y]=true;res[x][y]=f[i++];}
		while(x-1>=0 && !vis[x-1][y] && i<len){vis[--x][y]=true;res[x][y]=f[i++];}
	}	
}
int main()
{
//	freopen("data.txt","r",stdin);
	int t, i, j;
	
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{char f[405];
		memset(res,'0',sizeof(res));
		memset(vis,false,sizeof(vis));
		scanf("%d %d",&r,&c);
		getchar();
		gets(ch);

		for( i = 0,j=0;i < strlen(ch);i++)
		{
			if(ch[i]==' ') for(int k = 0;k < 5;k++) f[j++]='0';
			else
				for(int k = 0;k < 5;k++)
					f[j++]=letter[ch[i]-'A'][k];
		}	
		fill(f, i*5);	
		printf("%d ",cas);
		for( i = 0;i < r;i++)
			for( j = 0;j < c;j++)
				putchar(res[i][j]);
		putchar('\n');
	}
	return 0;
}