#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>

#define dbg(x) cout << #x << " = " << x << endl
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define elif else if

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

const int INF = 100100100;
const double ESP = 1e-9;


int main()
{
	vi a(4);

	auto check = [&](int fac) {
		if (a[0] % fac == 0 && a[1] % fac == 0 && a[2] % fac == 0 && a[3] % fac == 0) return true;
		return false;
	};

	while (1) {
		int sum = 0, max = 0, gcm = 1;

		for (int i = 0; i < 4; i++) {
			cin >> a[i];
			chmax(max, a[i]);
			sum += a[i];
		}

		if (!sum) break;

		for (int i = 2; i <= max; i++) {
			while (check(i)) {
				for (int j = 0; j < 4; j++) a[j] /= i;
				gcm *= i;
			}
		}

		cout << gcm << endl;
	}
}