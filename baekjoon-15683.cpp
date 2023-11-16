#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

typedef struct Node {
	int r, c;
	int type;
	int rot;
}Node;

vector<vector<int>> camera = {
	{2},
	{0, 2},
	{1, 2},
	{0, 1, 2},
	{0, 1, 2, 3}
};

int arr[8][8];
vector<Node> camInfo;
int N, M;

int wallCnt = 0;

int check()
{
	int copyArr[8][8];
	memcpy(copyArr, arr, sizeof(arr));

	for (Node node : camInfo)
	{
		for (int dir : camera[node.type])
		{
			dir = (dir + node.rot) % 4;
			int step = 1;
			while (1)
			{
				int nr = node.r + dy[dir] * step;
				int nc = node.c + dx[dir] * step;
				if (nr < 0 || nr >= N || nc < 0 || nc >= M) break;
				if (copyArr[nr][nc] == 6) break;
				copyArr[nr][nc] = 9;
				step++;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copyArr[i][j] == 0)
				ret++;
		}
	}
	return ret;
}

int DFS(int camIndex)
{
	if (camIndex == camInfo.size())
		return check();

	if (camInfo[camIndex].type == 5)
		return DFS(camIndex + 1);

	int ret = 999999;
	for (int i = 0; i < 4; i++)
	{
		camInfo[camIndex].rot = i;
		ret = min(ret, DFS(camIndex + 1));
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 6)
			{
				wallCnt++;
				continue;
			}
			if (arr[i][j] != 0)
			{
				camInfo.push_back({ i, j, arr[i][j] - 1, 0 });
				continue;
			}	
		}
	}

	cout << DFS(0);
	return 0;
}