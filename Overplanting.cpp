#include <iostream>
using namespace std;
#define MAX 10000
#define MIN -10000
struct Rectangle
{
	int x1, y1, x2, y2;
}rec[10];
int n, ulx = MAX, uly = MIN, lrx = MIN, lry = MAX, res = 0;

void find_edge(int x1, int y1, int x2, int y2)
{
	ulx = min( min(x1, x2), ulx );
	uly = max( max(y1, y2), uly );
	lrx = max( max(x1, x2), lrx );
	lry = min( min(y1, y2), lry );
}

void load()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> rec[i].x1 >> rec[i].y1
			 >> rec[i].x2 >> rec[i].y2;
		find_edge(rec[i].x1, rec[i].y1, rec[i].x2, rec[i].y2);
	}
}
bool is_ok(int i, int x, int y)
{
	if ( (x>=rec[i].x1) && (x<rec[i].x2) && (y>rec[i].y2) && (y<=rec[i].y1))
		return true;
	else return false;
}
bool is_grass(int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		if (is_ok(i, x, y)) return true;
	}
	return false;
}
void solve()
{
	for (int i = ulx; i < lrx; i++)
		for (int j = lry+1; j <= uly; j++)
			if ( is_grass(i, j) ) res++;
}
int main()
{
	load();
	solve();
	cout << res << endl;
  	return 0;
}
