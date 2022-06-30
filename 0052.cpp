#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <stack>
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

const int INF = 100100100;
const double ESP = 1e-9;

int main()
{
	int x;

	while (cin >> x && x)
	{
		int ans = 0, n = x+1;
		for (int i = 5; i < n; i++) {
			x = i;
			while (x % 5 == 0)
			{
				x = x / 5;
				ans++;
			}
		}

		cout << ans << endl;
	}
}