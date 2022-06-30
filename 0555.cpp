#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n, ans = 0;
	string s, r;

	getline(cin, s);

	cin >> n;

	for (int i = 0; i < n+1; i++) {
		getline(cin, r);

		for (int j = 0; j < r.size(); j++) {
			
			if (r[j] == s[0]) {
				bool f = true;
				for (int k = 1; k < s.size(); k++) {
					if (r[(j + k) % r.size()] != s[k]) {
						f = false;
						break;
					}
				}
				if (f) {
					ans++;
					break;
				}
			}
		}

	}

	cout << ans << endl;
}