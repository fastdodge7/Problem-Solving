#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int ans = 0;
int arr[1000001]; // arr[i] 높이 i를 지나가는 화살의 수

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        int a; cin >> a;
        if(arr[a] == 0)
        {
            ans++;
            arr[a - 1]++;
        }
        else
        {
            arr[a]--;
            arr[a - 1]++;
        }
    }

    cout << ans;
    return 0;
}