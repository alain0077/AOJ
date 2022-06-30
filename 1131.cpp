#include <iostream>

using namespace std;

int p, q, a, n, ans;

void func(int numer, int demon, int pre, int mlt, int count)
{
	if (p * demon == q * numer) {
		ans++;
		return;
	}

	if (n == count) return;
	if (q * numer > p * demon) return;

	for (int i = pre; mlt * i < a + 1; i++) func(numer * i + demon, demon * i, i, mlt * i, count + 1);
}

int main()
{
	while (cin >> p >> q >> a >> n) {
		if (!p && !q && !a && !n) break;
		ans = 0;
		func(0, 1, 1, 1, 0);
		cout << ans << endl;
	}
}