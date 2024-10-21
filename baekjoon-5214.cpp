#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

int N, K, M;
bool visited[100001];
bool lineVisited[1000];
vector<int> matrix[100001];
vector<int> arr[1000];

int BFS()
{
    queue<pair<int, int>> Q; Q.push({1, 0});
    visited[1] = true;
    while(!Q.empty())
    {
        auto [cur, distance] = Q.front(); Q.pop();

        for(int line : matrix[cur])
        {
            if(lineVisited[line]) continue;
            for(int next : arr[line])
            {
                if(visited[next]) continue;
                if(next == N) return distance + 1 + 1;
                Q.push({next, distance + 1});
                visited[next] = true;
            }
            lineVisited[line] = true;
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> M;
    for(int i = 0; i < M; i++) for(int j = 0; j < K; j++)
    {
        int a; cin >> a;
        arr[i].push_back(a);
        matrix[a].push_back(i);
    }

    cout << BFS();
    return 0;
}