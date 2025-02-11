#include <iostream>
#include <queue>
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
node *buildtree(node *root)
{

    cout << "Enter data:-";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    cout << "Enter data for left node of " << root->data << " :-";
    root->left = buildtree(root->left);

    cout << "Enter data for right node of " << root->data << " :-";
    root->right = buildtree(root->right);

    return root;
}
int countleaf(node *root)
{
    queue<node *> q;
    q.push(root);

    int count = 0;
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();
        if (temp->right == NULL && temp->left == NULL)
        {
            count++;
        }

        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return count;
}
// using recursion
void count(node *root, int &c)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        c++;
    }

    count(root->left, c);
    count(root->right, c);
}
int countleafrecursion(node*root){
int c=0;
count(root,c);
return c;
}
int main()
{

    node *root = NULL;
    root = buildtree(root);

    cout << countleafrecursion(root);
}
