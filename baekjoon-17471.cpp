#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <bitset>

using namespace std;

vector<int> matrix[11];
int arr[11];
int visited[11];

int N;

int BFS(int start, int mark, const int colorFlag)
{
	if(visited[start] > 0) return 0;
	queue<int> Q; Q.push(start);
	visited[start] = mark;
	int startFlag = (((1 << (start - 1)) & colorFlag) > 0) ? 1 : 0;

	//cout << "start pos : " << start << " / startFlag : " << startFlag << " / mark : " << mark << '\n';
	
	int ret = 0;
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		ret += arr[cur];
			
		for(int next : matrix[cur])
		{
			if(visited[next]) continue;
			int curFlag = (((1 << (next - 1)) & colorFlag) > 0) ? 1 : 0;
			if(curFlag != startFlag) continue;

			
			//cout << "cur pos : " << next << " / curFlag : " << curFlag << '\n';
			visited[next] = mark;
			Q.push(next);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];
	
	for(int i = 1; i <= N; i++)
	{
		int cnt; cin >> cnt;
		for(int j = 0; j < cnt; j++)
		{
			int k; cin >> k;
			matrix[i].push_back(k);
			matrix[k].push_back(i);
		}
	}

	int ans = 1e9;

	for(int colorFlag = 32-1; colorFlag < (1<<N) - 1; colorFlag++)
	{
		//cout << "BeatSet : " << bitset<10>(colorFlag) << '\n';
		fill(visited, visited + N + 1, 0);
		int mark = 1;
		int red = 0, blue = 0;
		bool acceptable = true;
		for(int i = 1; i <= N; i++)
		{
			
			if(visited[i] == 0)
			{
				if(red == 0)
					red = BFS(i, mark++, colorFlag);
				else
					blue = BFS(i, mark++, colorFlag);
			}

			if(mark > 3)
			{
				acceptable = false;
				break;
			}
		}

		if(acceptable)
		{
			//cout << "RED : " << red << " / Blue : " << blue << '\n';
			ans = min(ans, abs(blue - red));
		}
			
	}
	if(ans == 1e9)
		ans = -1;
	
	cout << ans << '\n';
	return 0;
}
