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
	int m,n,k,i,total;// m:�˿��� n:���к�
	linklist *head,*p,*q;
	//head ��¼����ͷָ�� p��Ϊѭ��ָ�� s��Ϊ��ʱָ�룬�����ͷ�p�ռ� q��Ϊ����ָ�룬Э��ɾ���ڵ�

    printf("������˿͸���m��");
    scanf("%d", &m);
    printf("��������к�n:");
    scanf("%d", &n);
    printf("�����봬����k��");
    scanf("%d", &k);

    total=m-k;
    head = (node *)malloc(sizeof(node));
    p = head;
    p->key = 1;
	p->next = NULL;// ǰ���ͺ�׺��㶼��ʱΪnull
	p->pre = NULL;
	/*��ʼ��ѭ������*/
	for(i = 2;i <= m;i++)
	{

        linklist *s;
        s = (node*)malloc(sizeof(node));
		s->key = i;

		s->pre = p;
		p->next = s;
		p = p->next;
	}
	p->next = head;//��β����
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
	** ���ʣ�µ�k���˿�
	*/

	total = k;
    printf("ʣ��˿�λ�ã�");
    while(total)
    {
        printf("%d ", p->key);
        p = p->next;
        total--;
    }
	return 0;
}
