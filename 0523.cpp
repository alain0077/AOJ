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
	int n;

	while (cin >> n && n)
	{
		vi t(n), h;
		rep(i, 2 * n) h.push_back(i+1);
		rep(i, n) {
			int a;
			cin >> a;
			t[i] = a;
			auto p = find(h.begin(), h.end(), a);
			if (p != h.end()) {
				h.erase(p);
			}
		}

		sort(t.begin(), t.end());

		int now = 0;

		while (h.size())
		{
			bool flag = true;
			rep(i, t.size()) {
				if (now < t[i])
				{
					now = t[i];
					flag = false;
					//dbg(t[i]);
					t.erase(t.begin() + i);
					break;
				}
			}
			if (flag) now = 0;

			if (!t.size()) break;

			flag = true;
			rep(i, h.size()) {
				if (now < h[i])
				{
					now = h[i];
					flag = false;
					//dbg(h[i]);
					h.erase(h.begin() + i);
					break;
				}
			}
			if (flag) now = 0;
		}

		cout << h.size() << endl;
		cout << t.size() << endl;
	}
}