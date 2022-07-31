#include <iostream>

using namespace std;

int main()
{
	int n;
	long long p;

	cin >> n;

	p = n;

	for (int i = 2; i * i <= n; i++) {
		
		if (n % i != 0) continue;
		
		while (!(n % i)) n /= i;
		p = p * (i - 1) / i;
	}

	if (n > 1) p = p * (n - 1) / n;

	cout << p << endl;
}