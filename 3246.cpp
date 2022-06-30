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
	int n;

	while (cin >> n && n)
	{
		vi  m(2022, 0), g(2022, 0);

		rep(i, n) {
			int y;
			string c;
			cin >> y >> c >> c;
			m[y]++;
			if (c == "Gold") g[y]++;
		}

		int mans = 0, gans = 0, medal = 0, gold = 0;
		rep(i, 2022) {
			if (medal < m[i]) {
				mans = i;
				medal = m[i];
			}
			if (gold < g[i]) {
				gans = i;
				gold = g[i];
			}
		}

		cout << gans << " " << mans << endl;
	}
}