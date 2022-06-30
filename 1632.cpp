#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m;

	while (cin >> n >> m) {
		if (!n && !m) break;

		int _max = 0, p;
		vector<int> sum(n);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> p;
				sum[j] += p;
			}
		}

		for (auto s : sum) _max = max(_max, s);

		cout << _max << endl;;
	}
}