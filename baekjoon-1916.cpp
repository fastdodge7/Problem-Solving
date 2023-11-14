#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 2e9 + 7;

int N, M;
vector<pair<int, int>> matrix[1001];
int dist[1001];
int startP, endP;

int dijkstra(int s, int e)
{
    fill(dist, dist + N + 1, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while(!pq.empty())
    {
        int curNode = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(curNode == e)
            return cost;

        if(cost > dist[curNode]) 
            continue;

        for(pair<int, int> next : matrix[curNode])
        {
            int nextNode = next.first;
            int edgeCost = next.second;
            if(cost + edgeCost < dist[nextNode])
            {
                pq.push({cost + edgeCost, nextNode});
                dist[nextNode] = cost + edgeCost;

            }
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        matrix[a].push_back({b, c});
    }
    cin >> startP >> endP;

    cout << dijkstra(startP, endP);
    return 0;
}