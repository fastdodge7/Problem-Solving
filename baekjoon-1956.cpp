#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int matrix[401][401];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&matrix[0][0], &matrix[400][400] + 1, 1e9);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        matrix[a][b] = c;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
    }
    
    int ans = 1e9;
    for (int j = 1; j <= N; j++)
        ans = min(ans, matrix[j][j]);

    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}