#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;

vector<int> leftVec = { 0 };
vector<int> rightVec = { 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		if (a < 0) leftVec.push_back(-a);
		else rightVec.push_back(a);
	}

	sort(leftVec.begin(), leftVec.end());
	sort(rightVec.begin(), rightVec.end());
	int ans = 0;

	vector<int>& far = (leftVec.back() > rightVec.back() ? leftVec : rightVec);
	vector<int>& near = (leftVec.back() <= rightVec.back() ? leftVec : rightVec);

	while (near.size() > 0)
	{
		int cnt = min((int)near.size(), M);
		ans += 2 * near.back();
		for (int i = 0; i < cnt; i++)
			near.pop_back();
	}

	int cnt = min((int)far.size(), M);
	ans += far.back();
	for (int i = 0; i < cnt; i++)
		far.pop_back();

	while (far.size() > 0)
	{
		cnt = min((int)far.size(), M);
		ans += 2 * far.back();
		for (int i = 0; i < cnt; i++)
			far.pop_back();
	}

	cout << ans << '\n';
	return 0;
}