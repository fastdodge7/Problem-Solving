#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int curTime = 0;
priority_queue<int, vector<int>, greater<int>> pq;
int times[10000];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> times[i];

    sort(times, times + N, greater<int>());

    for (int i = 0; i < N; i++)
    {
        if (pq.size() < M)
            pq.push(curTime + times[i]);
        else
        {
            curTime = pq.top(); pq.pop();
            pq.push(curTime + times[i]);
        }
    }

    while (pq.size() != 1)
        pq.pop();

    cout << pq.top();

    return 0;
}