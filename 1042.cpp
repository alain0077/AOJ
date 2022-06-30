#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string s;

	while (getline(cin,s)) {

		if (s == "END OF INPUT") break;

		int cnt = 0;

		for (auto c : s) {
			if (c != ' ') cnt++;
			else {
				cout << cnt;
				cnt = 0;
			}
		}

		cout << cnt << endl;
	}
}