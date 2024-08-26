#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
vector<string> ans;
bool visited[20];
string output = "";
string lastStr;

void permutation(string& origin, int depth)
{
	if(depth == origin.size())
	{
		cout << output << '\n';
		lastStr = output;
		return;
	}
	
	if(!lastStr.empty() && output < lastStr) return;

	for(int i = 0; i < origin.size(); i++)
	{
		if(visited[i]) continue;
		output += origin[i];
		visited[i] = true;
		permutation(origin, depth + 1);
		visited[i] = false;
		output.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string str; cin >> str;
		sort(str.begin(), str.end());
		permutation(str, 0);
		lastStr = "";
	}
	return 0;
}