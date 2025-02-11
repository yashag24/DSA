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
// int max(int h1, int h2)
// {
//     return h1 > h2 ? h1 : h2;
// }
int heightofTree(node *root)
{
    if (root == NULL)
        return 0;

    int h1 = heightofTree(root->left);

    int h2 = heightofTree(root->right);

    int h = 1 + max(h1, h2);

    return h;
}
int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = heightofTree(root->left) + heightofTree(root->right) + 1;

    return max(op1, max(op2, op3));
}

// OPTIMISED METHOD
pair<int, int> diameterfast(node *root)
{

    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    //second me height h
    

    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first =max(op1,max(op3,op2));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int diameteroptimised(node *root)
{

return diameterfast(root).first;

}
