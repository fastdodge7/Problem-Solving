#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9 + 7;

int T, N, D, S;
int dist[10001];

vector<pair<int, int>> matrix[10001];

void dijkstra(int start)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first > dist[cur.second]) continue;
        
        dist[cur.second] = cur.first;

        for(auto edge : matrix[cur.second])
        {
            int nextNode = edge.first;
            int newDist = cur.first + edge.second;

            if(newDist >= dist[nextNode]) continue;
            dist[nextNode] = newDist;
            pq.push({newDist, nextNode});
        }
    }
}

int main(int argc, char *argv[])
{
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++)
    {


        cin >> N >> D >> S;
        for(int i = 0; i < D; i++)
        {
            int a, b, c; cin >> a >> b >> c;
            //matrix[a].push_back({b, c});
            matrix[b].push_back({a, c});
        }
        fill(dist, dist + N + 1, INF);

        dijkstra(S);

        int cnt = 0;
        int maxTime = 0;
        for(int i = 1; i <= N; i++)
        {
            if(dist[i] != INF)
            {
                cnt++;
                maxTime = max(maxTime, dist[i]);
            }
        }
        
        cout << cnt << ' ' << maxTime << '\n';

        for(int i = 1; i <= N; i++)
            matrix[i].clear();
    }
    return 0;
}