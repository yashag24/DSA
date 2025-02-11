#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    // h.d. data
    map<int, int> bottomnode;
    // node address , hd
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        Node *frontNode = temp.first;

        int hd = temp.second;

            bottomnode[hd] = frontNode->data;
        

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }
    for (auto i : bottomnode)
    {
        ans.push_back(i.second);
    }
    return ans;
}