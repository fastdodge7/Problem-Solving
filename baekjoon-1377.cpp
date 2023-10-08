#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Node {
    int num;
    int index;
    int sortedIndex;

    bool operator<(const Node& other) const {
        if (num == other.num)
            return index < other.index;
        return num < other.num;
    }
};

int N;
Node sorted[500001];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int num;  cin >> num;
        sorted[i] = { num, i, -1 };
    }

    sort(sorted + 1, sorted + N + 1);

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        sorted[i].sortedIndex = i;
        if (sorted[i].sortedIndex < sorted[i].index)
        {
            ans = max(ans, sorted[i].index - sorted[i].sortedIndex);
        }
    }

    cout << ans + 1<< '\n';

    return 0;
}