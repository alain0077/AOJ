#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m;

	while (cin >> n >> m) {
		if (!n && !m) break;

		int _max = 0;
		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a.at(i);
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a.at(i) + a.at(j) <= m)
					_max = max(_max, a.at(i)+a.at(j));
			}
		}

		if (!_max)
			cout << "NONE" << endl;
		else
			cout << _max << endl;;
	}
}