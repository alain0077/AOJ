#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>

#define dbg(x) cout << #x << " = " << x << endl
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define fs first
#define sn second
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;

const int INF = 100100100;
const double ESP = 1e-9;

int H, W, K,
dfs[1000][1000],
dist[20][20],
dx[] = { 1,0,-1,0 }, dy[] = { 0,-1,0,1 },
dp[1 << 20][20],
dS[20],
dG[20];
string Map[1002];
vector<pi> ap;
pi	s, g;


int  bit_count (int bits) {
	bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
	bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
	bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
	bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
	return (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
}


int main()
{
	auto check = [&](int x, int y) {return 0 <= x && x < H && 0 <= y && y < W && Map[x][y] != '#'; };


	cin >> H >> W >> K;

	rep(i, H) {
		cin >> Map[i];
		rep(j, W) {
			if (Map[i][j] == 'a') ap.pb(mp(i, j));
			if (Map[i][j] == 's') s = mp(i, j);
			if (Map[i][j] == 'e') g = mp(i, j);
		}
	}

	int size = ap.size();

	rep(i, size) {
		rep(i, H) rep(j, W) dfs[i][j] = INF;

		dfs[ap[i].fs][ap[i].sn] = 0;

		queue<pi> q;
		q.push(ap[i]);

		while (q.size()) {
			auto pos = q.front();
			q.pop();

			int x = pos.fs, y = pos.sn;

			rep(t, 4) {
				int nx = x + dx[t], ny = y + dy[t];
				if (check(nx, ny) && dfs[nx][ny] == INF) {
					dfs[nx][ny] = dfs[x][y] + 1;
					q.emplace(nx, ny);
				}
			}
		}
		dS[i] = dfs[s.fs][s.sn];
		dG[i] = dfs[g.fs][g.sn];
		rep(j, size) dist[i][j] = dfs[ap[j].fs][ap[j].sn];
	}

	int M = 1 << size;
	rep(i, M) rep(j, size) dp[i][j] = INF;
	rep(i, size) dp[1 << i][i] = dS[i];
	rep(i, M) {
		rep(j, size) {
			rep(k, size) {
				if (!(i & 1 << k)) {
					dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist[j][k]);				
				}
			}
		}
	}

	int ans = INF;
	rep(i, M) {
		if (bit_count(i) >= K) {
			rep(j, size) {
				ans = min(ans, dp[i][j] + dG[j]);
			}
		}
	}
	if (ans >= INF) ans = -1;

	cout << ans << endl;

	return 0;
}