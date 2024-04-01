#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int BLACK = 0;
constexpr int GRAY = 1;
constexpr int WHITE = 2;

int N, M;
vector<int> matrix[10001];
bool visited[10001];

int DFS(int cur)
{
    if(visited[cur]) return 0;

    visited[cur] = true;
    int ret = 1;
    for(int next : matrix[cur])
    {
        ret += DFS(next);
    }
    
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        matrix[b].push_back(a);
    }

    vector<pair<int, int>> ans;
    for(int i = 1; i <= N; i++)
    {
        ans.push_back({DFS(i), i});
        fill(visited, visited + 10001, false);
    }

    sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    for(vector<pair<int, int>>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++)
    {
        if(it->first == ans[0].first)
            cout << it->second << ' ';
    }
    return 0;
}