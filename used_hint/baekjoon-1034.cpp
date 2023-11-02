#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, M, K;
unordered_map<string, int> cnt;

string arr[50];
int zeroCnt[50];



int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str; cin >> str;
        arr[i] = str;
    }
    cin >> K;

    for (int i = 0; i < N; i++) for(int j = 0; j < M; j++)
    {
        if (arr[i][j] == '0')
            zeroCnt[i]++;
    }

    for (int i = 0; i < N; i++) 
    {
        if (zeroCnt[i] <= K && (zeroCnt[i] + 1000 - K) % 2 == 1) continue;
        if (cnt.find(arr[i]) == cnt.end())
            cnt[arr[i]] = 1;
        else
            cnt[arr[i]] += 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        string cur = arr[i];
        int zCnt = zeroCnt[i];
        if (zCnt <= K && zCnt % 2 == K % 2) {
            ans = max(ans, cnt[cur]);
        }
    }

    
    cout << ans;
    
    return 0;
}