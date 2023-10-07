#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int parent[17][50001];
int visited[50001];
vector<int> arr[50001];

void DFS(int cur, int depth)
{
    visited[cur] = depth;
    parent[0][cur] = cur;

    for (int level = 2; level <= 16; level++)
    {
        if (parent[level - 1][cur] == 0) break;
        parent[level][cur] = parent[level - 1][parent[level - 1][cur]];
    }

    for (int next : arr[cur])
    {
        if (visited[next]) continue;
        parent[1][next] = cur;
        DFS(next, depth + 1);
    }
}

int LCA(int a, int b)
{
    if (visited[a] < visited[b]) swap(a, b);
    for (int i = 16; i >= 1; i--)
    {
        if (visited[parent[i][a]] < visited[b]) continue;
        a = parent[i][a];
    }
    if (a == b) return a;
    for (int i = 16; i >= 1; i--)
    {
        if (parent[i][a] == parent[i][b]) continue;
        a = parent[i][a];
        b = parent[i][b];
    }
    return parent[1][a];
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    DFS(1, 1);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

    return 0;
}