#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int arr[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int num; cin >> num;
		int idx = -1;
		int diff = 999999;
		for(int j = 0; j < 4; j++)
		{
			if(num > arr[j] && arr[j] - num < diff)
				idx = j;
		}
		if(idx == -1)
		{
			cout << "NO\n";
			return 0;
		}
		arr[idx] = num;
	}
	cout << "YES\n";
	return 0;
}