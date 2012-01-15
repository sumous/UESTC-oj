/*约瑟夫问题*/
#include <iostream>
#define DataType int
using namespace std;
typedef struct node
{
    DataType data;
    struct node *next;
}qnode;
typedef qnode* List;

void CreateList(List head, int m)//根据m建立链表
{
    List p = head;
    for(int i = 2;i <= m;i++)
    {
        List tmp = new(node);
        tmp->data = i, tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }
    p->next = head;
}

void Solve(List head, int m, int n, int k)//找出m-k个人即为应该扔下去的
{
    cout<<"应该被扔出乘客位置：";
    List p = head;
    for(int i = 0;i < m-k;i++)
    {
        for(int j = 2;j < n;j++) p = p->next;

        List tmp = p->next;
        p->next = tmp->next;
        p = p->next;
        cout<<tmp->data<<" ";

        delete tmp;
        tmp = NULL;
    }
}
int main(void)
{
    int n, m, k;
    List head = new(node);
    head->data = 1, head->next = NULL;

    cout<<"请输入乘客个数m：", cin>>m;
    cout<<"请输入出列数n：", cin>>n;
    cout<<"请输入船容量k：", cin>>k;

    CreateList(head, m);
    Solve(head, m, n, k);

    return 0;
}
