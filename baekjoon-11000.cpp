#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int curTime = 0;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pair<int, int> arr[200000];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
    }

    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
        swap(arr[i].first, arr[i].second);

    pq.push(arr[0]);

    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        while (pq.top().first <= arr[i].second)
            pq.pop();
        pq.push(arr[i]);
        ans = max(ans, (int)pq.size());
    }

    cout << ans;

    return 0;
}