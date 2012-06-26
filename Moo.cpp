#include <iostream>
#include <cmath>
using namespace std;
long n, cur = 1;
long S(long k)
{
	return pow(2, k+3) - 5 - k;
}
bool solve(long n)
{
	long k;
	long len;
	for (k = 0; ; k++)
	{
		len = S(k);
		if (len > n) break;
	}
//	cout<<k<<endl;
	len = S(k-1);
	n -= len;
	if (n == 1) return true;
	else if (n < k+3) return false;
	else return solve(n-k-3);
}
int main()
{
	cin>>n;
	if ( solve(n) ) cout<<"m"<<endl;
	else cout<<"o"<<endl;
	return 0;
}
