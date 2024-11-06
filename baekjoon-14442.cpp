#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int R, C, K;
string board[1000];
bool visited[1000][1000][11];

int BFS()
{
    queue<tuple<int, int, int, int>> Q;
    Q.push({0, 0, 0, 1});
    visited[0][0][0] = true;

    while(!Q.empty())
    {
        auto [r, c, cnt, dist] = Q.front(); Q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C ) continue;
            if(nr == R - 1 && nc == C - 1) return dist + 1;
            if(board[nr][nc] == '1')
            {
                if(cnt == K) continue;
                if(visited[nr][nc][cnt + 1]) continue;
                Q.push({nr, nc, cnt + 1, dist + 1});
                visited[nr][nc][cnt + 1] = true;
            }
            else
            {
                if(visited[nr][nc][cnt]) continue;
                Q.push({nr, nc, cnt, dist + 1});
                visited[nr][nc][cnt] = true;
            }
        }
    }
    return -1;
}


int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C>> K;
    for(int i = 0; i < R; i++) 
        cin >> board[i];
    
    cout << BFS() << '\n';
    return 0;
}