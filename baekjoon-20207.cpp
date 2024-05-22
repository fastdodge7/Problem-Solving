#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N;
int arr[367];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s, e; cin >> s >> e;
        arr[s] += 1;
        arr[e + 1] -= 1;
    }

    for(int i = 1; i <= 366; i++)
        arr[i] += arr[i - 1];

    int ans = 0;

    int width = 0;
    int height = 0;
    bool flag = false;
    for(int i = 1; i <= 366; i++)
    {   
        if(flag && arr[i] == 0)
        {
            ans += width * height;
            width = height = 0;
            flag = false;
            continue;
        }

        if(!flag && arr[i] > 0)
            flag = true;

        if(arr[i] > 0)
        {
            width += 1;
            height = max(height, arr[i]);
        }
    }
    
    cout << ans << '\n';
    return 0;
}