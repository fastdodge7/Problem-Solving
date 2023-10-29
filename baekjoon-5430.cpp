#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector<string> split(string str)
{
    vector<string> ret;
    if (str.empty()) return ret;

    string number = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',')
        {
            ret.push_back(number);
            number = "";
            continue;
        }
        number += str[i];
    }
    ret.push_back(number);

    return ret;
}

void printArr(int left, int right, vector<string>& arr, bool reverseFlag)
{
    if (left > right)
    {
        cout << "error\n";
        return;
    }

    string msg = "[";
    if (reverseFlag)
    {
        for (int i = right - 1; i > left; i--)
            msg += (arr[i] + ",");
        if(left < right)
            msg += arr[left];
    }
    else
    {
        for (int i = left; i < right - 1; i++)
            msg += (arr[i] + ",");
        if (left < right)
            msg += arr[right - 1];
    }
    msg += "]\n";
    cout << msg;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        string command; cin >> command;
        int N; cin >> N;
        string str; cin >> str; 
        str = str.substr(1, str.size() - 2);

        vector<string> arr = split(str);
        int left = 0; int right = arr.size();

        bool reverseFlag = false;
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'R')
                reverseFlag ^= true;

            else if(command[i] == 'D')
            {
                if (reverseFlag) right--;
                else left++;
            }
        }
        printArr(left, right, arr, reverseFlag);
    }
    return 0;
}