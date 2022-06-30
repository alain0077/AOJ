#include <iostream>

using namespace std;

int main()
{
	long long int n, a, b;

	cin >> n >> a >> b;

	switch (n%12)
	{
	case 0:
		cout << a << " " << b << endl;
		break;
	case 1:
		cout << a - b << " " << b << endl;
		break;
	case 2:
		cout << a - b << " " << a << endl;
		break;
	case 3:
		cout << - b << " " << a << endl;
		break;
	case 4:
		cout << - b << " " << a - b << endl;
		break;
	case 5:
		cout << -a << " " << a - b<< endl;
		break;
	case 6:
		cout << -a << " " << -b << endl;
		break;
	case 7:
		cout << -a + b << " " << -b << endl;
		break;
	case 8:
		cout << -a + b << " " <<-a << endl;
		break;
	case 9:
		cout << b << " " << -a << endl;
		break;
	case 10:
		cout << b << " " << -a + b << endl;
		break;
	case 11:
		cout << a << " " << -a + b << endl;
		break;
	}
}