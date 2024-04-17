#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(const string& str, int start, int end, int flag)
{
	if(start >= end) return flag;

	if(str[start] == str[end])
		return solve(str, start + 1, end - 1, flag);

	if(flag == 1)
		return 2;
	
	int rightDel = (str[start] == str[end - 1] ? solve(str, start, end - 1, 1) : 2);
	int leftDel = (str[start + 1] == str[end] ? solve(str, start + 1, end, 1) : 2);
	
	return (leftDel + rightDel) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N; cin >> N;
	for(int i = 0; i < N; i++)
	{
		string str; cin >> str;
		cout << solve(str, 0, str.size() - 1, 0) << '\n';
	}
	return 0;
}