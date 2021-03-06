#include <iostream>

using namespace std;

int main()
{
	int n, a;

	cin >> n;

	auto gcm = [](auto self, int a, int b) -> int
	{
		return  a % b ? self(self, b, a % b) : b;
	};

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;

		if (i) {
			a = a * t / gcm(gcm, a, t);
		}
		else a = t;
	}

	cout << a << endl;
}