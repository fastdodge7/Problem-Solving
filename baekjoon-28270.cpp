#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[1000001];
int ans[1000001];
vector<pair<int, int>> stck;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];
	
	int depth = 0;
	stck.push_back({0, 1});
	for(int i = 1; i <= N; i++)
	{
		if(arr[i] == stck.back().first + 1)
		{
			ans[i] = stck.back().second++;
			stck.push_back({arr[i], 1});
		}
		else if(arr[i] <= stck.back().first)
		{
			while(arr[i] <= stck.back().first)
				stck.pop_back();
			i--;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	for(int i = 1; i <= N; i++)
		cout << ans[i] << ' ';
	return 0;
}

