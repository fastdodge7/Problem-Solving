#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int x;
int n;
int arr[1000000];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while(cin >> x)
	{
		x *= 1e7;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);

		bool flag = false;
		for(int i = 0; i < n - 1; i++)
		{
			int second = *lower_bound(arr + i + 1, arr + n, x - arr[i]);
			if(arr[i] + second == x)
			{
				cout << "yes " << arr[i] << ' ' << second << '\n';
				flag = true;
				break;
			}
		}

		if(!flag)
			cout << "danger\n";
	}


	return 0;
}
