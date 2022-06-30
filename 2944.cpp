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

int main()
{
	int N, M, A;
	
	while (cin >> N >> M && N) {
		int ans = M, avg = M / N;

		rep(i, N) {
			cin >> A;
			if (A < avg) ans += A - avg;
		}

		cout << ans << endl;
	}
}