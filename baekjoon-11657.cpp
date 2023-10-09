#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr long long INF = (1LL<<62LL) - 1 + (1LL << 62LL);

typedef struct Edge {
    int a, b, c;
}Edge;

int N, M;
long long dist[501];
vector<Edge> edges;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(dist, dist + 501, INF);
    dist[1] = 0;

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({ a, b, c });
    }

    for (int i = 1; i < N; i++)
    {
        for (const Edge& e : edges)
        {
            if (dist[e.a] == INF) continue;
            dist[e.b] = min(dist[e.b], dist[e.a] + e.c);
        }
    }

    for (const Edge& e : edges)
    {
        if (dist[e.a] == INF) continue;
        if (dist[e.b] > dist[e.a] + e.c)
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 2; i <= N; i++)
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';

    return 0;
}