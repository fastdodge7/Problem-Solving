#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int buff[100];

int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);

	while(b > 0)
	{
		int temp = a;
		a = b;
		b = (temp % a);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> buff[i];
	
	for(int i = 0; i < N - 1; i++)
		buff[i] = abs(buff[i + 1] - buff[i]);

	int GCD = N == 2 ? buff[0] : gcd(buff[0], buff[1]);
	for(int i = 2; i < N - 1; i++)
	{
		GCD = gcd(GCD, buff[i]);
	}

	set<int> ans = {GCD};
	for(int i = 2; i <= ceil(sqrt(GCD)); i++)
	{
		if(GCD % i == 0)
		{
			ans.insert(i);
			if(GCD / i > 1)
				ans.insert(GCD / i);
		}
	}
	for(int a : ans)
		cout << a << ' ';
	return 0;
}
