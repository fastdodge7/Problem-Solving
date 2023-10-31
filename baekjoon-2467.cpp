#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
int ans[2] = { (int)1e9, (int)1e9 };

int findNearZeroSum(int target, int start, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target + arr[mid] > 0)
            right = mid - 1;
        else if (target + arr[mid] < 0)
            left = mid + 1;
        else
            return arr[mid];
    }
    if (right <= start) return arr[left];
    if (left >= N) return arr[right];
    int ret = (abs(target + arr[left]) < abs(target + arr[right])) ? arr[left] : arr[right];
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N - 1; i++)
    {
        int left = arr[i];
        int right = findNearZeroSum(left, i, i + 1, N - 1);

        if (abs(left + right) < abs(ans[0] + ans[1]))
        {
            ans[0] = left;
            ans[1] = right;
        }
    }
    cout << ans[0] << " " << ans[1];
    
    return 0;
}