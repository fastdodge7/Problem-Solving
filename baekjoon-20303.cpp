#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

vector<int> matrix[30001];
int candies[30001];
bool visited[30001];

vector<pair<int, int>> groupInfo;
int dp[3001];

pair<int, int> DFS(int start) {
    
    visited[start] = true;
    pair<int, int> ret = {candies[start], 1};

    for (int next : matrix[start])
    {
        if (visited[next]) continue;
        pair<int, int> temp = DFS(next);
        ret.first += temp.first;
        ret.second += temp.second;
    }

    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        cin >> candies[i];

    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i]) continue;
        groupInfo.push_back(DFS(i));
    }

    for (int j = K - 1; j >= 0; j--)
    {
        if (groupInfo[0].second <= j)
            dp[j] = groupInfo[0].first;
    }

    for (int i = 1; i < groupInfo.size(); i++)
    {
        int childrenCnt = groupInfo[i].second;
        int candyCnt = groupInfo[i].first;

        for (int j = K - 1; j >= 0; j--)
        {
            if (j - childrenCnt < 0) break;
            dp[j] = max(dp[j - childrenCnt] + candyCnt, dp[j]);
        }
    }

    cout << dp[K - 1];
    return 0;
}