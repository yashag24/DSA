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

void buildtree(node *&root)
{
    queue<node *> q;

    cout << "Enter the data for root:-";
    int d;
    cin >> d;
    root = new node(d);
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << "Enter the data for left node of " << temp->data << ":-";
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the data for right node of " << temp->data << ":-";
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

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
        {
            cout << temp->data << " ";
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
void butree(node *&root);
int main()
{
    node *root = NULL;
    // buildtree(root);
    butree(root);
    levelordertraversal(root);
}
void butree(node *&root)
{
    queue<node *> q;
    cout << "Enter data:-";
    int n;
    cin >> n;
    if (n == -1)
    {
        return;
    }
    root = new node(n);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
       

        cout << "Enter data for left node of " << temp->data << ":-";
        int ldata;
        cin >> ldata;
        if (ldata != -1)
        {
            temp->left = new node(ldata);
            q.push(temp->left);
        }

        cout << "Enter data for right node of " << temp->data << ":-";
        int rdata;
        cin >> rdata;
        if (rdata != -1)
        {
            temp->right = new node(rdata);
            q.push(temp->right);
        }
    }
}