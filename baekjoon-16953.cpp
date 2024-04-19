#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long from, to; cin >> from >> to;

	int ans = 0;
	while(from <= to)
	{
		ans++;
		if(from == to)
		{
			cout << ans << '\n';
			return 0;
		}

		if(to % 10 == 1)
			to /= 10;
		else if(to % 2 == 1)
			break;
		else
			to /= 2;
	}

	cout << -1;
	return 0;
}