/**
* 1219 - Web Navigation
**/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const char back[]="BACK",forward[]="FORWARD",visit[]="VISIT",quit[]="QUIT";
char order[10], url[105];
int cur_place = 0;

typedef struct qnode
{
	 char url[105];
	int place;
	struct qnode *next;
	struct qnode *prev;
}node;
typedef node* List;
List q;

void Insert()//插入一个结点 
{
	List p;
	if(!(p = (qnode *)malloc(sizeof(qnode))))
	{
		printf("内存分配失败");
		exit(0);
	}
	strcpy(p->url,url);
	p->place = q->place+1;
	p->prev = q;
	p->next= NULL; 
	q->next = p;
	q = p; 
	cur_place = p->place;
}

void Delete()//删除q以后的所有结点 
{
	if(q->next == NULL) return;
	
	List p = q->next;
	while(p != NULL)
	{
		List temp = p;
		p = temp->next;
		free(temp);
	}
	q->next = NULL;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	q = (qnode *)malloc(sizeof(qnode));
	q->place = 1;
	strcpy(q->url, "http://www.acm.org/");//初始化 
	q->prev= NULL;
	q->next= NULL;
	
	scanf("%s", order);
	while(order[0] != 'Q')
	{
		
		//puts(order);
		if(strcmp(order, visit) == 0)
		{
			getchar();
			Delete();
			scanf("%s", url);
			Insert();
			printf("%s\n", q->url);
			scanf("%s", order);
			continue;
		}
		
		if(strcmp(order, back) == 0)
		{//printf("%s %s\n", order, q->url);
	
			if(q->place == 1)
			{
				printf("Ignored\n");
				scanf("%s", order);
				continue;
			}
			
			q = q->prev;
			printf("%s\n", q->url);
			scanf("%s", order);
			continue;
		}
		
		if(strcmp(order, forward) == 0)
		{
			if(q->place == cur_place)
			{
				printf("Ignored\n");
				scanf("%s", order);
				continue;
			}
			
			q = q->next;
			printf("%s\n", q->url);
			scanf("%s", order);
			continue;
		}
	//	printf("test%s", q->url );
		getchar();
	}
	return 0;
}
