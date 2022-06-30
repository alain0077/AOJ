#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	while (cin >> n) {
		if (!n) break;

		int a, s = 0, c = 0;
		vector<int> v;

		for (int i = 0; i < n; i++) {
			cin >> a;
			s += a;
			v.push_back(a);
		}

		s = s / v.size();
		
		for (int i = 0; i < n; i++) {
			if (v.at(i) <= s)
				c++;
		}

		cout << c << endl;
	}
}