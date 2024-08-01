#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

typedef struct Node{
    Node(char c, vector<Node *> vec) : character(c), children(vec) {

    }

    char character;
    vector<Node *> children;
}Node;

typedef Node *Trie;

int T, N;
Trie root = nullptr;

int DFS(Trie node, const string& str, int idx)
{
    if(idx == str.size()) return 1;

    for(Node *child : node->children)
    {
        if(child->character == str[idx])
            return DFS(child, str, idx + 1);
    }

    int ret = (node->character != '.' && node->children.empty()) ? 1 : -1;
    int iter = idx;
    while(iter < str.size())
    {
        Node *newNode = new Node(str[iter], {});
        node->children.push_back(newNode);

        iter++;
        node = newNode;
    }

    return ret;
}

void cleanUp(Trie root)
{
    for(Trie child : root->children)
    {
        cleanUp(child);
    }
    delete root;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++)
    {
        cin >> N;
        root = new Node('.', {});

        bool isConsistent = true;
        for(int i = 0; i < N; i++)
        {
            string str; cin >> str;
            if(DFS(root, str, 0) == 1)
            {
                isConsistent = false;
            }
        }

        cout << (isConsistent ? "YES\n" : "NO\n");
        cleanUp(root);
    }
    return 0;
}