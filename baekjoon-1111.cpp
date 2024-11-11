#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N;
int arr[50];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >>arr[i];
	
	if(N <= 2)
	{
		if(N == 2 && arr[0] == arr[1])
		{
			cout << arr[0] << '\n';
			return 0;
		}
		cout << "A\n";
		return 0;
	}

	int a = arr[1] == arr[0] ? 0 : (arr[2] - arr[1]) / (arr[1] - arr[0]);
	int b = arr[1] - a * arr[0];

	for(int i = 0; i < N - 1; i++)
	{
		if(a * arr[i] + b != arr[i + 1])
		{
			cout << "B\n";
			return 0;
		}
	}

	cout << arr[N - 1] * a + b << '\n';
	return 0;
}