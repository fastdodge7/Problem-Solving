#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, K;
int arr[100000];

bool check(long long timeLimit)
{
	long long capa = 0;
	for(int i = 0; i < N; i++)
	{
		capa += (timeLimit / arr[i]);
		if(capa >= K)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	long long left = 0, right = 1e18 + 1;
	while(left + 1 < right)
	{
		long long mid = (left + right) / 2;
		if(check(mid))
			right = mid;
		else
			left = mid;
	}

	cout << right << '\n';
	return 0;
}