#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int board[200][200];

typedef struct Node{
    int time;
    int r, c;
    bool operator<(const Node& other) const {
        return board[r][c] < board[other.r][other.c];
    }
}Node;

int N, K, S, X, Y;

void BFS()
{
    vector<Node> initList;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    {
        if(board[i][j] > 0)
            initList.push_back({0, i, j});
    }

    sort(initList.begin(), initList.end());

    queue<Node> Q;
    for(auto nod: initList)
        Q.push(nod);
    

    while(!Q.empty())
    {
        auto [t, r, c] = Q.front(); Q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dy[i];
            int nc = c + dx[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(t == S) continue;
            if(board[nr][nc] > 0) continue;

            Q.push({t + 1, nr, nc});
            board[nr][nc] = board[r][c];
        }
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
        cin >> board[i][j];
    
    cin >> S >> X >> Y;
    BFS();
    cout <<board[X - 1][Y - 1];
    return 0;
}