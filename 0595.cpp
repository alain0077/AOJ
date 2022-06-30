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
const int MOD = 10007;


int main()
{
	int N;
	string s;

	cin >> N >> s;

	int sv;
	vii dp(N+1, vi(8, 0));

	dp[0][1] = 1;

	rep(i, N) {
		if (s[i] == 'J') sv = 0;
		elif(s[i] == 'O') sv = 1;
		else sv = 2;

		rep(bit, (1 << 3)) {
			rep(bit2, (1 << 3)) {
				if (!(bit2 & (1 << sv))) continue;
				if (!(bit & bit2))continue;
				dp[i + 1][bit2] += dp[i][bit];
				dp[i + 1][bit2] %= MOD;
			}
		}
	}

	int ans = 0;
	
	rep(bit, (1 << 3)) ans += dp[N][bit];

	cout << ans % MOD << endl;
}