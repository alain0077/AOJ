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
	int a, b, c;
	int t = 0;
	cin >> a >> b >> c;

	while (1)
	{
		if (t % 60 <= c && t % 60 + a >= c) {
			cout << t / 60 * 60 + c << endl;
			break;
		}
		else
			t += a + b;

		if (t % 60 == 0) {
			cout << -1 << endl;
			break;
		}
	}

	return 0;
}