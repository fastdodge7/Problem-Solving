#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[1000000];
priority_queue<pair<long long, long long>> maxQ;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> minQ;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long T; cin >> T;
    for(long long test_case = 1; test_case <= T; test_case++)
    {
        long long cnt = 0;
        long long N; cin >> N;
        for(long long i = 0; i < N; i++)
        {
            char c; cin >> c;
            if(c == 'I')
            {
                long long num; cin >> num;
                maxQ.push({num, cnt});
                minQ.push({num, cnt++});
            }
            else
            {
                long long flag; cin >> flag;
                if(flag == 1)
                {
                    while(!maxQ.empty() && check[maxQ.top().second])
                        maxQ.pop();
                    if(!maxQ.empty())
                    {
                        check[maxQ.top().second] = true;
                        maxQ.pop();
                    }
                }
                else
                {
                    while(!minQ.empty() && check[minQ.top().second])
                        minQ.pop();
                    if(!minQ.empty())
                    {
                        check[minQ.top().second] = true;
                        minQ.pop();
                    }
                }
            }
        }
        while(!minQ.empty() && check[minQ.top().second])
            minQ.pop();
        while(!maxQ.empty() && check[maxQ.top().second])
            maxQ.pop();


        fill(check, check + N, false);
        if(maxQ.empty())
            cout << "EMPTY\n";
        else
            cout << maxQ.top().first << ' ' << minQ.top().first << '\n';    
        
    }
    return 0;
}