#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N, S, M;
int arr[50];
unordered_set<int> dp[50];

int ans = -1;

int DFS(int cur, int vol)
{
    if(cur == N)
    {
        ans = max(ans, vol);
        return 1;
    }

    int ret = -1;
    if(vol + arr[cur] <= M && dp[cur].find(vol + arr[cur]) == dp[cur].end())
    {
        dp[cur].insert(vol + arr[cur]);
        ret = DFS(cur + 1, vol + arr[cur]);
    }
    
    if(vol - arr[cur] >= 0 && dp[cur].find(vol - arr[cur]) == dp[cur].end())
    {
        dp[cur].insert(vol - arr[cur]);
        ret = DFS(cur + 1, vol - arr[cur]);
    }
    
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    DFS(0, S);
    cout << ans << '\n';
    return 0;
}