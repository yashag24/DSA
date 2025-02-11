#include <iostream>
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

    cout << "Enter data for left node of "<<n<<"." << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for right node of "<<n<<"."  << endl;
    root->right = buildtree(root->right);
    return root;
}
void inordertraversal(node*root){
    if(root == NULL)
    return;

    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}
void preordertraversal(node * root){
    if(root == NULL)
    return;
cout<<root->data<<" ";
    preordertraversal(root->left);
    
    preordertraversal(root->right);
}
void postordertraversal(node * root){
    if(root == NULL)
    return;

    postordertraversal(root->left);
    
    postordertraversal(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    inordertraversal(root);
    cout<<endl;
    preordertraversal(root);
     cout<<endl;
    postordertraversal(root);
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 