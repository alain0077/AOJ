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
	string s;

	for (int i = 0; i < 1000; i++)
	{
		cin >> s;
		bool flag = true;
		for (int j = 1; j < s.size(); j++) {
			switch (s[j - 1])
			{
			case 'A':
				if (s[j] != 'B' && s[j] != 'D') flag = false;
				break;
			case 'B':
				if (s[j] != 'A' && s[j] != 'E' && s[j] != 'C') flag = false;
				break;
			case 'C':
				if (s[j] != 'B' && s[j] != 'F') flag = false;
				break;
			case 'D':
				if (s[j] != 'A' && s[j] != 'E' && s[j] != 'G') flag = false;
				break;
			case 'E':
				if (s[j] != 'B' && s[j] != 'D' && s[j] != 'F' && s[j] != 'H') flag = false;
				break;
			case 'F':
				if (s[j] != 'C' && s[j] != 'E' && s[j] != 'I') flag = false;
				break;
			case 'G':
				if (s[j] != 'D' && s[j] != 'H') flag = false;
				break;
			case 'H':
				if (s[j] != 'G' && s[j] != 'E' && s[j] != 'I') flag = false;
				break;
			case 'I':
				if (s[j] != 'H' && s[j] != 'F') flag = false;
				break;
			}
		}
		if (flag) cout << s << endl;
	}
}