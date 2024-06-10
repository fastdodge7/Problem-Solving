#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
string str;
vector<string> ans;

string solve(int idx, int cnt)
{
	if(cnt == 0)
	{
		ans.push_back(str);
		return str;
	}

	if(idx == str.size() - 1 && cnt > 0)
	{
		if(cnt % 2 == 1)
		{
			bool visited[10];
			fill(visited, visited + 10, false);
			for(auto c : str)
			{
				if(visited[c - '0'])
				{
					ans.push_back(str);
					return str;
				} 
				visited[c - '0'] = true;
			}
			swap(str[str.size() - 1], str[str.size() - 2]);
			ans.push_back(str);
			swap(str[str.size() - 1], str[str.size() - 2]);
			return str;
		}
		ans.push_back(str);
		return str;
	}

	vector<int> cand = {idx};
	for(int i = idx + 1; i < str.size(); i++)
	{
		if(str[i] >= str[cand.back()])
		{
			if(str[i] > str[cand.back()])
				cand.clear();
			cand.push_back(i);
		}
	}
	
	if(str[cand.back()] != str[idx])
	{
		for(int i : cand)
		{
			swap(str[idx], str[i]);
			solve(idx + 1, cnt - 1);
			swap(str[idx], str[i]);
		}
		return str;
	}
	else
		return solve(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str >> N;
	if(str.size() == 1 || (str.size() == 2 && str.back() == '0'))
		cout << -1;
	else
	{
		solve(0, N);
		sort(ans.begin(), ans.end());
		cout << ans.back();
	} 

	return 0;
}