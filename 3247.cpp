#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <iomanip>

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
	while (cin >> h >> w && h && w) {
		double xs = 0, ys = 0, a = 0;
		for (int i = 0; i < h; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < w; ++j) {
				int v = (s[j] - '0');
				xs += v * (i + 1);
				ys += v * (j + 1);
				a += v;
			}
		}
		cout << fixed << setprecision(9) << xs / a << " " << ys / a << endl;
	}
}