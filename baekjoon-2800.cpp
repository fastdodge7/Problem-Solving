#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

string expression;
vector<pair<int, int>> parentheses;
vector<int> stck;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> expression;
	for(int i = 0; i < expression.size(); i++)
	{
		if(expression[i] == '(')
			stck.push_back(i);
		if(expression[i] == ')')
		{
			parentheses.push_back({stck.back(), i});
			stck.pop_back();
		}
	}

	vector<string> ans;
	for(int bits = 1; bits < (1 << parentheses.size()); bits++)
	{
		vector<int> ignore;
		int idx = 0;
		for(int check = (1 << parentheses.size() - 1); check > 0; check >>= 1)
		{
			if((check & bits) > 0)
			{
				ignore.push_back(parentheses[idx].first);
				ignore.push_back(parentheses[idx].second);
			}
			idx++;
		}

		sort(ignore.begin(), ignore.end());

		char str[201];
		idx = 0;
		int stidx = 0;
		for(int i = 0; i < expression.size(); i++)
		{
			if(idx < ignore.size() && i == ignore[idx])
			{
				idx++;
				continue;
			}
			str[stidx++] = expression[i];
		}
		str[stidx] = '\0';
		ans.push_back(str);
	}

	sort(ans.begin(), ans.end());

	string lastStr = "";
	for(auto& a : ans)
	{
		if(lastStr == a) continue;
		cout << a << '\n';
		lastStr = a;
	}
		
	return 0;
}