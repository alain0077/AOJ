#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int to_int(string s)
{
	int n = 0, col = 1;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'm') n += 1000 * col;
		else if (s[i] == 'c') n += 100 * col;
		else if (s[i] == 'x') n += 10 * col;
		else if (s[i] == 'i') n += col;
		
		if ('2' <= s[i] && s[i] <= '9') col = s[i] - '0';
		else col = 1;
	}

	return n;
}

int main()
{
	int n;

	cin >> n;

	while (n--) {
		int a = 0, b = 0;
		string s1, s2;

		cin >> s1 >> s2;

		a = to_int(s1);
		b = to_int(s2);

		a += b;

		b = a / 1000;
		if (b) {
			if (b > 1) cout << b;
			cout << 'm';
		}

		b = a % 1000;
		b = b / 100;
		if (b) {
			if (b > 1) cout << b;
			cout << 'c';
		}

		b = a % 1000;
		b = b % 100;
		b = b / 10;
		if (b) {
			if (b > 1) cout << b;
			cout << 'x';
		}

		b = a % 1000;
		b = b % 100;
		b = b % 10;
		if (b) {
			if (b > 1) cout << b;
			cout << 'i';
		}

		cout << endl;
	}
}