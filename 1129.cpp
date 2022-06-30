#include <iostream>

using namespace std;

int main()
{
	int n, r, p, c;
	int cards[50], tmp[50];
	
	cin >> n >> r;

	while (n != 0 && r != 0) {
		for (int i = 0; i < n; i++) cards[i] = n - i;
		for (int i = 0; i < r; i++) {
			cin >> p >> c;
			for (int j = 0; j < p - 1; j++) tmp[j] = cards[j];
			for (int j = 0; j < c; j++) cards[j] = cards[p - 1 + j];
			for (int j = 0; j < p - 1; j++) cards[c + j] = tmp[j];
		}

		cout << cards[0] << endl;

		cin >> n >> r;
	}
}