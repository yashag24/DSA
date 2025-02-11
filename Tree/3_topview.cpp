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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    // h.d. data
    map<int, int> topnode;
    // node address , hd
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        Node *frontNode = temp.first;

        int hd = temp.second;

        if (topnode.find(hd) == topnode.end())
        {
            topnode[hd] = frontNode->data;
        }

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }
    for (auto i : topnode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// practice
vector<int> tview(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    // create map containing horizontal distance and data
    map<int, int> topnode;

    // make queue containg node address and hd
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontnode = temp.first;

        int hd = temp.second;

        if (topnode.find(hd) == topnode.end())
        {
            topnode[hd] = frontnode->data;
        }

        if (frontnode->left)
            q.push(make_pair(frontnode->left, hd - 1));
        if (frontnode->right)
            q.push(make_pair(frontnode->right, hd + 1));
    }

    for(auto i:topnode){
        ans.push_back(i.second);

    }
    return ans;
}