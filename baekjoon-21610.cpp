#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

constexpr int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
constexpr int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int diay[4] = {-1, -1, 1, 1};
constexpr int diax[4] = {-1, 1, 1, -1};

int N, M;
int bucket[50][50];
int cloud[50][50];

void moveCloud(int d, int s)
{
	vector<pair<int, int>> cand;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(cloud[i][j] == 1)
			cand.push_back({i, j});
	}		

	fill(&cloud[0][0], &cloud[49][49] + 1, 0);

	for(int i = 0; i < cand.size(); i++)
	{
		auto [r, c] = cand[i];
		r = (r + dy[d] * s + N * 50) % N;
		c = (c + dx[d] * s + N * 50) % N;
		cloud[r][c] = 1;
	}
}

void fillBucket()
{
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(cloud[i][j] == 1)
			bucket[i][j] += 1;
	}	
}

void waterCopyBug()
{
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(cloud[i][j] == 1)
		{
			int cnt = 0;
			for(int dir = 0; dir < 4; dir++)
			{
				int nr = i + diay[dir];
				int nc = j + diax[dir];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				if(bucket[nr][nc] > 0)
				{
					cnt++;
				}
			}
			bucket[i][j] += cnt;
		}
	}	
}

void genCloud()
{
	vector<pair<int, int>> cand;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(cloud[i][j] == 1) continue;
		if(bucket[i][j] >= 2)
		{
			bucket[i][j] -= 2;
			cand.push_back({i, j});
		}
	}
	fill(&cloud[0][0], &cloud[49][49] + 1, 0);

	for(auto [r, c] : cand) cloud[r][c] = 1;	
}

void printCloud()
{
	for(int i = 0; i < N; i++) 
	{
		for(int j = 0; j < N; j++)
		{
			cout << cloud[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "=======================================\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> bucket[i][j];

	cloud[N - 1][0] = cloud[N - 1][1] = cloud[N - 2][0] = cloud[N - 2][1] = 1;
	
	for(int i = 0; i < M; i++)
	{
		int d, s; cin >> d >> s;
		moveCloud(d - 1, s);
		fillBucket();
		waterCopyBug();
		genCloud();
	}

	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		ans += bucket[i][j];
	}

	cout << ans;
	return 0;
}