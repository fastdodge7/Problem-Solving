#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[101];
vector<int> matrix[101];
vector<int> reverseMatrix[101];

int DFS(int start)
{
    visited[start] = true;

    int ret = 1;
    for (int next : matrix[start])
    {
        if (visited[next]) continue;
        ret += DFS(next);
    }

    return ret;
}

int DFS2(int start)
{
    visited[start] = true;

    int ret = 1;
    for (int next : reverseMatrix[start])
    {
        if (visited[next]) continue;
        ret += DFS2(next);
    }

    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        matrix[a].push_back(b);
        reverseMatrix[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        int a = DFS(i) - 1;
        fill(visited, visited + N + 1, false);
        int b = DFS2(i) - 1;
        fill(visited, visited + N + 1, false);
        cout << N - (a + b + 1) << '\n';
    }

    return 0;
}