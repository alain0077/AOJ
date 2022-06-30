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
	int n, m;
	vi a;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (!i || a.back() > t) a.push_back(t);
	}

	reverse(a.begin(), a.end());

	for (int i = 0; i < m; i++) {
		if (i) cout << " ";

		int key;
		cin >> key;

		while (1)
		{
			auto it = upper_bound(a.begin(), a.end(), key);
			if (it == a.begin()) break;
			it--;
			key %= *it;
		}

		cout << key;
	}
	cout << endl;
}