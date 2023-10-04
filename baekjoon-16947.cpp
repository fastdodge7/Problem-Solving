#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

constexpr int WHITE = 0;
constexpr int GRAY = 1;
constexpr int BLACK = 2;
constexpr int CYCLE_START_POIONT = 3;

int station[3001];
vector<int> edges[3001];
int visited[3001];

int N;

bool cycle_detected = false;
bool cycle_resolved = false;

void findCycle(int cur, int parent)
{
	visited[cur] = GRAY;

	for (int next : edges[cur])
	{
		if (visited[next] == WHITE)
		{
			findCycle(next, cur);
		}
		else if (visited[next] == GRAY && next != parent)
		{
			visited[next] = CYCLE_START_POIONT;
			cycle_detected = true;
			station[cur] = station[next] = 0;
			return;
		}
		if (cycle_detected) break;
	}

	if (!cycle_resolved && cycle_detected && visited[cur] != CYCLE_START_POIONT)
		station[cur] = 0;

	if (cycle_detected && visited[cur] == CYCLE_START_POIONT)
		cycle_resolved = true;

	if (cycle_detected)
		return;

	visited[cur] = BLACK;
}

int DFS2(int cur)
{
	if (station[cur] == 0) return 0;
	if (station[cur] != 1e9) return station[cur];

	visited[cur] = true;

	for (int next : edges[cur])
	{
		if (station[next] == 0)
			return station[cur] = 1;
		if (visited[next] == false)
			station[cur] = min(station[cur], DFS2(next) + 1);
	}

	return station[cur];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(station, station + 3001, 1e9);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	findCycle(1, 0);
	for (int i = 1; i <= N; i++)
	{
		fill(visited, visited + 3001, false);
		station[i] = DFS2(i);
	}

	for (int i = 1; i <= N; i++)
		cout << station[i] << ' ';
	cout << '\n';

	return 0;
}