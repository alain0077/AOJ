#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int m;
	cin >> m;

	while (m--) {
		int f, y, n;
		cin >> f;
		cin >> y;
		cin >> n;

		int flag, fee, _max = 0;
		double r;
		for (int i = 0; i < n; i++) {
			cin >> flag >> r >> fee;

			int a = 0, b = 0, c = f;

			if (flag) {
				for (int j = 0; j < y; j++) {
					a = c;
					b = a * r;
					c = a + b - fee;
				}
				_max = max(_max, c);
			}
			else {
				for (int j = 0; j < y; j++) {
					a = c;
					b += a * r;
					c = a - fee;
				}
				c += b;
				_max = max(_max, c);
			}
		}
		cout << _max << endl;
	}
}