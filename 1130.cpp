#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tile {
	int row,
		col;
};

int main()
{
	int x, y, row, col, c;
	vector<string> v(20);
	queue<Tile> t;

	while (cin >> x >> y, x != 0 && y != 0) {
		c = 1;

		for (int i = 0; i < y; i++) {
			cin >> v.at(i);
			for (int j = 0; j < x; j++) {
				if (v.at(i).at(j) == '@') {
					t.push({ i,j });
					v.at(i).at(j) = '#';
					break;
				}
			}
		}

		while (!t.empty()) {
			row = t.front().row;
			col = t.front().col;
			t.pop();

			if (row - 1 >= 0 && v.at(row-1).at(col) == '.') {
				v.at(row-1).at(col) = '#';
				t.push({row-1,col});
				c++;
			}

			if (row + 1 < y && v.at(row+1).at(col) == '.') {
				v.at(row+1).at(col) = '#';
				t.push({ row+1,col });
				c++;
			}

			if (col - 1 >= 0 && v.at(row).at(col-1) == '.') {
				v.at(row).at(col-1) = '#';
				t.push({ row,col-1 });
				c++;
			}

			if (col + 1 < x && v.at(row).at(col+1) == '.') {
				v.at(row).at(col+1) = '#';
				t.push({ row,col+1 });
				c++;
			}
		}

		cout << c << endl;
	}
}