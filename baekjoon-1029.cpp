#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[15][15];
int dp[1024 * 32][15];

int DFS(int cur, int price, int bits)
{
    bits = (bits | (1 << cur));

    if (dp[bits][cur]) 
        return dp[bits][cur];

    for (int next = 1; next < N; next++)
    {
        if ((bits & (1 << next)) == 0 && arr[cur][next] >= price) 
            dp[bits][cur] = max(dp[bits][cur], DFS(next, arr[cur][next], bits) + 1);
    }

    return dp[bits][cur];
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < str.size(); j++)
            arr[i][j] = str[j] - '0';
    }
    
    cout << (DFS(0, 0, 0) + 1);
    
    return 0;
}