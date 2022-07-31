#include <iostream>

using namespace std;

int main()
{
	long long m, n, ans = 1;
	cin >> m >> n;

	//二分累乗法
	while (n > 0)
	{
		if (n & 1) ans = ans * m % 1000000007;
		m = m * m % 1000000007;
		n >>= 1;
	}

	cout << ans << endl;
}