#include <iostream>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void solve(Node *root, int currheight, int &maxheight, int sum, int &maxsum)
{
    if (root == NULL)
        return;
    sum += root->data;
    if (currheight > maxheight)
    {

        maxsum = sum;
        maxheight = currheight;
    }
    if (currheight == maxheight && sum > maxsum)
    {
        maxsum = sum;
    }
    solve(root->left, currheight + 1, maxheight, sum, maxsum);
    solve(root->right, currheight + 1, maxheight, sum, maxsum);
}

int Longestsum(Node *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;
    int currheight = 0;
    int maxheight = 0;

    int maxsum = 0;

    solve(root, currheight, maxheight, sum, maxsum);

    return maxsum;
}