// inorder traveral without recursiom
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void morris(Node *root)
{
    if (root == NULL)
        return;

    Node *current = root;
    Node *predecessor;

    while (current != NULL)
    {

        if (!current->left)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        { /* Find the inorder predecessor of current */
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
                predecessor = predecessor->right;

            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}