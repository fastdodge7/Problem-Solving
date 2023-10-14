#include <iostream>
#include <vector>


using namespace std;

int N;
vector<int> stck;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int a; cin >> a;
        while (!stck.empty())
        {
            if (stck.back() <= a)
                stck.pop_back();
            else
                break;
        }
        ans += stck.size();
        stck.push_back(a);
    }

    cout << ans;

    return 0;
}