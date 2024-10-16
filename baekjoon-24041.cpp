#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, G, K;
int sarr[200000];
int limitDate[200000];
bool canRemove[200000];

bool check(int curDay)
{
	long long bacteria = 0;
	vector<long long> removeArr = {};

	for(int i = 0; i < N; i++)
	{
		long long component = (long long)sarr[i] * max(1, curDay - limitDate[i]);
		bacteria += component;
		if(canRemove[i])
			removeArr.push_back(component);
	}
	sort(removeArr.begin(), removeArr.end(),greater<long long>());
	for(int i = 0; i < K; i++)
		bacteria -= removeArr[i];
	
	return bacteria <= G;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> G >> K;
	for(int i = 0; i < N; i++)
	{
		cin >> sarr[i] >> limitDate[i] >> canRemove[i];
	}

	long long left = 0, right = (int)2e9 + 1;
	while(left + 1 < right)
	{
		long long mid = (left + right) / 2;
		if(check(mid))
			left = mid;
		else
			right = mid;
	}
	cout << left << '\n';
	return 0;
}