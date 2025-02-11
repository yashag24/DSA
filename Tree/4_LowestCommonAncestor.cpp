#include <iostream>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n2 || root->data == n1)
        return root;
    Node *leftans = lca(root->left, n1, n2);

    Node *rightans = lca(root->right, n1, n2);

    if (leftans != NULL && rightans != NULL)
        return root;
    else if (leftans != NULL && rightans == NULL)
        return leftans;
    else if (leftans == NULL && rightans != NULL)
        return rightans;
    else
        return NULL;
}