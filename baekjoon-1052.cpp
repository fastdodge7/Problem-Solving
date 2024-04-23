#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, K;

int solve(int target)
{
	int cnt = 0;
	for(int i = target; i > 0; i >>= 1)
	{
		if(i & 1)
			cnt++;
	}
    if(cnt <= K) return target;

	int shift = 0;
	while(cnt >= K  || (target & 1 == 0))
	{
		if(target & 1 == 1)
			cnt--;
		shift++;
		target >>= 1;
	}
	target++;
	target <<= shift;
	return target;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	
	if(N <= K)
	{
		cout << 0 << '\n';
		return 0;
	}

	if((N / 2) + (N % 2) <= K)
	{
		cout << 0 << '\n';
		return 0;
	}
	
	cout << solve(N) - N << '\n';
	return 0;
}