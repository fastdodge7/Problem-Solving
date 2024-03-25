#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    long long A = 0;
    long long B = 0;
    for(int i = 0; i < N; i++)
    {
        int temp; cin >> temp;
        A += temp;
        B += (temp / 2);
    }
    
    if(A % 3 == 0)
    {
        if(A / 3 <= B)
        {
            cout << "YES";
            return 0;
        } 
    }
    
    cout << "NO";
    return 0;
}