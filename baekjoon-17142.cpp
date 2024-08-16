#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, M;
int board[50][50];
int visited[50][50];
vector<pair<int, int>> arr;

int BFS(const vector<int>& cand)
{
    fill(&visited[0][0], &visited[49][49] + 1, -1);
    queue<pair<int, int>> Q;
    for(int idx : cand)
    {
        Q.push(arr[idx]);
        visited[arr[idx].first][arr[idx].second] = 0;
    }

    int ans = 0;
    while(!Q.empty())
    {
        const auto [r, c] = Q.front(); Q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visited[nr][nc] >= 0 && visited[r][c] + 1 >= visited[nr][nc]) continue;
            if(board[nr][nc] == 1) continue;

            Q.push({nr, nc});
            if(board[nr][nc] != 2)
                ans = visited[r][c] + 1;
            visited[nr][nc] = visited[r][c] + 1;
        }
    }

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    {
        if(visited[i][j] == -1 && board[i][j] == 0)
            return 1e9;
    }
    return ans;
}

bool setComb(vector<int>& cand)
{
    int idx = cand.size() - 1;
    for(idx; idx >= 0; idx--)
    {
        int maxVal = arr.size() - (cand.size() - idx);
        if(idx == 0 && maxVal == cand[idx]) return false;
        if(maxVal == cand[idx]) continue;
        cand[idx] += 1;
        for(int i = idx + 1; i < cand.size(); i++)
        {
            cand[i] = cand[i - 1] + 1;
        }
        return true;
    }
    return false;
}

int solve()
{
    vector<int> cand = {};
    for(int i = 0; i < M; i++)
        cand.push_back(i);

    int ans = 1e9;
    while(1)
    {
        ans = min(ans, BFS(cand));
        if(cand[0] == arr.size() - cand.size()) break;
        setComb(cand); 
    }

    return ans == 1e9 ? -1 : ans;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    {
        cin >> board[i][j];
        if(board[i][j] == 2)
            arr.push_back({i, j});
    }

    cout << solve();
    return 0;
}