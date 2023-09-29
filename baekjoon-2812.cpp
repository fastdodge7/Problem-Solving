#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	string str; cin >> str;

	vector<int> stck; stck.push_back(str[0] - '0');

	for (int i = 1; i < str.size(); i++)
	{
		int cur = str[i] - '0';
		while (!stck.empty() && stck.back() < cur && K > 0)
		{
			stck.pop_back();
			K--;
		}
		stck.push_back(cur);
	}
	while (K > 0)
	{
		stck.pop_back();
		K--;
	}
	for (int c : stck)
		cout << c;

	return 0;
}