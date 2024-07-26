#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int R, C;
string board[20];
bool visited[20][20];

int numbering[20][20];
int dist[21][21];

bool dfsVisited[21];

typedef struct Node{
    int cnt;
    int r, c;
}Node;

vector<pair<int, int>> dirty = {};

void BFS(int r, int c, int num)
{
    fill(&visited[0][0], &visited[19][19] + 1, false);
    queue<Node> Q; Q.push({0, r, c});
    visited[r][c] = true;

    while(!Q.empty())
    {
        auto [cnt, cr, cc] = Q.front(); Q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = cr + dy[i];
            int nc = cc + dx[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(board[nr][nc] == 'x') continue;
            if(visited[nr][nc]) continue;

            if(board[nr][nc] == '*')
                dist[num][numbering[nr][nc]] = cnt + 1;

            Q.push({cnt + 1, nr, nc});
            visited[nr][nc] = true;
        }
    }
}

int ans = 1e9;
int DFS(int depth, int curNum, int acc)
{
    if(depth == dirty.size() - 1)
    {
        ans = min(ans, acc);
        return acc;
    }

    if(acc >= ans) return acc;

    dfsVisited[curNum] = true;

    int ret = 1e9;
    for(int i = 0; i < dirty.size(); i++)
    {
        int num = i + 1;
        if(dfsVisited[num]) continue;

        if(dist[curNum][num] < 1e9)
            ret = min(ret, DFS(depth + 1, num, acc + dist[curNum][num]));
    }

    dfsVisited[curNum] = false;
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        cin >> C >> R;
        if(R == 0 && C == 0) return 0;

        fill(&numbering[0][0], &numbering[19][19] + 1, 0);
        fill(&dist[0][0], &dist[20][20] + 1, 1e9);
        fill(dfsVisited, dfsVisited + 21, false);
        dirty.clear();
        ans = 1e9;


        int num = 1;

        int startR, startC;
        vector<pair<int, int>> temp = {};
        for(int i = 0; i < R; i++)
        {
            cin >> board[i];
            for(int j = 0; j < C; j++)
            {
                if(board[i][j] == '*')
                {
                    temp.push_back({i, j});
                    numbering[i][j] = num++;
                }  
                if(board[i][j] == 'o')
                {
                    startR = i;
                    startC = j;
                } 
            }
        }

        dirty = {{startR, startC}};
        for(auto p : temp)
            dirty.push_back(p);

        for(int i = 0; i < dirty.size(); i++)
        {
            auto [r, c] = dirty[i];
            BFS(r, c, i);
        }

        DFS(0, 0, 0);

        cout << (ans < 1e9 ? ans : -1) << '\n';
    }
    return 0;
}