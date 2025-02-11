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
Node *buildtree(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->data < data)
    {
        root->right = buildtree(root->right, data);
    }
    else
    {
        root->left = buildtree(root->left, data);
    }
    return root;
}
void takedata(Node *&root)
{
    int data;
    cout << "Enter data to create BST:-";
    cin >> data;
    while (data != -1)
    {
        root = buildtree(root, data);
        cin >> data;
    }
}
void lot(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}
int main()
{
    Node *root = NULL;
    takedata(root);
    lot(root);
}