#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
char color[1001];
int parent[1001];


typedef struct Edge {
    int a, b;
    int cost;
    bool operator>(const Edge& other) const { return cost > other.cost; }
}Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int Find(int a)
{
    if (parent[a] <= 0)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    parent[b] = a;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> color[i];

    for (int i = 0; i < M; i++)
    {
        int a, b, cost; cin >> a >> b >> cost;
        if (color[a] == color[b]) continue;
        pq.push({ a, b, cost });
    }

    int ans = 0;
    int cnt = N;
    while (!pq.empty())
    {
        Edge cur = pq.top(); pq.pop();
        if (Find(cur.a) == Find(cur.b)) continue;

        ans += cur.cost;
        cnt--;
        Union(cur.a, cur.b);
    }

    ans = (cnt == 1 ? ans : -1);
    cout << ans;
    return 0;
}