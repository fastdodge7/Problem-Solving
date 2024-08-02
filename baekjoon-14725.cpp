#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;


typedef struct Node{
    string strData;
    vector<Node *> children;
}Node;


typedef Node* Trie;


int N;
int idx = 1;
Node arr[15001];
Trie root = &arr[0];

bool DFS(Trie cur, const vector<string>& inputStr, int depth)
{
    if(depth == inputStr.size()) return true;
    for(Trie next : cur->children)
    {
        if(next->strData == inputStr[depth])
            return DFS(next, inputStr, depth + 1);
    }

    for(int i = depth; i < inputStr.size(); i++)
    {
        //Trie newNode = &arr[idx++];
        Trie newNode = new Node({"", {}});
        newNode->strData = inputStr[depth++];
        cur->children.push_back(newNode);
        cur = newNode;
    }
    return false;
}

void printAns(Trie cur, int depth)
{
    sort(cur->children.begin(), cur->children.end(), [](Trie a, Trie b){
        return a->strData < b->strData;
    });
    if(cur->strData != ".")
    {
        for(int i = 1; i < depth; i++)
        {
            cout << "--";
        }
        cout << cur->strData << '\n';
    }

    for(Trie child : cur->children)
    {
        printAns(child, depth + 1);
    }
    delete cur;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    root = new Node({".", {}});
    for(int i = 0; i < N; i++)
    {
        int k; cin >> k;
        vector<string> vec = {};
        for(int j = 0; j < k; j++)
        {
            string str; cin >> str;
            vec.push_back(str);
        }

        DFS(root, vec, 0);

    }
    printAns(root, 0);
    return 0;
}