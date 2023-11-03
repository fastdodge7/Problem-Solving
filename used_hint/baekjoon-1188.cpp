#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {
	int x, y;
	cin >> x >> y;

	cout << y - gcd(x, y);

	return 0;
}