#include<stdio.h>
#include<math.h>
#include <iostream>
using namespace std;
int main()
{
	int T;
//	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	while(T --)
	{
		double x1, y1, x2, y2, n, h, x0;
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		scanf("%lf%lf", &n ,&h);
		if((y1 <= y2)) 
		{
			printf("Impossible\n");
			continue;
		}
		if(x1 == x2)
		{
			printf("%.3lf\n", x1);
			continue;
		}
		
		double k, sib, sia, tanb,ans;
		k = (y1-y2)/(x1-x2);
		x0 = (h - y1)/k+x1;
	double drx=x2-x1,dry=y2-y1;
	double	r=sqrt(drx*drx+dry*dry);
            if(k>0)
            {
                sia=-drx/r;
                sib=sia/n;
                ans=x0-sib*h/sqrt(1-sib*sib);
            }
            else if(k<0)
            {
                sia=drx/r;
                sib=sia/n;
                ans=x0+sib*h/sqrt(1-sib*sib);
            }
            printf("%.3lf\n",ans);
	}
	return 0;
}