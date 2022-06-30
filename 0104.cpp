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
	
	int h, w;

	while (cin >> h >> w && h)
	{
		vector<vector<char>> map(h, vector<char>(w));

		rep(i, h)rep(j, w) cin >> map[i][j];

		int row = 0, col = 0, cnt = 0, l = h * w;
		while (map[row][col] != '.' && cnt <= l)
		{
			switch(map[row][col]) {
			case '>' :
				map[row][col] = '#';
				col++;
				break;
			case '<' :
				map[row][col] = '#';
				col--;
				break;
			case '^':
				map[row][col] = '#';
				row--;
				break;
			case 'v':
				map[row][col] = '#';
				row++;
				break;
			}

			if (map[row][col] == '#') break;
		}
		if (map[row][col] == '.') cout << col << " " << row << endl;
		else cout << "LOOP" << endl;
	}
}