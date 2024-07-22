#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, X, Y;
int income[500001];
vector<int> matrix[500001];
int dist[500001];

bool BFS(const vector<int>& initList)
{
    fill(dist, dist + N + 1, -1);
    queue<int> Q;
    for(int i : initList)
    {
        Q.push(i);
        dist[i] = 0;
    }

    int rest = N - initList.size();

    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for(int next : matrix[cur])
        {
            if(dist[next] != -1) continue;
            rest--;
            Q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }

    for(int i = 1; i <= N; i++)
    {
        if(dist[i] == -1 && income[i] > 0)
            return false;
    }

    return true;
}


int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X >> Y;
    for(int i = 1; i <= N; i++)
        cin >> income[i];
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    vector<int> initList = {};
    for(int i = 0; i < Y; i++)
    {
        int a; cin >> a;
        initList.push_back(a);
    }

    if(!BFS(initList))
    {
        cout << -1;
        return 0;
    }

    vector<long long> ans = {};
    for(int i = 1; i <= N; i++)
        ans.push_back((long long)income[i] * dist[i]);
    
    sort(ans.begin(), ans.end(), greater<long long>());

    long long summation = 0;
    for(int i = 0; i < X; i++)
        summation += ans[i];

    cout << summation;
    return 0;
}