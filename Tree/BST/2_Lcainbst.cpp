#include <iostream>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
    if (root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);

    if (root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);

    return root;
}
/// iterative approach

Node *Lca(Node *root, Node *P, Node *Q)
{
    while (root != NULL)
    {
        if (root->data < P->data && root->data < Q->data)
            root = root->right;

        else if (root->data > P->data && root->data > Q->data)
            root = root->left;
        else
            return root;
    }
}