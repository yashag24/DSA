
#include <iostream>
#include <vector>
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
void getarray(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    getarray(root->left, v);
    v.push_back(root->data);
    getarray(root->right, v);
}

int kthSmallest(Node *root, int k)
{
    if (root == NULL)
        return -1;
    vector<int> v;
    getarray(root, v);
    int size = v.size();
    if (k > size)
        return -1;
    int i = 0;
    for (i = 0; i < k; i++)
    {
    }
    return v[i - 1];
}