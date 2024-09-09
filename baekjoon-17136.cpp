#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

bool board[10][10];
bool visited[10][10];
int arr[5] = {5, 5, 5, 5, 5};

vector<pair<int, int>> nodes;

bool canExpand(int r, int c, int width)
{
    if(width <= 1) return true;

    for(int i = r; i < r + width; i++) for(int j = c; j < c + width; j++)
    {
        if(i < 0 || i >= 10 || j < 0 || j >= 10) return false;
        if(visited[i][j]) return false;
        if(board[i][j] == 0) return false;
    }

    return true;
}

bool fillVisit(int r, int c, int width, bool boolean)
{
    for(int i = r; i < r + width; i++) for(int j = c; j < c + width; j++)
    {
        visited[i][j] = boolean;
    }
    return boolean;
}

int DFS(int cnt, int depth)
{
    if(depth >= nodes.size()) return cnt;

    auto [r, c] = nodes[depth];
    if(visited[r][c]) return DFS(cnt, depth + 1);

    int ret = 1e9;
    for(int wid = 1; wid <= 5; wid++)
    {
        if(arr[wid - 1] == 0) continue;
        if(canExpand(r, c, wid))
        {
            fillVisit(r, c, wid, true);
            arr[wid - 1]--;
            ret = min(ret, DFS(cnt + 1, depth + 1));
            arr[wid - 1]++;
            fillVisit(r, c, wid, false);
        }
    }

    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 100; i++)
    {
        int a; cin >> a;
        board[i / 10][i % 10] = a;
        if(a == 1)
            nodes.push_back({i / 10, i % 10});
    }

    int ans = DFS(0, 0);
    if(ans == 1e9) ans = -1;

    cout << ans;
    return 0;
}