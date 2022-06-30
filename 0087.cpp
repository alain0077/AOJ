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
	string s;

	while (getline(cin,s)) {
		stack<double> st;
		stringstream ss(s);
		while (!ss.eof()) {
			string c;
			ss >> c;

			if (c != "-" && c != "+" && c != "*" && c != "/") {
				st.push(stod(c));
			}
			else {
				double x = st.top();
				st.pop();
				double y = st.top();
				st.pop();
				if (c == "-") {
					st.push(y - x);
				}
				else if (c == "+") {
					st.push(y + x);
				}
				else if (c == "*") {
					st.push(y * x);
				}
				else{
					st.push(y / x);
				}
				
			}
		}

		cout << fixed << setprecision(6) << st.top() << endl;
	}
}