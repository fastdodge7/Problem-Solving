#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int RUNNER = 1;
constexpr int EMPTY = 0;

int N;
int cnt = 0;
vector<int> rotation = {2, 3, 4, 5, 6, 7, 8, 9};
bool visited[8];
int scoreBoard[51][10];


int calcTotalScore()
{
	int rot = 0;
	vector<int> playerList = {};
	for(int i = 0; i < rotation.size(); i++)
	{
		playerList.push_back(rotation[i]);
		if(playerList.size() == 3)
			playerList.push_back(1);
	}

	int totalScore = 0;
	for(int inning = 1; inning <= N; inning++)
	{
		int outs = 0;
		queue<int> runners;
		while(outs < 3)
		{
			int result = scoreBoard[inning][playerList[(rot++) % 9]];
			if(result == 0)
			{
				outs++;
				continue;
			}
			if(result == 4)
			{
				totalScore++;
				while(!runners.empty())
				{
					if(runners.front() == RUNNER)
						totalScore++;
					runners.pop();
				}
				continue;
			}

			runners.push(RUNNER);
			for(int i = 1; i < result; i++)
				runners.push(EMPTY);

			while(runners.size() > 3)
			{
				if(runners.front() == RUNNER)
					totalScore++;
				runners.pop();
			}
		}
	}

	return totalScore;
}


int permutation(int depth)
{
	if(depth == rotation.size())
	{
		cnt++;
		return calcTotalScore();
	}

	int res = 0;
	for(int i = depth; i < rotation.size(); i++)
	{
		swap(rotation[depth], rotation[i]);
		res = max(res, permutation(depth + 1));
		swap(rotation[depth], rotation[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= 9; j++)
		{
			cin >> scoreBoard[i][j];
		}
	}

	int ans = 0;
	cout << permutation(0) << '\n';
	return 0;
}
