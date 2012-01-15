#include<stdio.h>
#include<string.h>
#define MAX 65536
int is_vis[MAX];
int que[MAX*2];
int step[MAX];

int main()
{//freopen("data.txt","r", stdin);
	int ini = 0;
	int front = 0, rear = 0;
	int i,j;
	char str[5];
	memset(is_vis, 0, sizeof(is_vis));
	for(i = 0;i < 4;i ++)
	{
		scanf("%s", str);
		for(j = 0;j < 4;j ++)
		{
			if(str[j] == 'w')
			{
				ini += 1<<(i * 4 + j);	
			}
		}
	}//printf("%o", ini);
	if(ini==0||ini==65535){printf("0\n");return 0;}
	que[rear++] = ini;
	is_vis[ini] = 1;
	step[ini] = 0;
	while(front < rear)
	{
		int temp = que[front++];
		ini = temp;
		for(i = 0;i < 4;i ++)
			for(j = 0;j < 4; j++)
			{
				temp = ini;
				if(i == 0) temp ^= 1<<(j+4);//翻转它下面一个 
				else if(i == 3) temp ^= 1<<(8+j);//翻转上面一个 
				else//翻转上下两个 
				{
					temp ^= 1<<(4*i-4+j);
					temp ^= 1<<(4*i+4+j);
				} 
				
				if(j == 0) temp ^= 3<<(4*i);//翻转它及右边一个 
				else if(j == 3) temp ^= 3<<(4*i+2);//翻转它及左边一个 
				else temp ^= 7<<(4*i+j-1);//翻转它及左右两个
				
				if(temp == 0||temp == 65535)
				{
					printf("%d\n", step[ini]+1);
					return 0;
				} 
				if(!is_vis[temp])
				{				
					step[temp] = step[ini]+1;
					is_vis[temp] = 1;
					que[rear++] = temp;
				}
			}
	}
	printf("Impossible\n");
	return 0;
}