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
int max(int h1, int h2)
{
    return h1 > h2 ? h1 : h2;
}
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

node *buildtree(node *root)
{
    cout << "Enter the data:-";
    int d;
    cin >> d;
    if (d == -1)
        return NULL;

    root = new node(d);

    cout << "Enter data of left node of " << root->data << ".\n";
    root->left = buildtree(root->left);
    cout << "Enter data of right node of " << root->data << ".\n";
    root->right = buildtree(root->right);

    return root;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    cout << heightofTree(root);
}