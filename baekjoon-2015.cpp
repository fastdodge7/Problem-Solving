#include <stdio.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, K;
int prefix;
unordered_map<int, long long> hashT;

int main() {
	long long ans = 0;
	hashT.insert({0, 1});

	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++)
	{
		int temp; scanf("%d", &temp);
		prefix += temp;

		if(hashT.find(prefix - K) != hashT.end())
			ans += hashT[prefix - K];

		if(hashT.find(prefix) == hashT.end())
			hashT.insert({prefix, 1});
		else
			hashT[prefix] += 1;
	}

	printf("%lld", ans);
	return 0;
}