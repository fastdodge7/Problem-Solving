#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9 + 7;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int N, M;
pair<int, int> dist[50][50];
char board[50][50];

typedef struct Node {
    int r, c;
    pair<int, int> cnt;

    bool operator>(const Node& other) const { return cnt > other.cnt; }
}Node;

void dijkstra(int startR, int startC)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({ startR, startC, {0, 0} });

    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (cur.cnt > dist[cur.r][cur.c]) continue;

        dist[cur.r][cur.c] = cur.cnt;

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.r + dy[i];
            int nc = cur.c + dx[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            pair<int, int> newCnt = pair<int, int>(cur.cnt);
            if (board[nr][nc] == 'g') newCnt.first++;
            if (board[nr][nc] == 'n') newCnt.second++;

            if (newCnt >= dist[nr][nc]) continue;
            dist[nr][nc] = newCnt;
            pq.push({ nr, nc, newCnt });
        }
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        dist[i][j] = { INF, INF };

    int startR, startC;
    int targetR, targetC;

    for (int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'S')
            {
                startR = i;
                startC = j;
            }
            if (board[i][j] == 'F')
            {
                targetR = i;
                targetC = j;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'g')
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    int nr = i + dy[dir];
                    int nc = j + dx[dir];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    board[nr][nc] = (board[nr][nc] == '.' ? 'n' : board[nr][nc]);
                }
            }
        }
    }

    dijkstra(startR, startC);

    cout << dist[targetR][targetC].first << ' ' << dist[targetR][targetC].second << '\n';
    return 0;
}