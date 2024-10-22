#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <tuple>
#include <cmath>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int N, M;
int cnt = 0;
int board[50][50];
vector<pair<int, int>> arr;
vector<pair<int, int>> init;
bool used[10];
bool visited[50][50];

int BFS()
{
    fill(&visited[0][0], &visited[49][49] + 1, false);
    int rest = cnt;
    queue<tuple<int, int, int>> Q;
    for(auto [r, c] : init)
    {
        Q.push({r, c, 0});
        visited[r][c] = true;
    }

    int ret = 0;
    while(!Q.empty())
    {
        auto [r, c, timestamp] = Q.front(); Q.pop();
        ret = max(ret, timestamp);
        rest--;
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(board[nr][nc] == 1) continue;
            if(visited[nr][nc]) continue;
            Q.push({nr, nc, timestamp + 1});
            visited[nr][nc] = true;
        }
    }
    return rest > 0 ? 1e9 : ret;
}

int DFS(int depth, int lastIdx)
{
    if(depth == M)
    {
        return BFS();
    }

    int ret = 1e9;
    for(int i = lastIdx + 1; i < arr.size(); i++)
    {
        if(used[i]) continue;
        init.push_back(arr[i]);
        used[i] = true;
        ret = min(DFS(depth + 1, i), ret);
        used[i] = false;
        init.pop_back();
    }
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    {
        cin >> board[i][j];
        if(board[i][j] == 2)
            arr.push_back({i, j});
        if(board[i][j] == 1) continue;
        cnt++;
    }

    int ans =  DFS(0, -1);
    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}