#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Block {
	int x,
		s,
		left,
		right;
	double level;
};

enum eDir {
	Left,
	Right,
};

int main()
{
	int d, n, m, l;

	cin >> d;

	while (d--) {
		cin >> n;
		vector<int> b(n), h(n);
		for (int i = 0; i < n; i++) cin >> b.at(i) >> h.at(i);

		cin >> m;
		vector<int> f(m), a(m);
		for (int i = 0; i < m; i++) cin >> f.at(i) >> a.at(i);

		cin >> l;
		vector<int> p(l), t(l);
		for (int i = 0; i < l; i++)	cin >> p.at(i) >> t.at(i);

		vector<Block> blocks;

		for (int i = 0; i < n + 1; i++) {
			if (i == 0) blocks.push_back({ b.at(i), b.at(i) * 30, 50, h.at(i), 0.0 });
			else if (i == n) blocks.push_back({ 100, (100 - b.at(i - 1)) * 30, h.at(i - 1), 50, 0.0 });
			else blocks.push_back({ b.at(i), (b.at(i) - b.at(i - 1)) * 30, h.at(i - 1), h.at(i), 0.0 });
		}


		for (int i = 0; i < l; i++) {
			int _time = t.at(i);
			int pos = 0;
			for (pos = 0; pos < n + 1; pos++) {
				if (blocks.at(pos).x > p.at(i))
					break;
			}

			for (int j = 0; j < n + 1; j++) {
				blocks.at(j).level = 0.0;
			}

			double _max = 0.0;
			double ans = 0.0;
			for (int j = 0; j < m; j++) {
				double w = double(a.at(j)) * _time;
				_max += w;

				if (_max >= 50.0 * 100 * 30) {
					ans = 50.0;
					break;
				}

				int k;
				for (k = 0; k < n + 1; k++) {
					if (blocks.at(k).x > f.at(j))
						break;
				}


				int _left = 0;
				int _right = 0;
				double _sum = double(blocks.at(k).s);
				int _dir = 0;
				int flag = 0;
				
				while (1) {
					double high;
					double _min;

					if (blocks.at(k + _left).left > blocks.at(k + _right).right) {
						high = double(blocks.at(k + _right).right - blocks.at(k +_right).level);
						_min = double(blocks.at(k + _right).right);
						_dir = Right;
					}
					else {
						high = double(blocks.at(k + _left).left - blocks.at(k + _left).level);
						_min = double(blocks.at(k + _left).left);
						_dir = Left;
					}

					double _level = w / _sum;
					/*
					cout << k << endl;
					cout << _left << ":" << _right << endl;
					cout << w << ":" << _sum << endl;
					cout << _level << ":" << high << endl;
					*/
					if (high < _level) {
						if (high > 0) {
							w -= high * _sum;

							//cout << w << endl;

							int _l = _left, _r = _right;
							while (_l || _r)
							{
								if (_l != 0) blocks.at(k + _l++).level = _min;

								if (_r != 0) blocks.at(k + _r--).level = _min;
							}
							blocks.at(k).level = _min;
						}

						if (_dir) {
							if (blocks.at(k + _right + 1).left < blocks.at(k + _right + 1).right) {
								_right++;
								_level = w / blocks.at(k + _right).s;

								//cout << _level << ":" << blocks.at(k + _right).left - blocks.at(k + _right).level << endl;
								
								if (_level < blocks.at(k + _right).left - blocks.at(k + _right).level) {
									blocks.at(k + _right).level += _level;
									break;
								}
								else {
									if (high >= 0) {
										if (blocks.at(k + _right).left - blocks.at(k + _right).level > 0) {
											w -= (blocks.at(k + _right).left - blocks.at(k + _right).level) * blocks.at(k + _right).s;
											blocks.at(k + _right).level = blocks.at(k + _right).left;
										}
									}
									_sum += double(blocks.at(k + _right).s);
								}
							}
							else if (blocks.at(k + _right + 1).level >= blocks.at(k + _right + 1).left) {
								_right++;
								_sum += double(blocks.at(k + _right).s);
							}
							else {
								k++;
								k += _right;
								_right = 0;
								_left = 0;
								_sum = double(blocks.at(k).s);
							}
						}
						else {
							if (blocks.at(k + _left - 1).right < blocks.at(k + _left - 1).left) {
								_left--;
								_level = w / blocks.at(k + _left).s;
								
								//cout << _level << ":" << blocks.at(k + _left).left - blocks.at(k + _left).level << endl;
								
								if (_level < blocks.at(k + _left).right - blocks.at(k + _left).level) {
									blocks.at(k + _left).level += _level;
									break;
								}
								else {
									if (high >= 0) {
										if (blocks.at(k + _left).right - blocks.at(k + _left).level > 0) {
											w -= (blocks.at(k + _left).right - blocks.at(k + _left).level) * blocks.at(k + _left).s;
											blocks.at(k + _left).level = blocks.at(k + _left).right;
										}
									}
									_sum += double(blocks.at(k + _left).s);
								}
							}
							else if (blocks.at(k + _left - 1).level >= blocks.at(k + _left - 1).right) {
								_left--;
								_sum += double(blocks.at(k + _left).s);
							}
							else {
								k--;
								k += _left;
								_right = 0;
								_left = 0;
								_sum = double(blocks.at(k).s);
							}
						}
					}
					else {
						while (_left || _right)
						{
							if (_left != 0) blocks.at(k + _left++).level += _level;

							if (_right != 0) blocks.at(k + _right--).level += _level;
						}
						blocks.at(k).level += _level;

						break;
					}
					/*
					for (int z = 0; z < n + 1; z++) {
						cout << blocks.at(z).level << endl;
					}
					*/
				}
				/*
				for (int z = 0; z < n + 1; z++) {
					cout << blocks.at(z).level << endl;
				}
				*/
				ans = blocks.at(pos).level;
			}
			cout << ans << endl;
		}
	}
}