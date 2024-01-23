#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
char arr[15];

bool check(string str)
{
	int cnt = 0;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			cnt++;
	}
	return cnt > 0 && str.size() - cnt > 1;
}

void DFS(int idx, int level, string str)
{
	if(level == 0)
	{
		if(check(str))
			cout << str << '\n';
		return;
	}
	for(int i = idx; i <= C - level; i++)
		DFS(i + 1, level - 1, str + arr[i]);
}

int main() {
	// your code goes here
	
	cin >> L >> C;
	for(int i = 0; i < C; i++)
		cin >> arr[i];
		
	sort(arr, arr + C);
	
	DFS(0, L, "");
	return 0;
}