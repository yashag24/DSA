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
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    // lvl data
    map<int, int> Leftview;
    //  node address , lvl
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *leftnode = temp.first;
        int level = temp.second;
        if (Leftview.find(level) == Leftview.end())
        {
            Leftview[level] = leftnode->data;
        }

        if (leftnode->left)
            q.push(make_pair(leftnode->left, level + 1));
        if (leftnode->right)
            q.push(make_pair(leftnode->right, level + 1));
    }
    for (auto i : Leftview)
    {
        ans.push_back(i.second);
    }
    return ans;
}