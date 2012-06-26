#include <iostream>
#include <stdio.h>
using namespace std;
const int mday[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
						 {0,31,29,31,30,31,30,31,31,30,31,30,31},
						};
int y, m, d, h, c;
int cy = 2001, cm = 1, cd = 1, ch = 0;
/* 判断是否为闰年 */
bool is_leap_year(int year)
{
	return (year % 4 == 0) && ( year % 100 != 0 || year % 400 == 0 );
}
/* 天数加1，但需要判断是否月份以及年份是否超过 */
void next_day(int& ty, int& tm, int& td, int& th)
{
    th -= 8;
    td ++;
    int idx = is_leap_year(ty);
      
    if (td > mday[idx][tm])//超过当前月份的天数，转入下一个月
    {
        
        td -=  mday[idx][tm];
        tm ++;
        if (tm > 12)//超过12个月，转入下一年
        {
            tm -= 12;
            ty ++;
        }
    }
}
/* 用蔡勒公式判断是否为周末 */
bool check_weekend(int ty, int tm, int td)
{
    if (tm < 3) {tm += 12;ty--;}
    int c = int(ty / 100), y = ty - 100 * c;
    int w = int(c / 4) - 2*c +y +int(y/4) +(26 * (tm + 1)/10 ) + td - 1;
    w = ( w % 7 + 7 ) % 7;
    
    if (w == 0 || w == 6) return true;
    return false;
}
/* 加一个小时，并判断是否超过一天（8小时） */
void next_hour(int& ty, int& tm, int& td, int& th)
{
    th ++;
    if (th > 8)
    {
        next_day(ty, tm, td, th);
        while ( check_weekend(ty, tm, td) )
        {
            th += 8;
            next_day(ty, tm, td, th);
        }
    }
}
/* 对比当前时间和输入时间，若小于，则赋值为输入时间，即从输入时间开始 */
void cmp_date()
{
    if (y > cy) {cy = y; cm = m; cd = d; ch = h;}
    if (y == cy && m > cm){ cm = m; cd = d; ch = h;}
    if (y == cy && m == cm && d > cd) {cd = d; ch = h;}
    if (y == cy && m == cm && d == cd && h > ch ) ch = h;
    
}
void solve()
{
    int i;
    cmp_date();
    /* 每次增加一个小时 */
    for (i = 0; i < c; i++)
        next_hour(cy, cm, cd ,ch);
}
void load()
{
	scanf("%d/%d/%d %d %d", &y, &m, &d, &h, &c);
    /* 对输入时间进行处理，使其符合：首先必须在星期一到星期五,其次必须在 10 点到 18 点之间
 */
    if (h < 10) h = 0;
    else if (h >= 18){h = 8; next_day(y, m, d, h);}
    else h -= 10;
    while(check_weekend(y, m, d))
    {
        h = 8;
        next_day(y, m, d, h);
    }
}
void out(int i)
{
    printf("Case #%d: %d/", i, cy);
    if (cm < 10) printf("0%d/", cm);
    else printf("%d/", cm);

    if(cd < 10) printf("0%d ", cd);
    else printf("%d ", cd);

    printf("%d\n", ch+10);
}


int main()
{
	freopen("data", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		load();
		solve();
		out(i);
    }
	return 0;
}
