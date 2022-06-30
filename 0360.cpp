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
    int a, b, n;
    bool f = false;
    vector<bool> rsv(1001, false);

    cin >> a >> b >> n;

    for (int i = 0; i < n; i++) {
        int s, f;
        cin >> s >> f;
        for (int j = s; j < f; j++) rsv[j] = true;
    }

    for (int i = a; i < b; i++) {
        if (rsv[i]) {
            f = true;
            break;
        }
    }

    cout << f << endl;
}