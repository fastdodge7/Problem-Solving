#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int N, M;
int islandCnt = 0;

int board[100][100];
int islandMark[100][100];
int dist[7][7];

int parent[7];

typedef struct Edge{
    int s, e;
    int cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
}Edge;

int BFS(int r, int c, int mark)
{
    if(islandMark[r][c] > 0 || board[r][c] == 0) 
        return 0;

    queue<pair<int, int>> Q;
    Q.push({r, c});
    islandCnt++;
    islandMark[r][c] = mark;

    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = cur.first + dy[i];
            int nc = cur.second + dx[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] == 0) continue;
            if(islandMark[nr][nc] > 0) continue;

            islandMark[nr][nc] = mark;
            Q.push({nr, nc});
        }        
    }
    return 1;
}

int castRay(int r, int c)
{
    if(islandMark[r][c] == 0) 
        return 0;
    
    int start = islandMark[r][c];
    for(int i = 0; i < 4; i++)
    {
        int step = 1;
        while(1)
        {
            int nr = r + dy[i] * step;
            int nc = c + dx[i] * step;
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) break;
            if(islandMark[nr][nc] == start) break;
            if(islandMark[nr][nc] != start && islandMark[nr][nc] > 0)
            {
                if(step > 2)
                    dist[start][islandMark[nr][nc]] = min(dist[start][islandMark[nr][nc]], step - 1);
                break;
            }
            step++;
        }
    }
    return 1;
}

int Find(int a)
{
    if(parent[a] == 0)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a == b) return;
    parent[b] = a;
}

void printIsland()
{
    cout << "섬 정보 표시\n";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << islandMark[i][j] << ' ';
        cout << '\n';
    }
}

void printDist()
{
    cout << "거리 정보 표시\n";
    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dist[0][0], &dist[6][6] + 1, 1e9);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            BFS(i, j, islandCnt + 1);
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            castRay(i, j);
    }

    // printIsland();
    // printDist();

    vector<Edge> arr;
    for(int i = 1; i < 7; i++)
    {
        for(int j = i + 1; j < 7; j++)
        {
            if(dist[i][j] < 1e9)
            {
                arr.push_back({i, j, dist[i][j]});
            }
        }
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    for(Edge e : arr)
    {
        //cout << e.s << " -> " << e.e << " / cost : " << e.cost << '\n';
        if(Find(e.s) == Find(e.e)) continue;
        Union(e.s, e.e);
        islandCnt--;
        ans += e.cost;
    }

    if(islandCnt > 1)
        cout << -1 ;
    else 
        cout << ans;

    return 0;
}
