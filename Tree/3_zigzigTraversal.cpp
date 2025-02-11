#include <iostream>
#include <queue>
#include <vector>
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
vector<int> zigzagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;
    queue<node *> q;

    q.push(root);

    bool leftToright = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // level process

        for (int i = 0; i < size; i++)
        {
            node *frontnode = q.front();
            q.pop();

            int index = leftToright ? i : size - 1 - i;
            ans[index] = frontnode->data;

            if (frontnode->left)
            { 
                q.push(frontnode->left);
            }
            if (frontnode->right)
            {
                q.push(frontnode->right);
            }
        }
        leftToright = !leftToright;

        for (auto i : ans)
            result.push_back(i);
    }
    return result;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);

    vector<int> v = zigzagTraversal(root);
    for (int i : v)
    {
        cout << i << " ";
    }
}