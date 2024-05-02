#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>

using namespace std;

int T, N;
unordered_map<string, string> parent;
unordered_map<string, int> cnt;

string UFind(const string& name)
{
	if(parent[name] == name)
		return name;
	return parent[name] = UFind(parent[name]);
}

void Union(const string& a, const string& b)
{
	string na = UFind(a);
	string nb = UFind(b);
	if(na == nb) return;
	parent[nb] = na;
	cnt[na] = cnt[na] + cnt[nb]; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		string firstName = "";
		for(int i = 0; i < N; i++)
		{
			string str1, str2; cin >> str1 >> str2;
			if(firstName.empty())
				firstName = str1;

			if(parent.find(str1) == parent.end())
			{
				parent[str1] = str1;
				cnt[str1] = 1;
			}
			if(parent.find(str2) == parent.end())
			{
				parent[str2] = str2;
				cnt[str2] = 1;
			}

			Union(str1, str2);

			string printer = UFind(str1);
			cout << cnt[printer] << '\n';
		}
		
		parent = unordered_map<string, string>();
		cnt = unordered_map<string, int>();
	}

	return 0;
}
