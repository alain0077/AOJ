#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>

#define dbg(x) cout << #x << " = " << x << endl
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define fs first
#define sn second
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;

const int INF = 100100100;
const double ESP = 1e-9;

int main()
{
	int n, a=0, un=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "A") a++;
		if (s == "Un") {
			un++;
			if (a < un) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	if (a == un) cout << "YES" << endl;
	else cout << "NO" << endl;
}