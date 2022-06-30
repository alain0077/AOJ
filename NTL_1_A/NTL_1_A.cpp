#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	cout << n << ":";

	for (int i = 2; i * i <= n; i++) {
		while (!(n % i))
		{
			n /= i;
			cout << " " << i;
		}
	}

	if(n > 1) cout << " " << n;

	cout << endl;
}