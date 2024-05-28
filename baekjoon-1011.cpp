#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int T;
long long diff = 0;

bool check(long long n)
{
	long long rest = diff - n * n;
	return rest >= 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		long long x, y; cin >>x >> y;
		diff = y - x;

		long long left = 0, right = 2147483648;
		while(left + 1 < right)
		{
			int mid = (left + right) / 2;
			if(check(mid))
				left = mid;
			else
				right = mid;
		}

		long long ans = left * 2 - 1;
		long long rest = diff - left * left;
		if(rest > left)
		{
			ans += rest / left;
			rest = rest % left;
		}
			
		if(rest > 0)
			ans++;

		cout << ans << '\n';
	}

	return 0;
}