#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	//freopen("data.txt", "r", stdin);
	char course[105][105], cur[105];
	int T, n, score[105], cur_score;
	scanf("%d", &T);
	while(T --)
	{
		int count = 0, i, len = 0;
		scanf("%d", &n);
		getchar();
		n --;
		scanf("%s%d", course[0], &score[0]);
		course[0][strlen(course[0])] = '\0';
		while(n --)
		{
			scanf("%s%d",cur, &cur_score);
		//	printf("%s %d\n", cur, cur_score);
			cur[strlen(cur)] = '\0';
			int flag = 0;
			for(i = 0;i < len + 1;i ++)
			{
				if(strcmp(cur, course[i]) == 0)
				{
					flag = 1;
					if(cur_score > score[i])
					{
						score[i] = cur_score;
						count ++;						
						break;
					}					
				}
			}
			
			if(flag == 0)
			{//puts(cur);
				strcpy(course[++len], cur);
				score[len] = cur_score;
			}
			
		}
		printf("%d\n", count);
	}
	return 0;
}