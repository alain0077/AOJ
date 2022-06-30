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
using vii = vector<vi>;

const int INF = 100100100;
const double ESP = 1e-9;

int main()
{
	int H, W;

	while (cin >> H >> W && H)
	{
		int ans = 0;
		vii b(H, vi(W, 0));

		rep(i, H)rep(j, W) cin >> b[i][j];

		rep(bit, 1 << H) {
			auto b2 = b;
			rep(i, H) {
				if (!(bit & (1 << i))) continue;
				rep(j, W) b2[i][j] = 1 - b2[i][j];
			}

			int t = 0;
			rep(j, W) {
				int cnt = 0;
				rep(i, H) {
					if (b2[i][j] == 0) cnt++;
				}
				t += max(cnt, H - cnt);
			}
			ans = max(ans, t);
		}
		cout << ans << endl;
	}
}