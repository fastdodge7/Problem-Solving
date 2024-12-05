#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 32;

int N;
int arr[MAX_N];
vector<int> stacks;

void findPos(int value)
{
	int right = stacks.size() - 1;
	int left = 0;



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];

	stacks.push_back(arr[0]);


	for(int i = 1; i < N; i++)
	{
		auto iter = upper_bound(stacks.begin(), stacks.end(), arr[i]);
		if(iter == stacks.end())
		{
			if(stacks.back() == arr[i]) continue;
			stacks.push_back(arr[i]);
		}
		else
		{
			*iter = arr[i];
		}
	}

	cout << stacks.size();
	return 0;
}