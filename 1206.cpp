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

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int INF = 100100100;
const double ESP = 1e-9;

const int NODE = 81;


struct Node {
	char label;
	int dist, ary;
	Node *l, *r;

	Node(char label) : label(label), l(NULL), r(NULL), dist(0), ary(0) {}
};


int cnt, max_x;
string s;
vector<string> buff(NODE * 2);

int dist(vector<pi> lv, vector<pi> rv)
{
	int r = 0;
	int n = min(lv.size(), rv.size());

	rep(i, n) {
		chmax(r, lv[i].se + rv[i].fi + 2);
		if (i < n-1) {
			chmax(r, lv[i + 1].se + rv[i].fi + 1);
			chmax(r, lv[i].se + rv[i + 1].fi + 1);
		}
	}

	if (lv.size() > rv.size()) chmax(r, lv[rv.size()].se + rv[rv.size() - 1].fi + 1);
	if (lv.size() < rv.size()) chmax(r, lv[lv.size() - 1].se + rv[lv.size()].fi + 1);

	return r;
}

vector<pi> setPos(Node* node)
{
	vector<pi> re, left, right;
	re.push_back({ 0, 0 });

	switch (node->ary)
	{
	case 0:
		return re;
	case 1:
		left = setPos(node->l);
		re.insert(re.end(), left.begin(), left.end());
		return re;
	case 2: 
		left = setPos(node->l);
		right = setPos(node->r);

		int d = dist(left, right);

		node->dist = d;

		rep(i, max(left.size(), right.size())) {
			if (i < min(left.size(), right.size())) {
				re.push_back(make_pair(left[i].fi + d / 2, right[i].se + (d + 1) / 2));
			}
			else if (left.size() > right.size()) {
				re.push_back(make_pair(left[i].fi + d / 2, left[i].se - d / 2));
			}
			else if (left.size() < right.size()) {
				re.push_back(make_pair(right[i].fi - (d + 1) / 2, right[i].se + (d + 1) / 2));
			}
		}
		break;
	}
	return re;
}

void dfs(Node *node, int y)
{
	int t = buff[cnt].size();
	rep(i, y - t) buff[cnt] += " ";
	buff[cnt] += node->label;

	switch (node->ary)
	{
	case 0:
		break;
	case 1:
		cnt++;
		t = buff[cnt].size();
		rep(i, y - t) buff[cnt] += " ";
		buff[cnt] += '-';
		cnt++;
		dfs(node->l, y);
		cnt -= 2;
		break;
	case 2:
		cnt++;
		int d = node->dist, 
			l = d / 2, 
			r = (d + 1) / 2;
		t = buff[cnt].size();
		rep(i, y - l - t) buff[cnt] += " ";
		rep(i, d + 1) buff[cnt] += '-';
		
		cnt++;
		dfs(node->l, y - l);
		dfs(node->r, y + r);

		cnt -= 2;
		break;
	}
}

Node *parse() 
{
	Node* diag = new Node(s[cnt++]);

	if (s[cnt] != '(') return diag;
	cnt++;
	diag->l = parse();
	diag->ary = 1;

	if (s[cnt] != ',') {
		cnt++;
		return diag;
	}
	else {
		cnt++;
		diag->r = parse();
		diag->ary = 2;
		cnt++;
	}

	return diag;
};

int main()
{
	char c;
	int t = 1;

	do {
		s = "";

		while (cin >> c, c != ';' && c != '.') {
			s += string(1, c);
		}

		cout << t++ << ":" << endl;

		cnt = 0;
		max_x = 0;

		rep(i, NODE * 2) buff[i] = "";

		Node *root = parse();
		vector<pi> v = setPos(root);

		for (auto n : v) {
			chmax(max_x, n.fi);
		}

		//dbg(max_x);
		//dbg(v.size());
		
		cnt = 0;

		dfs(root, max_x);

		for (int i = (v.size() - 1) * 2; i >= 0; i--) {
			for (auto c : buff[i]) {
				cout << c;
			}
			cout << endl;
		}

	} while (c != '.');

	return 0;
}