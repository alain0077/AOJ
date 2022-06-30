#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

#define dbg(x) cout << #x << " = " << x << endl
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using pi = pair<int, int>;

const int INF = 100100100;
const double ESP = 1e-9;

const int N = 11;
const int M = 21;


int main()
{
	int W, D;

	while (cin >> W >> D) {
		if (!W && !D) break;

		int ans = 0;
		int x[N], y[N];

		rep(i, W) cin >> x[i];
		rep(i, D) cin >> y[i];

		rep(i, W) {
			ans += x[i];
			rep(j, D) {
				if (x[i] == y[j]) {
					y[j] = 0;
					break;
				}
			}
		}

		rep(i, D) ans += y[i];

		cout << ans << endl;
	}
	return 0;
}