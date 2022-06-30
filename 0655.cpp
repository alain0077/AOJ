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
	int N, _max = 0, ans = 1, cnt = 1;
	vector<bool> flag;
	vector<pi> A;

	cin >> N;

	rep(i, N) {
		int x;
		cin >> x;
		chmax(_max, x);
		A.pb({x, i});
		flag.pb(false);
	}

	if (!_max) {
		cout << 0 << endl;
		return 0;
	}

	sort(A.begin(), A.end());

	rep(i, N) {
		flag[A[i].se] = true;
		cnt++;
		if (!A[i].se || flag[A[i].se - 1]) cnt--;
		if (A[i].se == N - 1 || flag[A[i].se + 1]) cnt--;
		if (i < N - 1 && A[i].fi == A[i + 1].fi) continue;
		chmax(ans, cnt);
	}
	cout << ans << endl;

	return 0;
}