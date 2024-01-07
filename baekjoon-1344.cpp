#include <iostream>
#include <cmath>
using namespace std;

double A, B;

long long comb(int n, int c)
{
	if(c > 9)
		return comb(n, n - c);
	long long res = 1;
	for(int i = 0; i < c; i++)
	{
		res *= n;
		n--;
		//cout << res << '\n';
	}
	for(int i = c; i >= 1; i--)
		res /= i;
	return res;
}

double calc(double prob)
{
	double res = 0;
	int cnt[] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18 };
	for(int i = 0; i < 12; i++)
	{
		res += (pow(prob, cnt[i]) * pow(1 - prob, 18 - cnt[i]) * comb(18, cnt[i]));
	}
	return res;
}

int main() {
	// your code goes here
	
	cin >> A >> B;
	A /= 100;
	B /= 100;
	
	cout<<fixed;
    cout.precision(15);
	cout << (1 - calc(A) * calc(B));
	return 0;
}