#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Block{
	int num;
	int base;
	int height;
	int weight;

	bool operator>(const Block other) const {
		if(base == other.base)
			return weight > other.weight;
		return base > other.base;
	}
}Block;

int N;
Block arr[101];
int dp[101];
int beforeBlock[101];

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	arr[0] = {0, (int)1e9, 0, (int)1e9};
	for(int i = 1; i <= N; i++)
	{
		int a, h, w; cin >> a >> h >> w;
		arr[i] = {i, a, h, w};
	}

	sort(arr, arr + N + 1, greater<Block>());

	for(int i = 1; i <= N; i++)
	{
		for(int bef = 0; bef < i; bef++)
		{
			if(arr[bef].weight < arr[i].weight) continue;
			if(dp[bef] + arr[i].height > dp[i])
			{
				dp[i] = dp[bef] + arr[i].height;
				beforeBlock[i] = bef;
			}
		}
	}
	int topBlock = 0;
	for(int i = 0; i <= N; i++)
	{
		if(dp[i] > dp[topBlock])
			topBlock = i;
	}
	vector<int> ans = {};
	while(topBlock != 0)
	{
		ans.push_back(topBlock);
		topBlock = beforeBlock[topBlock];
	}

	cout << (int)ans.size() << '\n';
	for(int i : ans)
	{
		cout << arr[i].num << '\n';
	}
	
	return 0;
}