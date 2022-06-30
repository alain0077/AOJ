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
		int ans = 0;
		vi d(n);

		rep(i, n) cin >> d[i];

		rep(i, n - 3) if (d[i] == 2) if (d[i + 1] == 0) if (d[i + 2] == 2) if (d[i + 3] == 0) ans++;

		cout << ans << endl;
	}
}