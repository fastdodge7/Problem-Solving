#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, -1, 1};

int N, M, H;

typedef struct Node {
    int r, c, h;
    int cnt;
}Node;

int tomato[100][100][100];
int tomatoCnt = 0;

int BFS()
{
    queue<Node> Q;
    int maturedCnt = 0;
    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        {
            if (tomato[i][j][h] == 1)
                Q.push({ i, j, h, 0 });
        }
    }

    int ret = 0;
    while (!Q.empty())
    {
        Node cur = Q.front(); Q.pop();
        ret = cur.cnt;
        tomatoCnt--;
        
        for (int i = 0; i < 6; i++)
        {
            int nr = cur.r + dy[i];
            int nc = cur.c + dx[i];
            int nh = cur.h + dh[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M || nh < 0 || nh >= H)
                continue;
            if (tomato[nr][nc][nh] != 0) 
                continue;
            
            tomato[nr][nc][nh] = 1;
            Q.push({ nr, nc, nh, cur.cnt + 1 });
        }
    }
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;
    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        {
            cin >> tomato[i][j][h];
            if (tomato[i][j][h] != -1) tomatoCnt++;
        }
    }

    int ans = BFS();
    cout << (tomatoCnt > 0 ? -1 : ans);

    return 0;
}