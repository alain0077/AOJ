#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int m, nmax, nmin;

	while (cin >> m >> nmin >> nmax) {
		if (!m && !nmin && !nmax) break;

		int _max = 0;
		int ans = 0;
		vector<int> p(m);

		for (int i = 0; i < m; i++) {
			cin >> p.at(i);
		}

		for (int i = nmin-1; i < nmax; i++) {
			if (_max <= p.at(i) - p.at(i + 1)) {
				_max = p.at(i) - p.at(i + 1);
				ans = i;
			}
		}

		cout << ans+1 << endl;
	}
}