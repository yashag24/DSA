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
vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    // lvl data
    map<int, int> Rightview;
    //  node address , lvl
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *rightnode = temp.first;
        int level = temp.second;
        
            Rightview[level] = rightnode->data;
        

        if (rightnode->left)
            q.push(make_pair(rightnode->left, level + 1));
        if (rightnode->right)
            q.push(make_pair(rightnode->right, level + 1));
    }
    for (auto i : Rightview)
    {
        ans.push_back(i.second);
    }
    return ans;
}