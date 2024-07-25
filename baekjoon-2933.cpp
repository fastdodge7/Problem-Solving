#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

constexpr int VISITED = 1;
constexpr int AIR = 2;

int R, C, N;
string board[100];
int visited[100][100];
vector<pair<int, int>> target = {};


void printBoard()
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cout << visited[i][j] << ' ';

        }
        cout << endl;
    }
}


bool BFS(int r, int c)
{
    if(visited[r][c]) return false;
    if(board[r][c] == '.') return false;

    queue<pair<int, int>> Q; Q.push({r, c});
    visited[r][c] = true;
    vector<pair<int, int>> temp = {{r, c}};

    bool ret = false;

    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        if(cur.first == R - 1)
            ret = true;

        for(int i = 0; i < 4; i++)
        {
            int nr = cur.first + dy[i];
            int nc = cur.second + dx[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(board[nr][nc] == '.')continue;
            if(visited[nr][nc]) continue;

            Q.push({nr, nc});
            temp.push_back({nr, nc});
            visited[nr][nc] = VISITED;
        }
    }

    if(!ret)
    {
        target = vector<pair<int, int>>(temp);
    }
        

    return !ret;    
}

int calcDropDist()
{
    //printBoard();
    for(auto p : target)
    {
        visited[p.first][p.second] = AIR;
    }
    int minDist = 1e9;
    for(auto p : target)
    {
        auto [r, c] = p;
        for(int step = 1; r + step < R; step++)
        {
            int nr = r + step;
            if(board[nr][c] == 'x' && visited[nr][c] != AIR)
                minDist = min(minDist, step - 1);
            
            else if(nr == R - 1)
                minDist = min(minDist, step);
        }
    }
    return minDist;
}

void drop(int dist)
{
    if(dist == 1e9) return;
    for(auto p : target)
    {
        board[p.first][p.second] = '.';
    }
    int minDist = 1e9;
    for(auto p : target)
    {
        auto [r, c] = p;
        board[r + dist][c] = 'x';
    }
}
// 클러스터를 솎아낼 수 있어야 함.
// 각 클러스터가 바닥에 떨어졌는지 여부를 판정해야 함
// 각 클러스터를 얼마나 밑으로 이동해야 바닥에 떨어지는지 판정해야 함.


int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        cin >> board[i];

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int row; cin >> row;
        row = R - row;
        int step = i % 2 == 0 ? 1 : -1;
        int startPos = i % 2 == 0 ? 0 : C - 1;
        for(int j = startPos; 0 <= j && j < C; j += step)
        {
            if(board[row][j] == 'x')
            {
                board[row][j] = '.';
                break;
            }
        }

        fill(&visited[0][0], &visited[99][99] + 1, 0);
        bool flag =false;
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                if(BFS(r, c))
                {
                    drop(calcDropDist());
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
    }
    
    for(int i = 0; i < R; i++)
        cout << board[i] << '\n';
    
    return 0;
}