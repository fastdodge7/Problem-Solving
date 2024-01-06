#include <iostream>
using namespace std;

bool isNotPrime[1000001];

void checkPrime()
{
	for(int i = 2; i <= 1000000; i++)
	{
		if(isNotPrime[i]) continue;
		int mult = 2;
		while(i * mult <= 1000000)
			isNotPrime[i * mult++] = true;
	}
}

int main() {
	// your code goes here
	int N; cin >> N;
	if(N < 8)
	{
		cout << -1;
		return 0;
	}
	checkPrime();
	cout << 2 << ' ' << (2 + N % 2);
	for(int i = 2; i <= 1000000; i++)
	{
		if(!isNotPrime[i] && !isNotPrime[N - 4 - (N % 2) - i])
		{
			cout << ' ' << i << ' ' << N - 4 - (N % 2) - i;
			return 0;
		}
	}
	return 0;
}