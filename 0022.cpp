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
const double MOD = 1e9 + 7;

int main()
{
	int n;

	while (cin >> n && n)
	{
		int max = -100001, sum = 0;

		vi a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			sum = 0;

			for (int k = i; k < n; k++) {
				sum += a[k];
				chmax(max, sum);
			}
		}

		cout << max << endl;
	}
}