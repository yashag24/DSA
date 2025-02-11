#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *solve(Node *root, int &k, int n)
{
    if (root == NULL)
        return NULL;
    if (root->data == n)
        return root;
    Node *leftans = solve(root->left, k, n);
    Node *rightans = solve(root->right, k, n);

    if (leftans != NULL && rightans == NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return leftans;
    }

    if (leftans == NULL && rightans != NULL)
    {
         k--;
        if (k == 0)
        {
            return root;
        }
        return rightans;
    }
return NULL;
}

int kthancestor(Node *root, int k, int n)
{

    vector<Node *> path;

    Node *ans = solve(root, k, n);
    if(ans==NULL || ans->data==n)
    return -1;
    
    return ans->data;
}