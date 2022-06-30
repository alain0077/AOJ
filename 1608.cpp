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


int main()
{
	int n;

	while (cin >>n && n)
	{
		int ans = INT_MAX;
		vector<int> a(n);

		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(), a.end());

		for (int i = 1; i < n; i++) chmin(ans, a[i] - a[i - 1]);

		cout << ans << endl;
	}
}