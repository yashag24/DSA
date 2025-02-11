#include <iostream>
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
void traverseLeft(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(node *root, vector<int> &ans)
{

    if (root == NULL)
        return;
    if (root->right == NULL && root->left == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node*root,vector<int>&ans){
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

   
    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
 ans.push_back(root->data);

}
vector<int> boundaryTraversal(node *root)
{ vector<int>ans;
if(root==NULL)
return ans;
ans.push_back(root->data);
    //leftpart traverse
    traverseLeft(root->left,ans);

    //leaf traversal
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);

    // right traversal
    traverseRight(root->right,ans);

    return ans;

    
}