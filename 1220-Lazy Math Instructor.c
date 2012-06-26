/**
 * 1220-Lazy Math Instructor
 * 应该说是比较简单的栈题,但是花了比较长时间,需要兼顾的问题比较多
 */
# include <stdio.h>
# include <string.h>
char str[2][81];
int res[2];
int num[81];
char op[81];

void solve(int i)
{
    int n = strlen(str[i]);
    int j, top1 = 0, top2 = 0;
    op[top2++] = '#';
    for (j = 0; j < n; j++)
    {
        int flag = 0;
        char ch = str[i][j];
        if ('0' <= ch && ch <= '9')
        {
            num[top1++] = ch - '0';
            flag = 1;
        }
        else if ( ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') )
        {
            if (ch < 'a')
                num[top1++] = ch - 'A' + 1;
            else
                num[top1++] = ch - 'a' + 1;
            flag = 1;
        }
        else
        {
            switch(ch)
            {
                
            case '(':
            case '-':
            case '*':
            case '+':
            {
                op[top2++] = ch;
                break;
            }
            case ')':
            {
                top2--;
                flag = 1;
                break;
            }
            
            }
        }
        /*当ch为数字,字母,右括号时,需要进行计算*/
        while (flag)
        {
            switch(op[top2-1])
            {
            case '*':
            {
                int num1 = num[--top1];
                int num2 = num[--top1];
                num[top1++] = num1 * num2;
                top2--;
                break;
            }
            case '-':
            {
                int num1 = num[--top1];
                int num2 = num[--top1];
                num[top1++] = num2 - num1;
                top2--;
                break;
            }
            case '+':
            {
                int num1 = num[--top1];
                int num2 = num[--top1];
                num[top1++] = num1 + num2;
                top2--;
                break;
            }
            }

            if (op[top2-1] == '+' || op[top2-1] == '-' || op[top2-1] == '*')
                flag = 1;
            else flag = 0;
        }
    }
    res[i] = num[0];
}
void out()
{
    (res[0] == res[1]) ? printf("YES\n") : printf("NO\n");
}
int main()
{
    freopen("data", "r", stdin);
    int cas;
    scanf ("%d", &cas);
    getchar();
    while (cas --)
    {
        gets(str[0]);
        gets(str[1]);
        solve(0);
        solve(1);
        out();
    }
    return 0;
}
