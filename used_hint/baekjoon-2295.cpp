#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N;
long long arlist[1000];
vector<long long> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arlist[i];
	}

	sort(arlist, arlist + N);

	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		arr.push_back(arlist[i] + arlist[j]);

	sort(arr.begin(), arr.end());

	for(int target = N - 1; target >= 0; target--)
	{
		for(int last = 0; last < N; last++)
		{
			int left = -1, right = arr.size();
			while(left + 1 < right)
			{
				int mid = (left + right) / 2;
				if(arlist[target] == arr[mid] + arlist[last])
				{
					cout << arlist[target] << '\n';
					return 0;
				}
				else if(arlist[target] < arr[mid] + arlist[last])
					right = mid;
				
				else
					left = mid;
			}
		}
	}

	return 0;
}