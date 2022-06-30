#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	string s;

	while (getline(cin, s)) {

		if (s == ".") break;

		stack<char> j;
		bool f = true;

		for (auto c : s) {
			if (c == '(') { f = false; j.push('('); }
			if (c == '[') { f = false; j.push('['); }

			if (c == ')' && j.size() == 0) {
				f = false;
				break;
			}
			else if (c == ')' && j.top() != '(') {
				f = false;
				break;
			}
			else if (c == ')') { f = true; j.pop(); }

			if (c == ']' && j.size() == 0) {
				f = false;
				break;
			}
			else if (c == ']' && j.top() != '[') {
				f = false;
				break;
			}
			else if (c == ']') { f = true; j.pop(); }
		}

		if (f&&!j.size()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}