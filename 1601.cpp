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
		string w;
		vi s(n);
	
		rep(i, n) {
			cin >> w;
			s[i] = w.size();
		}


		rep(i, n) {
			int size = 0, now = i;
			while (size < 5) size += s[now++];
			if (size != 5) continue;

			size = 0;
			while (size < 7) size += s[now++];
			if (size != 7) continue;

			size = 0;
			while (size < 5) size += s[now++];
			if (size != 5) continue;

			size = 0;
			while (size < 7) size += s[now++];
			if (size != 7) continue;

			size = 0;
			while (size < 7) size += s[now++];
			if (size != 7) continue;

			cout << i + 1 << endl;

			break;
		}
	}
}