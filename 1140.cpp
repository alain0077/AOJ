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

int dx[] = { 1,0,-1,0 }, dy[] = { 0,-1,0,1 };

int main()
{
	int w, h;

	while (cin >> w >> h && w) {
		pi s;
		vector<pi> g;
		vector<string> map(h);

		rep(i, h) {
			cin >> map[i];
			rep(j, w) {
				if (map[i][j] == 'o') s = mp(i, j);
				if (map[i][j] == '*') g.pb(mp(i, j));
			}
		}

		int size = g.size();
		vi dr(size);
		vii dist(size, vi(size));
		auto check = [&](int x, int y) {return 0 <= x && x < h && 0 <= y && y < w&& map[x][y] != 'x'; };

		rep(i, size) {
			vii bfs(h, vi(w, INF));
			bfs[g[i].fi][g[i].se] = 0;

			queue<pi> q;
			q.push(g[i]);

			while (q.size())
			{
				pi pos = q.front();
				q.pop();

				int x = pos.fi, y = pos.se;

				rep(t, 4) {
					if (check(x + dx[t], y + dy[t]) && bfs[x + dx[t]][y + dy[t]] == INF) {
						bfs[x + dx[t]][y + dy[t]] = bfs[x][y] + 1;
						q.push(mp(x + dx[t], y + dy[t]));
					}
				}

				dr[i] = bfs[s.fi][s.se];
				rep(j, size) dist[i][j] = bfs[g[j].fi][g[j].se];
			}
		}

		int B = (1 << size);
		vii dp(B, vi(size, INF));
		rep(i, size) dp[(1 << i)][i] = dr[i];
		rep(i, B) rep(j, size) rep(k, size) if (!(i & (1 << k))) dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist[j][k]);

		int ans = INF;
		rep(i, size) chmin(ans, dp[(1 << size) - 1][i]);

		if (ans >= INF) ans = -1;
		cout << ans << endl;
	}
}