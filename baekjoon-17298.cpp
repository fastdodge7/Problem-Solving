#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> stck;
int arr[1000000];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = N - 1; i >= 0; i--)
    {
        int temp = arr[i];
        while (!stck.empty())
        {
            if (arr[i] < stck.back())
            {
                int t = stck.back();
                stck.push_back(arr[i]);
                arr[i] = t;
                break;
            }
            stck.pop_back();
        }
        if (temp == arr[i])
        {
            stck.push_back(arr[i]);
            arr[i] = -1;
        }
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
    return 0;
}