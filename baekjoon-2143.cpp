#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int T, N, M;

bool visited[401];


long long arrA[1001];
long long arrB[1001];

vector<long long> vecA, vecB;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> T;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arrA[i];
		arrA[i] += arrA[i - 1];
	}
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> arrB[i];
		arrB[i] += arrB[i - 1];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
			vecA.push_back(arrA[j] - arrA[i - 1]);
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = i; j <= M; j++)
			vecB.push_back(arrB[j] - arrB[i - 1]);
	}

	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());

	long long ans = 0;
	for (long long a : vecA)
	{
		auto target = lower_bound(vecB.begin(), vecB.end(), T - a);
		if (target == vecB.end())
			continue;
		if (*target == T - a)
		{
			ans += (upper_bound(vecB.begin(), vecB.end(), T - a) - target);
		}
	}

	cout << ans << '\n';

	return 0;
}