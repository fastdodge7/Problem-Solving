#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string tree;
int targetA = 0, targetB = 0;

int zeroIdx[2001];
int oneIdx[2001];
int trace[4001];

void solve()
{
	int cnt = 0;
	vector<int> stck;
	for(int i = 0; i < tree.size(); i++)
	{
		if(tree[i] == '0')
		{
			stck.push_back(++cnt);
			zeroIdx[cnt] = i;
			trace[i] = cnt;
		}
		else
		{
			oneIdx[stck.back()] = i;
			trace[i] = stck.back();
			stck.pop_back();
		}
	}

	if(trace[targetA - 1] == trace[targetB - 1])
	{
		int ans = trace[targetA - 1];
		cout << zeroIdx[ans] + 1 <<' ' << oneIdx[ans] + 1;
		return;
	}

	stck.clear();

	int minSize = -1;
	vector<int> cache = {};
	for(int i = 0; i < tree.size(); i++)
	{
		
		minSize = min(minSize, (int)stck.size());
		if(tree[i] == '0')
		{
			stck.push_back(trace[i]);
		}

		if(i + 1 == targetA)
		{
			minSize = stck.size();
			cache = vector<int>(stck);
		}
		else if(i + 1 == targetB)
		{
			int ans = -1;
			for(int i = 0; i < min(cache.size(), stck.size()); i++)
			{
				if(cache[i] == stck[i])
					ans = cache[i];
				else
					break;
			}
			cout << zeroIdx[ans] + 1 << ' ' << oneIdx[ans] + 1;
			return;
		}

		if(tree[i] == '1')
		{
			stck.pop_back();
		}	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> tree;
	cin >> targetA >> targetB;

	if(targetA > targetB) swap(targetA, targetB);

	solve();

	return 0;
}