#include <iostream>
#include <queue>
#include <map>
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
Node *createMapping(Node *root, int target, map<Node *, Node *> &NodetoParent)
{
    if (root == NULL)
        return NULL;
    Node *res = NULL;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            NodetoParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            NodetoParent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}
int burnTree(Node *root, map<Node *, Node *> &NodeToParent)
{
   
    queue<Node *> q;
    map<Node *, bool> visited;

    q.push(root);
    visited[root] = true;
    int ans = 0;
   

    while (!q.empty())
    { bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = true;
                flag = 1;
            }
            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = true;
                flag = 1;
            }
            if (NodeToParent[front] && !visited[NodeToParent[front]])
            {
                q.push(NodeToParent[front]);
                visited[NodeToParent[front]] = true;
                flag = 1;
            }
        }
        if (flag == 1)
            ans++;
    }
    return ans;
}

int minTime(Node *root, int target)
{
    map<Node *, Node *> NodetoParent;
    Node *targetnode = createMapping(root, target, NodetoParent);
    int ans = burnTree(targetnode, NodetoParent);
    return ans;
}