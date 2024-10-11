#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

int N;
vector<int> matrix[300001];
int cnt[300001];
long long dist[300001];

long long findDistSum(int parent, int cur)
{
    long long ret = 0;
    for(int next : matrix[cur])
    {
        if(next != parent)
            ret += (findDistSum(cur, next) + cnt[next]);
    }  
    return dist[cur] = ret;
}

int DFS(int parent, int cur)
{
    int count = 1;
    for(int next : matrix[cur])
    {
        if(next != parent)
            count += DFS(cur, next);
    }   

    return cnt[cur] = count;
}

long long solve(int parent, int root)
{
    long long ans = 0;
    long long dstSum = 0;
    long long nodeCnt = 0;

    for(int next : matrix[root])
    {
        if(next != parent)
        {
            ans += (solve(root, next) + (long long)cnt[next] * (cnt[next] - 1) / 2);
            ans += (dist[next] + cnt[next]);
            ans += (cnt[next] * (dstSum + nodeCnt) + (dist[next] + cnt[next]) * nodeCnt);

            nodeCnt += cnt[next];
            dstSum += dist[next];
        }  
    }
    return ans;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }

    DFS(0, 1);
    findDistSum(0, 1);
    
    cout << solve(0, 1);
    return 0;
}