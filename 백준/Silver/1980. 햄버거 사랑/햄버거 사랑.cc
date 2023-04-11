#include<iostream>
using namespace std;

int n, m, t, i, r1, r2;

int main()
{
	cin >> n >> m >> t; r2 = t;

	for (; n * i <= t; i++)
	{
		int k = t - n * i;
		int p = k / m, q = k % m;
		if (q <= r2)
			q == r2 ? (r1 = max(r1, i + p)) : (r1 = i + p, r2 = q);
	}
	cout << r1 << ' ' << r2;
}