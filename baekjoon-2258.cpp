#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;

pair<int, int> arr[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].second >> arr[i].first;
		arr[i].second = -arr[i].second;
	}

	sort(arr, arr + N);

	int price = 0;
	int priceSum = 0;

	int weight = 0;
	for (int i = 0; i < N; i++)
	{
		weight -= arr[i].second;
		priceSum += arr[i].first;
		if (arr[i].first > price)
		{
			price = arr[i].first;
			priceSum = price;
		}

		if (weight >= M)
		{
			int nextPrice = 0x7fffffff;
			for (int j = i + 1; j < N; j++)
			{
				if (arr[i].first < arr[j].first)
				{
					nextPrice = arr[j].first;
					break;
				}
			}
			cout << min(priceSum, nextPrice);
			return 0;
		}
	}
    cout << -1;
	return 0;
}