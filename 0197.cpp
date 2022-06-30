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
	int x, y, a;

	while(cin >> x >> y && (x != 0 && y != 0)){
		if (x < y) {
			int t = x;
			x = y;
			y = t;
		}

		int c = 1;
		while (1) {
			a = x % y;
			x = y;
			y = a;
			if(y == 0) break;
			c++;
			
		}

		cout << x << " " << c << endl;
	}
}