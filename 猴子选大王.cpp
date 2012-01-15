#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
int key;
struct node *pre,*next;
}linklist;

int main()
{
	int m,n,k,i,total;// m:乘客数 n:出列号
	linklist *head,*p,*q;
	//head 记录链表头指针 p作为循环指针 s作为临时指针，用于释放p空间 q作为辅助指针，协助删除节点

    printf("请输入乘客个数m：");
    scanf("%d", &m);
    printf("请输入出列号n:");
    scanf("%d", &n);
    printf("请输入船容量k：");
    scanf("%d", &k);

    total=m-k;
    head = (node *)malloc(sizeof(node));
    p = head;
    p->key = 1;
	p->next = NULL;// 前驱和后缀结点都暂时为null
	p->pre = NULL;
	/*初始化循环链表*/
	for(i = 2;i <= m;i++)
	{

        linklist *s;
        s = (node*)malloc(sizeof(node));
		s->key = i;

		s->pre = p;
		p->next = s;
		p = p->next;
	}
	p->next = head;//首尾连接
	head->pre = p;

	p = head;
	q = head;
	while(total != 0)
	{
        for(i = 1;i < n;i++)
        {
            p = p->next;
        }
        q = p->pre;
        q->next = p->next;
        p->next->pre = q;
        linklist *s = p;
        p = p->next;
        free(s);
        s = NULL;
        total--;
    }

	/*
	** 输出剩下的k个乘客
	*/

	total = k;
    printf("剩余乘客位置：");
    while(total)
    {
        printf("%d ", p->key);
        p = p->next;
        total--;
    }
	return 0;
}
