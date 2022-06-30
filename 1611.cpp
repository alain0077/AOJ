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

const int N = 300;

int n;
vector<int> w;
vector<vector<int>> dp;

int rec(int l, int r)
{
	int re = 0;

	if (l >= r) return 0;
	if (l - r == 1) {
		if (abs(w[l] - w[r]) <= 1) return 2;
		else return 0;
	}
	if (dp[l][r] != -1) return dp[l][r];

	if (abs(w[l] - w[r]) <= 1 && rec(l + 1, r - 1) == r - l - 1)  re = r - l + 1;

	for (int i = l; i < r; i++) chmax(re, rec(l, i) + rec(i + 1, r));

	return dp[l][r] = re;
}


int main()
{
	int n;

	while (cin >> n && n)
	{
		w.clear();

		rep(i, n) {
			int x;
			cin >> x;
			w.pb(x);
		}

		dp.assign(N, vector<int>(N, -1));

		cout << rec(0,n-1) << endl;
	}

	return 0;
}