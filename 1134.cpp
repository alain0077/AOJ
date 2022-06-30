#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;
using ll = long long;
using ps = pair<string, string>;
#define dbg(x) cout << #x << " = " << x << endl
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define fi first
#define se second

const int INF = 100100100;
const double ESP = 1e-9;

ps split(string s) {
	auto pos = s.find("-");

	return { s.substr(0, pos), s.substr(pos + 1) };
}

const int N = 201;

int main()
{
	int n, m;

	while (cin >> n) {
		if (!n) break;

		int cnt = 0;
		int d[N][N], C[N][N];
		bool arr[N][N];
		map<string, int> map;

		rep(i,N)rep(j,N) arr[i][j] = false;
		
		rep(i,N)rep(j,N) d[i][j] = INF;
		rep(i, N) d[i][i] = 0;

		rep(i, N)rep(j, N) C[i][j] = INF;
		rep(i, N) C[i][i] = 0;


		rep(i,n) {
			string s;
			cin >> s;
			ps c = split(s);

			if (!map.count(c.fi)) map[c.fi] = cnt++;
			if (!map.count(c.se)) map[c.se] = cnt++;

			int u = map[c.fi], v = map[c.se];

			C[u][v] = 1;
			d[u][v] = d[v][u] = 1;
			arr[u][v] = true;
		}

		cout << cnt << endl;

		rep(k, cnt)rep(i, cnt)rep(j, cnt) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


		auto same_degree = [&](int a, int b) {
			bool same = false;
			rep(i, cnt) {
				if ((arr[a][i] || arr[i][a]) && (arr[b][i] || arr[i][b])) same = true;
			}
			if (!same) return false;

			rep(i, cnt) {
				if (arr[i][a] && arr[b][i]) return false;
				if (arr[a][i] && arr[i][b]) return false;
			}
			return true;
		};

		rep(i, cnt)rep(j, i) {
			if (same_degree(i, j)) {
				//cout << "DEG :: " << i << " " << j << endl;
				C[i][j] = C[j][i] = 1;
			}
		}


		rep(k, cnt)rep(i, cnt)rep(j, cnt) C[i][j] = min(C[i][j], C[i][k] + C[k][j]);

		cin >> m;
		while (m--) {
			string q;
			cin >> q;

			ps qc = split(q);

			bool ok = false;
			if (map.count(qc.fi) && map.count(qc.se)) {
				int u = map[qc.fi], v = map[qc.se];
				//dbg(C[u][v]);

				if (d[u][v] % 2 == 1 && C[u][v] < INF) ok = true;
			}
			cout << (ok ? "YES" : "NO") << endl;
		}
	}
	return 0;
}