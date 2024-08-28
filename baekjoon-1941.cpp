#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

string board[5];
bool selected[5][5];
int visited[5][5];
vector<pair<int, int>> candidates;

vector<int> comb = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};

int DFS(int depth, int cnt, int r, int c)
{
    if(7 - depth + cnt < 4) return 0;
    if(depth == 7){ 
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cout << (visited[i][j] ? 'X' : 'O');
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }

    visited[r][c] = true;

    int ret = 0;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
        if(visited[nr][nc]) continue;
        ret += DFS(depth + 1, cnt + (int)(board[r][c] == 'S'), nr, nc);
    }

    visited[r][c] = false;
    return ret;
}

bool check()
{
    fill(&visited[0][0], &visited[4][4] + 1, false);
    for(int i = 0; i < 25; i++)
    {
        if(comb[i] == 1)
        {
            queue<pair<int, int>> Q; Q.push({i / 5, i % 5});
            visited[i / 5][i % 5] = true;

            int cnt = 0;
            int target =0; 
            while(!Q.empty())
            {
                auto [r, c] = Q.front(); Q.pop();
                cnt++;
                if(board[r][c] == 'S') target++;

                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dy[i];
                    int nc = c + dx[i];
                    if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                    if(visited[nr][nc]) continue;
                    if(comb[nr * 5 + nc] == 0) continue;

                    Q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }

            return cnt == 7 && target >= 4;
        }
    }
}
int solve()
{
    int ans = 0;
    int count = 0;
    do{
        if(check())
            ans++;
    }
    while(next_permutation(comb.begin(), comb.end()));
    return ans;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 5; i++)
        cin >> board[i];

    cout << solve();
    return 0;
}