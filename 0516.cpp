#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k;

	while (cin >> n >> k) {
		if (!n && !k) break;

		int _max = 0;
		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a.at(i);
		}

		for (int i = 0; i < n-k+1; i++) {
			int sum = 0;
			for (int j = 0; j < k; j++) sum += a[i + j];
			_max = max(_max,sum);
		}

		cout << _max << endl;
	}
}