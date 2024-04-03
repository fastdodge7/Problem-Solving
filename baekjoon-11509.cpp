#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct balloon{
    int height;
    int pos;

    bool operator<(const balloon& other) const {
        if(height == other.height)
            return pos < other.pos;
        return height > other.height; 
    }
}balloon;

int N;
vector<balloon> arr;
queue<balloon> Q;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a; cin >> a;
        arr.push_back({a, i});
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        while(!Q.empty() && !(Q.front().height == arr[i].height || Q.front().height == arr[i].height + 1))
            Q.pop();

        if(Q.empty() || arr[i].height == Q.front().height)
        {
            Q.push(arr[i]);
            ans++;
            continue;
        }

        if(Q.front().pos > arr[i].pos)
        {
            Q.push(arr[i]);
            ans++;
            continue;
        }

        Q.pop();
        Q.push(arr[i]);
    }
    cout << ans;
    return 0;
}