#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


int N;
int cnt[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	vector<int> arr = {};
	for(int i = 0; i < N; i++)
	{
		int a; cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size() - 1; i++)
	{
		if(arr[i + 1] - arr[i] != 1) continue;

		for(int j = i + 1; j < arr.size(); j++)
		{
			if(arr[j] - arr[i] != 1)
			{
				swap(arr[i + 1], arr[j]);
				sort(arr.begin() + i + 1 + 1, arr.end());
				break;
			}
		}

		int cache = arr[i + 1];
		arr.erase(arr.begin() + i + 1);
		for(int j = i + 1; j >= 0; j--)
		{
			if(j == 0)
			{
				arr.insert(arr.begin(), cache);
				break;
			}
			else
			{
				if(cache - arr[j - 1] != 1)
				{
					arr.insert(arr.begin() + j, cache);
					break;
				}
			}
		}
	}
	
	for(int a : arr)
		cout << a << ' ';
	

	return 0;
}