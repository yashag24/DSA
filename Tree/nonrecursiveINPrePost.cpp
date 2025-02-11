#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Non-recursive Inorder Traversal
void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    stack<TreeNode *> s;
    TreeNode *current = root;

    while (current || !s.empty())
    {
        while (current)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }
}

// Non-recursive Preorder Traversal
void preorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *current = s.top();
        s.pop();

        cout << current->data << " ";

        if (current->right)
            s.push(current->right);

        if (current->left)
            s.push(current->left);
    }
}

// Non-recursive Postorder Traversal
void postorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    stack<TreeNode *> s;
    stack<int> out;

    s.push(root);

    while (!s.empty())
    {
        TreeNode *current = s.top();
        s.pop();

        out.push(current->data);

        if (current->left)
            s.push(current->left);

        if (current->right)
            s.push(current->right);
    }

    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}