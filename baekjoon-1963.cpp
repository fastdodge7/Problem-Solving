#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int NOT_PRIME = -1;

int T;
int table[10000];

void eratos()
{
	table[0] = table[1] = NOT_PRIME;
	for(int i = 2; i < 10000; i++)
	{
		if(table[i] == 0)
		{
			for(int mult = 2; mult * i < 10000; mult++)
				table[i * mult] = NOT_PRIME;
		}
	}
}

int BFS(int start, int target)
{
	if(start == target) return 0;
	queue<pair<int, int>> Q; Q.push({start, 0});
	table[start] = true;
	int increment[5] = {1, 10, 100, 1000, 10000};

	while(!Q.empty())
	{
		auto [cur, cnt] = Q.front(); Q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int temp = (cur / increment[i + 1]) * increment[i + 1] + (cur % increment[i]);
			
			for(int newNum = 0; newNum < 10; newNum++)
			{
				if(i == 3 && newNum == 0) continue;
				temp += increment[i] * newNum;

				if(table[temp] == 0)
				{
					if(temp == target) 
						return cnt + 1;
					Q.push({temp, cnt + 1});
					table[temp] = true;
				}
				temp -= increment[i] * newNum;
			}
		}
	}
	return -1;
}

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);

	eratos();
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++)
	{
		int start, end; cin >> start >> end;

		int result = BFS(start, end);

		if(result == -1)
			cout << "impossible\n";
		else
			cout << result << '\n';

		for(int i = 2; i < 10000; i++)
		{
			if(table[i] == true)
				table[i] = 0;
		}
	}
	return 0;
}