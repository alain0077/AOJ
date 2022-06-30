#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

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

const int INF = 100100100;
const double ESP = 1e-9;


int main()
{
	int h, w;
	string s;
	map<char, pi> r;

	while (cin >> h >> w && h && w) {
		rep(i, h) {
			rep(j, w) {
				char c;
				cin >> c;
				if (c != '_') r[c] = { i,j };
			}
		}

		cin >> s;

		int ans = 0;
		pi p = { 0,0 };

		for (auto c : s) {
			ans += abs(p.fi - r[c].fi) + abs(p.se - r[c].se) + 1;
			p.fi = r[c].fi;
			p.se = r[c].se;
		}

		cout << ans << endl;
	}
}