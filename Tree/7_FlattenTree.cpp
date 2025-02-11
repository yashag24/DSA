// inorder traveral without recursiom
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
Node* flatTree(Node*root){
    Node*curr=root;
    if(root==NULL)
    return curr;

}