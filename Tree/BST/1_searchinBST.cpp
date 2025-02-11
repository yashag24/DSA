#include <iostream>
#include <queue>
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

bool searchinBST(Node *root, int ele)
{

    if (root == NULL)
        return false;
    if (root->data == ele)
        return true;

    if (root->data < ele)
    {
        return searchinBST(root->right, ele);
    }
    else
    {
        return searchinBST(root->left, ele);
    }
}
// iterative method
bool searchInBST(Node *root, int ele)
{

    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == ele)
            return true;

        if (root->data < ele)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return false;
}
