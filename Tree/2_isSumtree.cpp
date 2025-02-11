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

pair<bool, int> isSumtreefast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left== NULL &&  root->right ==NULL){
         pair<bool, int> p = make_pair(true, root->data);
        return p; 
    }

    pair<bool, int> left = isSumtreefast(root->left);
    pair<bool, int> right = isSumtreefast(root->right);
    bool isleft = left.first;
    bool isright = right.first;

    bool equal = root->data == left.second + right.second;
    pair<bool, int> ans;
    ans.second = left.second + right.second + root->data;
    if (isleft && isright && equal)
    {
        ans.first = true;
    }
    else
        ans.first = false;

    return ans;
}
bool isSumTree(node*root){
    return isSumtreefast(root).first;
}