#include <iostream>

using namespace std;

template <typename T> 
T extgcd(T a, T b, T& x, T& y)
{
	T d = a;

	if (b == 0) {
		x = 1;
		y = 0;
	}
	else {
		d = extgcd(b, a % b, y, x);
		y -= a / b * x;
	}

	return d;
}


int main()
{
	int a, b, x, y;

	cin >> a >> b;

	extgcd(a, b, x, y);

	cout << x << " " << y << endl;
}