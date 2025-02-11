#include <iostream>
#include <climits>
#include <vector>
using namespace std;
class node
{
public:
    int data;
   node *left;
    node *right;
    node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
};
node *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
        return NULL;
    if (preorder[i] < mini || preorder[i] > maxi)
        return NULL;
    node *root = new node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}
node *preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}
