#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <tuple>
#include <cmath>

using namespace std;


constexpr int dir[4] = {'L', 'U', 'R', 'D'};
constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

constexpr int UNKNOWN = 1;
constexpr int ESCAPABLE = 2;
constexpr int TRAPPED = 3;

int N, M;
string board[500];
int visited[500][500];

void proc(int r, int c)
{
    if(visited[r][c] != 0) return;
    vector<pair<int, int>> stck = {{r, c}};

    while(1)
    {
        auto [r, c] = stck.back();
        visited[r][c] = UNKNOWN;

        int nr = r, nc = c;
        for(int i = 0; i < 4; i++)
        {
            if(board[r][c] == dir[i])
            {
                nr += dy[i];
                nc += dx[i];
                break;
            }
        }

        if(nr < 0 || nr >= N || nc < 0 || nc >= M)
        {
            for(auto [tr, tc] : stck)
                visited[tr][tc] = ESCAPABLE;
            break;
        }
        else if(visited[nr][nc] == UNKNOWN)
        {
            for(auto [tr, tc] : stck)
                visited[tr][tc] = TRAPPED;
            break;
        }
        else if(visited[nr][nc] == ESCAPABLE || visited[nr][nc] == TRAPPED)
        {
            for(auto [tr, tc] : stck)
                visited[tr][tc] = visited[nr][nc];
            break;
        }
        else
        {
            stck.push_back({nr, nc});
        }
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
    {
        proc(i, j);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
    {
        if(visited[i][j] == ESCAPABLE)
            ans++;
    }

    cout << ans;
    return 0;
}