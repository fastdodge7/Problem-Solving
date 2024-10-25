#include <iostream>
#include <algorithm>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

typedef struct Node{
	int a, b;
	bool operator<(const Node& other) const {
		if(b == other.b)
			return a < other.a;
		return b < other.b;
	}
}Node;

bool compare(const Node& a, const Node& b)
{
	return a.a < b.a;
}

int C, N;
Node arr[20000];
multiset<int> chicken;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >>C >> N;
	for(int i = 0; i < C; i++)
	{
		int temp; cin >> temp;
		chicken.insert(temp);
	}
		
	for(int i = 0; i < N; i++)
		cin >> arr[i].a >> arr[i].b;

	sort(arr, arr + N);

	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		auto it = chicken.lower_bound(arr[i].a);
		if(it != chicken.end() && *it <= arr[i].b)
		{
			ans++;
			chicken.erase(it);
		}
	}

	cout << ans;
	return 0;
}