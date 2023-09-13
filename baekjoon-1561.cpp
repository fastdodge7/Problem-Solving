#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int N, M;
int attraction[10001];

ll check(ll limitTime)
{
	ll cnt = M;
	for (int i = 0; i < M; i++)
		cnt += (limitTime / attraction[i]);

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> attraction[i];

	if (N <= M)
	{
		cout << N << '\n';
		return 0;
	}

	ll left = 0; ll right = 60000000000;
	ll mid = (left + right) / 2;
	ll time = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid) >= N)
		{
			time = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	ll cnt = check(time - 1);
	for (int i = 0; i < M; i++) {
		if (time % attraction[i] == 0)
		{
			cnt++;
		}
		if (cnt == N)
		{
			cout << i + 1 << '\n';
			return 0;
		}
	}
	return 0;
}