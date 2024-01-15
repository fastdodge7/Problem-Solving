#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q; 
unordered_map<long long, long long> dp;

long long solve(long long a)
{
	if(dp.find(a) != dp.end())
		return dp[a];
	
	dp.insert({a, solve(a / P) +  solve(a / Q)});
	return dp[a];
}

int main() {
	cin >> N >> P >> Q;
	dp.insert({0LL, 1LL});
	cout << solve(N);
	return 0;
}