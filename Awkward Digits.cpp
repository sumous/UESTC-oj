#include <iostream>
#include <cstring>
using namespace std;
char base2[32], base3[32];
long n, len2, len3;
const char chg[][2] = {{'1','2'},{'0','2'},{'0','1'}};

long _to10(long b, char base[32], long len)
{
	long a = 1, res = 0;
	for (int i = len-1; i >= 0; i--)
	{
		res += (base[i]-'0') * a;
		a *= b;
	}
	return res;
}
bool is_ok()
{
	long n2 = _to10(2, base2, len2), n3 = _to10(3, base3, len3);
	if ( n2 == n3 )
	{
		n = n2;
		return true;
	}
	else return false;
}
void solve()
{
	for (int i = 0; i < len2; i++)
	{
		base2[i] = !(base2[i] - '0') + '0';
		for (int j = 0; j < len3; j++)
		{
			char ch = base3[j];
			for (int k = 0; k < 2; k++)
		  	{
		  		base3[j] = chg[ ch - '0' ][k];
		  		if (is_ok()) return;
		  	}
		  	base3[j] = ch;
  
		}
		base2[i] = !(base2[i] - '0') + '0';
	}
}
int main()
{
	cin >> base2 >> base3;
	len2 = strlen(base2), len3 = strlen(base3);
	solve();
	cout << n << endl;
	return 0;
}
