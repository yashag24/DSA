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
Node *deletenode(Node *root, int data)
{
    if (root == NULL)
        return root;
    if (root->data == data)
    {
        // o child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            Node *predecessor = root->left;

            while (predecessor->right != NULL)
                predecessor = predecessor->right;

            root->data = predecessor->data;

            root->left = deletenode(root->left, predecessor->data);
        }
    }
    else if (root->data < data)
    {
        root->right = deletenode(root->right, data);
    }
    else
    {
        root->left = deletenode(root->left, data);
    }
    return root;
}