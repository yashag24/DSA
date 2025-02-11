#include <iostream>
using namespace std;
#include <queue>
#include <map>

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int d)
    {
        left = right = NULL;
        data = d;
    }
};
vector<int> VerticalTraversal(Node *root)
{

    vector<int> ans;

    // hori. dist.    LVL   NODES
    map<int, map<int, vector<int>>> nodes;

    //      node address , HD , LVL
    queue<pair<Node *, pair<int, int>>> q;

    if (root == NULL)
        return ans;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontnode = temp.first;

        int hd = temp.second.first;

        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontnode->data);

        if (frontnode->left)
            q.push(make_pair(frontnode->left, make_pair(hd - 1, lvl + 1)));
        if (frontnode->right)
            q.push(make_pair(frontnode->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
    }

    return ans;
}

/// by chatgpt optimized

vector<int> verticalOrder(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }

    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        Node *frontnode = temp.first;
        int hd = temp.second;
        int lvl = nodes[hd].size();

        nodes[hd][lvl].push_back(frontnode->data);

        if (frontnode->left)
        {
            q.push({frontnode->left, hd - 1});
        }
        if (frontnode->right)
        {
            q.push({frontnode->right, hd + 1});
        }
    }

    for (const auto &hdNodes : nodes)
    {
        for (const auto &lvlNodes : hdNodes.second)
        {
            for (const int &data : lvlNodes.second)
            {
                ans.push_back(data);
            }
        }
    }

    return ans;
}