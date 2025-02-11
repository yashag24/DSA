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
bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    return false;

        bool isequal = false;
    if (root1->data == root2->data)
    {

        bool left = isIdentical(root1->left, root2->left);
        bool right = isIdentical(root1->right, root2->right);

        if (left && right)
            isequal = true;
    }

    return isequal;
}