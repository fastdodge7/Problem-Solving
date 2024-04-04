#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

int N;
vector<pair<int, int>> arr;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        arr.push_back({b, a});
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    int lastTimeStamp = arr[0].first;
    for(int i = 0; i < N; i++)
    {
        if(lastTimeStamp > arr[i].first)
            lastTimeStamp = arr[i].first;
        lastTimeStamp = lastTimeStamp - arr[i].second;
    }

    if(lastTimeStamp < 0)
        lastTimeStamp = -1;
    cout << lastTimeStamp;
    return 0;
}