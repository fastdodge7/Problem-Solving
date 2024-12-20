#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
long long cnt[11];
long long tens[11] = {0, 1, 10, 100, 1000, 10000, 100000,1000000, 10000000, 100000000, 1000000000};

long long N, K;

void init()
{
	cnt[1] = 9;

	long long f = 100;
	long long r = 10;
	for(int i = 2; i <= 9; i++)
	{
		cnt[i] = cnt[i - 1] + i * (f - r);
		f *= 10;
		r *= 10;
	}
	cnt[10] = cnt[9] + 10;
}

long long getOrder(long long num)
{
	long long ret = 0;

	while(num > 0)
	{
		ret++;
		num /= 10;
	}

	return ret;
}

long long getNumCnt(long long num)
{
	long long order = getOrder(num);
	
	return (num - tens[order] +1) * order + cnt[order - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	
	cin >> N >> K;
	long long left = 0, right = N + 1;

	while(left + 1 < right)
	{
		long long mid = (left + right) / 2;

		//cout << mid << "\n";

		long long base = getNumCnt(mid);

		if(base - getOrder(mid) < K && K <= base)
		{
			string str = to_string(mid);
			long long counter = K - base + getOrder(mid);
			cout << str[counter - 1];
			return 0;
		}
		else if(base - getOrder(mid) >= K)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	cout << -1;
	return 0;
}