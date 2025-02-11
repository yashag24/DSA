#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};



void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
       
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        { cout << temp->data << " ";
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
}
node *buildtree(node *root)
{

    cout << "Enter the data:-";
    int n;
    cin >> n;
    root = new node(n);

    // Assuming that if data is -1,then user wants to end that tree node
    if (n == -1)
    {
        return NULL;
    }

    cout << "Enter data for left node of " << n << "." << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for right node of " << n << "." << endl;
    root->right = buildtree(root->right);
    return root;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelordertraversal(root);
}