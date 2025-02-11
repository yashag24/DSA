#include <iostream>
using namespace std;
class node
{
public:
    node *left;
    int data;
    node *right;
    node(int d)
    {

        left = NULL;
        right = NULL;
        data = d;
    }
};
int heightofTree(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    int h1 = heightofTree(root->left);

    int h2 = heightofTree(root->right);

    int h = 1 + max(h1, h2);

    return h;
}
bool isbalanced(node *root)
{

    if (root == NULL)
        return true;

    bool left = isbalanced(root->left);
    bool right = isbalanced(root->right);
    bool diff = abs(heightofTree(root->left) - heightofTree(root->right)) <= 1;
    if (left && right && diff)
        return 1;
    else
        return false;
}
// time complexity above is o(n2)
pair<bool, int> isBalanced(node *root)
{

    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> l = isBalanced(root->left);
    pair<bool, int> r = isBalanced(root->right);
    bool left = l.first;
    bool right = r.first;

    bool diff = abs(l.second - r.second) <= 1;
    pair<bool, int> ans;
    if (left && right && diff)
    {
        ans = make_pair(1, max(l.second, r.second) + 1);
        return ans;
    }
    else
    {
        ans = make_pair(false, max(l.second, r.second) + 1);
        return ans;
    }
}
bool isBalancedfast(node *root)
{
    pair<bool, int> ans = isBalanced(root);
    return ans.first;
}
