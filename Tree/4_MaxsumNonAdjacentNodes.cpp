#include <iostream>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data;
    Node(int d)
    {
        left = right = NULL;
        data = d;
    }
};

pair<int, int> solve(Node *root)
{
    pair<int, int> p = make_pair(0, 0);
    if (root == NULL)
        return p;

    pair<int, int> leftans = solve(root->left);
    pair<int, int> rightans = solve(root->right);
    pair<int, int> ans;
    ans.first = root->data + leftans.second + rightans.second;
    ans.second = max(leftans.first, leftans.second) + max(rightans.first, rightans.second);

    return ans;
}

int getsum(Node *root)
{

    ///  including node,excluding node
    pair<int,                int> ans = solve(root);

    return max(ans.first, ans.second);
}