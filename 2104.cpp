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

int main()
{
	int t;
	cin >> t;

	rep(i, t) {
		int n, k, x;
		cin >> n >> k >> x;

		vi d(n - 1);
		rep(j, n - 1) {
			int tmp;
			cin >> tmp;
			d[j] = tmp - x;
			x = tmp;
		}

		sort(d.rbegin(), d.rend());

		int ans = 0;
		for (int j = k - 1; j < n - 1; j++) ans += d[j];
		cout << ans << endl;
	}
}