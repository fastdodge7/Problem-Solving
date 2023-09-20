#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

long long N, M;

long long parent[1001];

long long Find(long long a)
{
	if(parent[a] <= 0) return a;
	return parent[a] = Find(parent[a]);
}

void Union(long long a, long long b)
{
	a = Find(a);
	b = Find(b);
    if(a == b) return;
	parent[b] = a;
}

typedef struct edge{
	long long a, b;
	double cost;
	bool operator<(const edge& other) const { return cost < other.cost; }
}edge;

vector<edge> arr;
pair<long long, long long> gods[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> N >> M;
	for(long long i = 1; i <= N; i++)
	{
		long long a, b; cin >> a >> b;
		gods[i] = {a, b};
	}

	
	long long cnt = N;
	for(long long i = 0; i < M; i++)
	{
		long long a, b; cin >> a >> b;
		if(Find(a) == Find(b)) continue;
		Union(a, b);
		cnt--;
	}

	double ans = 0.0f;

	for(long long i = 1; i < N; i++) for(long long j = i + 1; j <= N; j++)
	{
		long long dx = gods[i].first - gods[j].first;
		long long dy = gods[i].second - gods[j].second;

		arr.push_back({i, j, (double)sqrt(dx*dx + dy*dy)});
	}

	sort(arr.begin(), arr.end());


	for(long long i = 0; i < arr.size(); i++)
	{
		if(cnt == 1) break;
		if(Find(arr[i].a) == Find(arr[i].b)) continue;
		Union(arr[i].a, arr[i].b);
		cnt--;
		ans += arr[i].cost;
	}

	cout << fixed;
	cout.precision(2);
	cout << round(ans * 100) / 100 << '\n';

	return 0;
}