#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
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
int height(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}
int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    ;
    return max(op1, max(op2, op3));
}

vector<int> zigzag(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);

    bool leftoright = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();
            int index = leftoright ? i : size - i - 1;

            ans[index] = front->data;
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        leftoright = !leftoright;

        for (int i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}
vector<int> topview(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    map<int, int> top;

    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *topnode = temp.first;
        int hd = temp.second;
        if (top.find(hd) == top.end())
        {
            top[hd] = topnode->data;
        }

        if (topnode->left)
            q.push(make_pair(root->left, hd - 1));
        if (topnode->right)
            q.push(make_pair(root->right, hd + 1));
    }
    for (auto i : top)
    {
        result.push_back(i.second);
    }
    return result;
}

void giveleft(vector<int> &ans, node *root, int level)
{
    if (root == nullptr)
        return;
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    giveleft(ans, root->left, level + 1);
    giveleft(ans, root->right, level + 1);
}
vector<int> leftview(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;
    giveleft(result, root, 0);
    return result;
}

void leaftoroot(node *root, int sum, int &maxsum, int currheight, int &maxheight)
{
    if (root == NULL)
        return;
    sum += root->data;
    if (currheight > maxheight)
    {
        maxsum = sum;
        maxheight = currheight;
    }
    else if (currheight == maxheight && sum > maxsum)
    {
        maxsum = sum;
    }
    leaftoroot(root->left, sum, maxsum, currheight + 1, maxheight);
    leaftoroot(root->right, sum, maxsum, currheight + 1, maxheight);
}

int longestbloodlineSum(node *root)
{
    if (root == NULL)
        return 0;
    if (root->right == nullptr && root->left == nullptr)
        return root->data;
    int maxheight = 0, currheight = 0, sum = 0, maxsum = 0;
}

// LCA

node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return nullptr;
    if (root->data == n1 || root->data == n2)
        return root;
    node *leftans = lca(root->left, n1, n2);
    node *rightans = lca(root->right, n1, n2);

    if (leftans && rightans)
        return root;
    else if (!leftans && rightans)
        return rightans;
    else if (!rightans && leftans)
        return leftans;
    else
        return nullptr;
}

// kthnancestor
node *solve(node *root, int &k, int n)
{
    if (root == NULL || root->data == n)
        return root;
    node *leftans = solve(root->left, k, n);
    node *rightans = solve(root->right, k, n);

    if (leftans && !rightans)
    {
        k--;
        if (k == 0)
            return root;
        return leftans;
    }
    if (
        !leftans && rightans)
    {
        k--;
        if (k == 0)
            return root;
        return rightans;
    }
    return NULL;
}

int kthancestor(node *root, int k, int n)
{
    int ans;
    if (root == NULL || root->data == n)
        return -1;
}
