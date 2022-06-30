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
const int MAX = 7368792;

int main()
{
	int m, n;
	
	while (cin >> m >> n && m) 
	{
		int num = m;
		vector<bool> f(MAX,false);

		for (int i = 0; i <= n; i++) {

			while (f[num]) num++;

			for (int j = num; j <= MAX; j += num) {
				f[j] = true;
			}
		}

		cout << num << endl;
	}
}