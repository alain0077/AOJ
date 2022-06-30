#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-4;

struct Coor {
	double x, y;
};

double pw(double x) { return x * x; };
int max(int n, int m) { return n > m ? n : m; };

int main()
{
	double n;
	vector<Coor> v(300);

	while (cin >> n) {
		if (n == 0) break;

		

		for (int i = 0; i < n; i++) {
			cin >> v.at(i).x >> v.at(i).y;
		}

		double x1, y1, x2, y2;
		int _max = 1;

		Coor mid;

		for (int i = 0; i < n-1; i++) {
			x1 = v.at(i).x; y1 = v.at(i).y;

			for (int j = i + 1; j < n; j++) {
				x2 = v.at(j).x; y2 = v.at(j).y;
				mid.x = (x1 + x2) / 2;
				mid.y = (y1 + y2) / 2;

				double d = sqrt(pw(x1 - x2) + pw(y1 - y2));
				double dx = sqrt(1 - pw(d / 2)) * (y1 - y2) / d;
				double dy = sqrt(1 - pw(d / 2)) * (x2 - x1) / d;

				int ct1 = 0, ct2 = 0;

				for (int k = 0; k < n; k++) {
					double tmp = pw(v.at(k).x - (mid.x + dx)) + pw(v.at(k).y - (mid.y + dy));
					if (sqrt(tmp) <= 1.0 + EPS) ct1++;

					tmp = pw(v.at(k).x - (mid.x - dx)) + pw(v.at(k).y - (mid.y - dy));
					if (sqrt(tmp) <= 1.0 + EPS) ct2++;
				}

				_max = max(_max, ct1);
				_max = max(_max, ct2);
			}
		}

		cout << _max << endl;
	}
}